#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class minBullet : public GameObject
{
    int hModel_;

    //-----�R���C�_�[�̒��S�ʒu�A�傫���̐ݒ�-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.0f, 1.8f, 0.0f);
    XMFLOAT3 COLLIDER_SIZE = XMFLOAT3(0.5f, 3.5f, 1.0f);
    //--------------------------------------------

    //-----�e�̑傫���̐ݒ�-----
    XMFLOAT3 BULLET_SCL = XMFLOAT3(0.3f, 0.5f, 0.0f);
    //--------------------------

    float v_shot = 0.3f;
    float limitPosY = -20.0f;
public:
    //�R���X�g���N�^
    minBullet(GameObject* parent);

    //�f�X�g���N�^
    ~minBullet();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

