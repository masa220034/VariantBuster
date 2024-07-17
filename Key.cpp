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

    tKey.scale_ = KEY_SCL;

    SphereCollider* collision = new SphereCollider(BASE_POS, c_scl);
    AddCollider(collision);
}

//更新
void Key::Update()
{
    transform_ = tKey;
}

//描画
void Key::Draw()
{
    Model::SetTransform(hKey_, tKey);
    Model::Draw(hKey_);
}

//開放
void Key::Release()
{
}

void Key::SetPosition(const DirectX::XMFLOAT3& position)
{
    tKey.position_ = position;
}

DirectX::XMFLOAT3 Key::GetPosition() const
{
    return tKey.position_;
}