#include "EnemyBullet2.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"

//�R���X�g���N�^
EnemyBullet2::EnemyBullet2(GameObject* parent)
    :GameObject(parent, "EnemyBullet2"), hModel_(-1)
{
}

//�f�X�g���N�^
EnemyBullet2::~EnemyBullet2()
{
}

//������
void EnemyBullet2::Initialize()
{
    hModel_ = Model::Load("eBullet2.fbx");
    assert(hModel_ >= 0);

    transform_.scale_ = XMFLOAT3(0.3f, 0.3f, 0.3f);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.3, 0), 0.35f);
    AddCollider(collision);

    shot = true;
}

//�X�V
void EnemyBullet2::Update()
{
    if (shot)
    {
        transform_.position_.x += 0.5f;
        transform_.position_.y += 0.5f;
        if (transform_.position_.y >= 10.0f)
        {
            shot = false;
            KillMe();
        }
    }
    else 
    {
        if (rand() % 100 == 0)
        {
            transform_.position_.y -= 0.5f;
        }

        if (transform_.position_.y < -20.0f)
        {
            KillMe();
        }
    }
}

//�`��
void EnemyBullet2::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void EnemyBullet2::Release()
{
}