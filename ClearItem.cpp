#include "ClearItem.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
ClearItem::ClearItem(GameObject* parent)
    :GameObject(parent, "ClearItem"), hClearItem_(-1)
{
}

//デストラクタ
ClearItem::~ClearItem()
{
}

//初期化
void ClearItem::Initialize()
{
    hClearItem_ = Model::Load("ClearItem.fbx");
    assert(hClearItem_ >= IMB);

    tClearItem.scale_ = ClearItem_SCL;

    SphereCollider* collision = new SphereCollider(BASE_POS, c_scl);
    AddCollider(collision);
}

//更新
void ClearItem::Update()
{
    transform_ = tClearItem;
}

//描画
void ClearItem::Draw()
{
    Model::SetTransform(hClearItem_, tClearItem);
    Model::Draw(hClearItem_);
}

//開放
void ClearItem::Release()
{
}

void ClearItem::SetPosition(const DirectX::XMFLOAT3& position)
{
    tClearItem.position_ = position;
}

DirectX::XMFLOAT3 ClearItem::GetPosition() const
{
    return tClearItem.position_;
}