#include "Key.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Key::Key(GameObject* parent)
    :GameObject(parent, "Key"), hKey_(-1)
{
}

//デストラクタ
Key::~Key()
{
}

//初期化
void Key::Initialize()
{
    hKey_ = Model::Load("Key.fbx");
    assert(hKey_ >= 0);

    transform_.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(-0.1, 0.4, 0.3), 0.3f);
    AddCollider(collision);
}

//更新
void Key::Update()
{
}

//描画
void Key::Draw()
{
    Model::SetTransform(hKey_, transform_);
    Model::Draw(hKey_);
}

//開放
void Key::Release()
{
}

void Key::SetPosition(const DirectX::XMFLOAT3& position)
{
    transform_.position_ = position;
}

DirectX::XMFLOAT3 Key::GetPosition() const
{
    return transform_.position_;
}