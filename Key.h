#pragma once
#include "Engine/GameObject.h"
#include <DirectXMath.h>
#include <d3d11.h>

class Key : public GameObject
{
    int hKey_;
    int IMB = 0; //I=�摜�AM=���f���AB=BGM

    //-----�L�[�̑傫���̐ݒ�-----
    XMFLOAT3 KEY_SCL = XMFLOAT3(0.5f, 0.5f, 0.5f);
    //----------------------------

    //-----�R���C�_�[�̒��S�ʒu�Ƒ傫���̐ݒ�-----
    XMFLOAT3 BASE_POS = XMFLOAT3(-0.1f, 0.4f, 0.3f);
    float c_scl = 0.3f;
    //--------------------------------------------

    Transform tKey;
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