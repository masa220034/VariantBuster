#include "EnemyBullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/BoxCollider.h"


//�R���X�g���N�^
EnemyBullet::EnemyBullet(GameObject* parent)
    :GameObject(parent, "EnemyBullet"), hModel_(-1), eBulletSound_(-1)
{
}

//�f�X�g���N�^
EnemyBullet::~EnemyBullet()
{
}

//������
void EnemyBullet::Initialize()
{
    hModel_ = Model::Load("eBullet.fbx");
    assert(hModel_ >= 0);

    eBulletSound_ = Audio::Load("eBulletSound.wav");
    assert(eBulletSound_ >= 0);

    transform_.scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(basePosX, basePosY, basePosZ), XMFLOAT3(c_sizeX, c_sizeY, c_sizeZ));
    AddCollider(collision);
}

//�X�V
void EnemyBullet::Update()
{
    Audio::Play(eBulletSound_);

    transform_.position_.x -= v_shot;

    if (transform_.position_.x >= limitPos)
    {
        KillMe();
    }
}

//�`��
void EnemyBullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void EnemyBullet::Release()
{
}