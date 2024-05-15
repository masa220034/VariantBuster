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
    Camera::SetPosition(XMFLOAT3(0, 3, -10));
    Camera::SetTarget(XMFLOAT3(0, 2, 0));

    hPlayer_ = Model::Load("Player.fbx");
    assert(hPlayer_ >= 0);

    JumpSound_ = Audio::Load("JumpSound.wav");
    DamegeSound_ = Audio::Load("DamegeSound2.wav");
    assert(JumpSound_ >= 0);
    assert(DamegeSound_ >= 0);

    tPlayer.position_ = XMFLOAT3(-3.0f, 0.0f, 0.0f);
    tPlayer.scale_ = XMFLOAT3(0.2f, 0.2f, 0.2f);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0.0, 0.2, 0.0), 0.25f);
    AddCollider(collision);
}

//�X�V
void Player::Update()
{
    if (!isHpmax)
    {
        nowHp_ += 1;
        if (nowHp_ >= maxHp_)
        {
            nowHp_ = maxHp_;
            isHpmax = true;
        }
    }

    if (nowHp_ <= 0)
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
    data.dir = XMFLOAT3(0, -1, 0);       //���C�̕���
    Model::RayCast(hGroundModel, &data); //���C�𔭎�

    if (isJump)
    {
        tPlayer.position_.y += x;
        x -= gravity;

        if (tPlayer.position_.y <= 0.0f)
        {
            if (data.hit)
            {
                //���ꂪ����ꍇ�A�W�����v�������̈ʒu��������
                tPlayer.position_.y -= data.dist;
                tPlayer.position_.y = 0.0f;
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
        nowHp_ -= 2;
    }

    if (pTarget->GetObjectName() == "EnemyBullet")
    {
        pTarget->KillMe();
        nowHp_ -= 4;
        Audio::Play(DamegeSound_);
    }

    if (pTarget->GetObjectName() == "EnemyBullet2")
    {
        pTarget->KillMe();
        nowHp_ -= 8;
    }

    if (pTarget->GetObjectName() == "minBullet")
    {
        pTarget->KillMe();
        nowHp_ -= 4;
    }
}
