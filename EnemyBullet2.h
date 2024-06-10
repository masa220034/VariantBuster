#pragma once
#include "Engine/GameObject.h"

class EnemyBullet2 : public GameObject
{
    int hModel_;

    //-----�e�̑傫���̐ݒ�-----
    XMFLOAT3 BULLET_SCL = XMFLOAT3(0.3f, 0.3f, 0.3f);
    //--------------------------

    //-----�R���C�_�[�̒��S�ʒu�A�傫���̐ݒ�-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.0f, 0.3f, 0.0f);
    float c_scale = 0.35f;
    //--------------------------------------------

    float v_shot = 0.5f;
    float limitPos = 20.0f;
public:
    //�R���X�g���N�^
    EnemyBullet2(GameObject* parent);

    //�f�X�g���N�^
    ~EnemyBullet2();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
