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

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0.0, 1.8, 0.0), XMFLOAT3(0.5, 3.5, 1.0));
    AddCollider(collision);

    transform_.scale_ = XMFLOAT3(0.3f, 0.5f, 0.0f);
}

//更新
void minBullet::Update()
{
    transform_.position_.y -= 0.3f;
    if (transform_.position_.y <= -20)
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