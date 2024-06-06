#include "minBullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"

//コンストラクタ
minBullet::minBullet(GameObject* parent)
    :GameObject(parent, "minBullet"), hModel_(-1)
{
}

//デストラクタ
minBullet::~minBullet()
{
}

//初期化
void minBullet::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("minBullet.fbx");
    assert(hModel_ >= 0);

    BoxCollider* collision = new BoxCollider(BASE_POS, COLLIDER_SIZE);
    AddCollider(collision);

    transform_.scale_ = BULLET_SCL;
}

//更新
void minBullet::Update()
{
    transform_.position_.y -= v_shot;
    if (transform_.position_.y <= limitPosY)
    {
        KillMe();
    }
}

//描画
void minBullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void minBullet::Release()
{
}