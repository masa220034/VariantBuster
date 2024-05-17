#include "EnemyBullet2.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
EnemyBullet2::EnemyBullet2(GameObject* parent)
    :GameObject(parent, "EnemyBullet2"), hModel_(-1)
{
}

//デストラクタ
EnemyBullet2::~EnemyBullet2()
{
}

//初期化
void EnemyBullet2::Initialize()
{
    hModel_ = Model::Load("eBullet2.fbx");
    assert(hModel_ >= 0);

    transform_.scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(basePosX, basePosY, basePosZ), c_scale);
    AddCollider(collision);

    shot = true;
}

//更新
void EnemyBullet2::Update()
{
    transform_.position_.x += v_shot;

    if (transform_.position_.x > limitPos)
    {
        KillMe();
    }
}

//描画
void EnemyBullet2::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void EnemyBullet2::Release()
{
}