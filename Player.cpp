#include "Player.h"
#include "Stage.h"
#include "Bullet.h"
#include "PlayerGauge.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hPlayer_(-1), 
    JumpSound_(-1), DamegeSound_(-1),
    maxHp_(100), nowHp_(0)
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    Camera::SetPosition(XMFLOAT3(cmrPosX, cmrPosY, -cmrPosZ));
    Camera::SetTarget(XMFLOAT3(cmrTgtX, cmrTgtY, cmrTgtZ));

    hPlayer_ = Model::Load("Player.fbx");
    assert(hPlayer_ >= 0);

    JumpSound_ = Audio::Load("JumpSound.wav");
    DamegeSound_ = Audio::Load("DamegeSound2.wav");
    assert(JumpSound_ >= 0);
    assert(DamegeSound_ >= 0);

    tPlayer.position_ = XMFLOAT3(posX, posY, posZ);
    tPlayer.scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(collPosX, collPosY, collPosZ), collScale);
    AddCollider(collision);
}

//�X�V
void Player::Update()
{
    if (!isHpmax)
    {
        nowHp_ += upHp_;
        if (nowHp_ >= maxHp_)
        {
            nowHp_ = maxHp_;
            isHpmax = true;
        }
    }

    if (nowHp_ <= noHp_)
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
    }

    PlayerGauge* pPlayerGauge = (PlayerGauge*)FindObject("PlayerGauge");
    pPlayerGauge->SetHp(nowHp_, maxHp_);

    if (Input::IsKey(DIK_LEFT))
    { 
        tPlayer.position_.x -= moveSpeed;
    }

    if (Input::IsKey(DIK_RIGHT))
    {  
        tPlayer.position_.x += moveSpeed;
    }

    if (Input::IsKeyDown(DIK_A))
    {
        Bullet* pBullet = Instantiate<Bullet>(GetParent());
        pBullet->SetPosition(tPlayer.position_);
    }

    //�ړ���ɑ��ꂪ���邩�ǂ��������C�L���X�g�Ŋm�F
    Stage* pStage = (Stage*)FindObject("Stage");
    int hGroundModel = pStage->GetModelHandle();

    RayCastData data;
    data.start = tPlayer.position_;   //���C�̔��ˈʒu
    data.dir = XMFLOAT3(R_dirX, R_dirY, R_dirZ);       //���C�̕���
    Model::RayCast(hGroundModel, &data); //���C�𔭎�

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
        nowHp_ -= e_damage;
    }

    if (pTarget->GetObjectName() == "EnemyBullet")
    {
        pTarget->KillMe();
        nowHp_ -= eb_damege;
        Audio::Play(DamegeSound_);
    }

    if (pTarget->GetObjectName() == "EnemyBullet2")
    {
        pTarget->KillMe();
        nowHp_ -= sec_eb_damege;
    }

    if (pTarget->GetObjectName() == "minBullet")
    {
        pTarget->KillMe();
        nowHp_ -= min_b_damege;
    }
}
