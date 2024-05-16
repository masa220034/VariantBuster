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

    BoxCollider* collision = new BoxCollider(XMFLOAT3(basePosX, basePosY, basePosZ), XMFLOAT3(sizeX, sizeY, sizeZ));
    AddCollider(collision);

    m_Bullet.scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);
}

//更新
void minBullet::Update()
{
    m_Bullet.position_.y -= v_shot;
    if (m_Bullet.position_.y <= limitPosY)
    {
        KillMe();
    }
}

//描画
void minBullet::Draw()
{
    Model::SetTransform(hModel_, m_Bullet);
    Model::Draw(hModel_);
}

//開放
void minBullet::Release()
{
}