#include "Key.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

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

    tKey.scale_ = KEY_SCL;

    SphereCollider* collision = new SphereCollider(BASE_POS, c_scl);
    AddCollider(collision);
}

//�X�V
void Key::Update()
{
    transform_ = tKey;
}

//�`��
void Key::Draw()
{
    Model::SetTransform(hKey_, tKey);
    Model::Draw(hKey_);
}

//�J��
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