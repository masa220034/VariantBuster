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

    transform_.scale_ = XMFLOAT3(0.3f, 0.3f, 0.3f);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0.0, 0.1, 0.1), XMFLOAT3(1.5, 0.1, 1.0));
    AddCollider(collision);
}

//�X�V
void EnemyBullet::Update()
{
    Audio::Play(eBulletSound_);
    transform_.position_.x += direction.x;
    transform_.position_.y += direction.y;
    transform_.position_.z += direction.z;

    if (transform_.position_.x < -50.0f || transform_.position_.x > 50.0f ||
        transform_.position_.y < -50.0f || transform_.position_.y > 50.0f )
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