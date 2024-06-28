#include "Key.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
Key::Key(GameObject* parent)
    :GameObject(parent, "Key"), hKey_(-1)
{
}

//�f�X�g���N�^
Key::~Key()
{
}

//������
void Key::Initialize()
{
    hKey_ = Model::Load("Key.fbx");
    assert(hKey_ >= 0);
}

//�X�V
void Key::Update()
{
    //SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
    //pSceneManager->ChangeScene(SCENE_ID_GAMECLEAR);
}

//�`��
void Key::Draw()
{
    Model::SetTransform(hKey_, transform_);
    Model::Draw(hKey_);
}

//�J��
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
