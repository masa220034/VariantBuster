#include "Player.h"
#include "Stage.h"
#include "Bullet.h"
#include "PlayerGauge.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hPlayer_(-1),
    JumpSound_(-1), DamegeSound_(-1),
    maxHp_(100), nowHp_(0), targetHp(0),
    isDamage(false), d_Amount(0), d_Step(0.1f),
    cooldown(0.5f), lastBulletTime(std::chrono::high_resolution_clock::now())
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    hPlayer_ = Model::Load("Player.fbx");
    assert(hPlayer_ >= IMB);

    JumpSound_ = Audio::Load("JumpSound.wav");
    DamegeSound_ = Audio::Load("DamegeSound2.wav");
    assert(JumpSound_ >= IMB);
    assert(DamegeSound_ >= IMB);

    tPlayer.position_ = PLAYER_POS;
    tPlayer.scale_ = PLAYER_SCL;
    tPlayer.rotate_ = PLAYER_ROT;

    SphereCollider* collision = new SphereCollider(BASE_POS, c_scale);
    AddCollider(collision);
}

//�X�V
void Player::Update()
{
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = currentTime - lastBulletTime;

    //�n�܂������AHP�Q�[�W�㏸
    if (!isHpmax)
    {
        nowHp_ += upHp_;
        if (nowHp_ >= maxHp_)
        {
            nowHp_ = maxHp_;
            isHpmax = true;
        }
    }

    //�_���[�W���󂯂��Ƃ���HP�Q�[�W�̌������x
    if (isDamage)
    {
        nowHp_ -= d_Step;
        if (nowHp_ <= targetHp)
        {
            nowHp_ = targetHp;
            isDamage = false;
        }
    }

    if (nowHp_ <= noHp_)
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
    }

    PlayerGauge* pPlayerGauge = (PlayerGauge*)FindObject("PlayerGauge");
    pPlayerGauge->SetHp(nowHp_, maxHp_);

    if (isHpmax)
    {
        if (Input::IsKey(DIK_LEFT))
        {
            tPlayer.position_.x -= moveSpeed;
            P_Right = false;
        }

        if (Input::IsKey(DIK_RIGHT))
        {
            tPlayer.position_.x += moveSpeed;
            P_Right = true;
        }

        if (Input::IsKeyDown(DIK_SPACE) && elapsed.count() >= cooldown)
        {
            Bullet* pBullet = Instantiate<Bullet>(GetParent());
            pBullet->SetPosition(tPlayer.position_);

            if (P_Right)
            {
                pBullet->SetDirection(RIGHT_DIR);
            }
            else
            {
                pBullet->SetDirection(LEFT_DIR);
            }

            lastBulletTime = currentTime;
        }

        //�ړ���ɑ��ꂪ���邩�ǂ��������C�L���X�g�Ŋm�F
        Stage* pStage = (Stage*)FindObject("Stage");
        int hGroundModel = pStage->GetModelHandle();

        RayCastData data;
        data.start = tPlayer.position_; //���C�̔��ˈʒu
        data.dir = RAY_DIR; //���C�̕���
        Model::RayCast(hGroundModel, &data);

        if (isJump)
        {

            tPlayer.position_.y += x;
            x -= gravity;

            if (tPlayer.position_.y <= ground_Y)
            {
                if (data.hit)
                {
                    //���ꂪ����ꍇ�A�W�����v�������̈ʒu��������
                    tPlayer.position_.y = ground_Y;
                }
                isJump = false;
            }
        }
        else
        {
            if (Input::IsKeyDown(DIK_UP))
            {
                // �W�����v�J�n
                isJump = true;
                x = v;
                Audio::Play(JumpSound_);
            }

            if (!data.hit)
            {
                //���ꂪ�Ȃ��ꍇ�A�v���C���[�̍�����������
                tPlayer.position_.y -= fallSpeed * gravity;

                if (tPlayer.position_.y <= fPosition)
                {
                    SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
                    pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
                }
            }
        }
    }
   
    transform_ = tPlayer;
}

//�`��
void Player::Draw()
{
    Model::SetTransform(hPlayer_, tPlayer);
    Model::Draw(hPlayer_);
}

//�J��
void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Enemy")
    {
        StartDamage(e_damage);
    }

    if (pTarget->GetObjectName() == "EnemyBullet")
    {
        pTarget->KillMe();
        StartDamage(eb_damage);
        Audio::Play(DamegeSound_);
    }

    if (pTarget->GetObjectName() == "EnemyBullet2")
    {
        pTarget->KillMe();
        StartDamage(sec_eb_damage);
    }

    if (pTarget->GetObjectName() == "minBullet")
    {
        pTarget->KillMe();
        StartDamage(min_b_damage);
    }

    if (pTarget->GetObjectName() == "Key")
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_GAMECLEAR);
    }
}

void Player::StartDamage(float amount)
{
    targetHp = nowHp_ - amount;
    if (targetHp < noHp_)
    {
        targetHp = noHp_;
    }
    isDamage = true;
}
