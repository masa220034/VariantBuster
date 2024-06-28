#include "Key.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"

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
}

//更新
void Key::Update()
{
    //SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
    //pSceneManager->ChangeScene(SCENE_ID_GAMECLEAR);
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
