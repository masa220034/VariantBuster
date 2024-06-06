#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SphereCollider.h"


//�R���X�g���N�^
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), hModel_(-1), BulletSound_(-1)
{
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
    hModel_ = Model::Load("Bullet.fbx");
    assert(hModel_ >= 0);

    BulletSound_ = Audio::Load("BulletSound.wav");
    assert(BulletSound_ >= 0);

    transform_.scale_ = BULLET_SCL;
    SphereCollider* collision = new SphereCollider(BASE_POS, c_scale);
    AddCollider(collision);
}

//�X�V
void Bullet::Update()
{
    Audio::Play(BulletSound_);

    transform_.position_.x += direction_.x * v_shot;
    
    if (transform_.position_.x > limitPos)
    {
        KillMe();
    }
}

//�`��
void Bullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Bullet::Release()
{
}

void Bullet::SetDirection(const XMFLOAT3& direction)
{
    direction_ = direction;
}

