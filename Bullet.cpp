#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SphereCollider.h"


//コンストラクタ
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), hModel_(-1), BulletSound_(-1)
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
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

//更新
void Bullet::Update()
{
    Audio::Play(BulletSound_);

    transform_.position_.x += direction_.x * v_shot;
    
    if (transform_.position_.x > limitPos)
    {
        KillMe();
    }
}

//描画
void Bullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Bullet::Release()
{
}

void Bullet::SetDirection(const XMFLOAT3& direction)
{
    direction_ = direction;
}

