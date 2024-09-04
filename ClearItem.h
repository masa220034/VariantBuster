#pragma once
#include "Engine/GameObject.h"
#include <DirectXMath.h>
#include <d3d11.h>

class ClearItem : public GameObject
{
    int hClearItem_;
    int IMB = 0; //I=�摜�AM=���f���AB=BGM

    //-----�L�[�̑傫���̐ݒ�-----
    XMFLOAT3 ClearItem_SCL = XMFLOAT3(0.2f, 0.2f, 0.2f);
    //----------------------------

    //-----�R���C�_�[�̒��S�ʒu�Ƒ傫���̐ݒ�-----
    XMFLOAT3 BASE_POS = XMFLOAT3(-0.1f, 0.3f, 0.3f);
    float c_scl = 0.3f;
    //--------------------------------------------

    Transform tClearItem;
public:
    //�R���X�g���N�^
    ClearItem(GameObject* parent);

    //�f�X�g���N�^
    ~ClearItem();

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