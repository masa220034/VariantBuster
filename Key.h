#pragma once
#include "Engine/GameObject.h"
#include <DirectXMath.h>
#include <d3d11.h>

class Key : public GameObject
{
    int hKey_;
public:
    //�R���X�g���N�^
    Key(GameObject* parent);

    //�f�X�g���N�^
    ~Key();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetPosition(const DirectX::XMFLOAT3& position);

    DirectX::XMFLOAT3 GetPosition() const;
};