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

    transform_.scale_ = XMFLOAT3(0.3f, 0.3f, 0.3f);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0.1, 0.1, 0.1), 0.3f);
    AddCollider(collision);
}

//更新
void Bullet::Update()
{
    Audio::Play(BulletSound_);

    transform_.position_.x += 0.5f;
    if (transform_.position_.x > 50.0f)
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

