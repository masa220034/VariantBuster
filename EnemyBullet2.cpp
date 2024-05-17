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

    transform_.scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(basePosX, basePosY, basePosZ), c_scale);
    AddCollider(collision);

    shot = true;
}

//�X�V
void EnemyBullet2::Update()
{
    transform_.position_.x += v_shot;

    if (transform_.position_.x > limitPos)
    {
        KillMe();
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