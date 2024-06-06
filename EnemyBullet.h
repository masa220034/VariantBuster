#pragma once
#include "Engine/GameObject.h"

class EnemyBullet : public GameObject
{
    int hModel_;
    int eBulletSound_;

    //-----�e�̑傫���̐ݒ�-----
    XMFLOAT3 BULLET_SCL = XMFLOAT3(0.3f, 0.3f, 0.3f);
    //--------------------------

    //-----�R���C�_�[�̒��S�ʒu�Ƒ傫���̐ݒ�-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.0f, 0.1f, 0.1f);
    XMFLOAT3 COLLIDER_SIZE = XMFLOAT3(1.5f, 1.5f, 1.0f);
    //--------------------------------------------

    //-----�e�̑��x�Ƌ����̐ݒ�-----
    float v_shot = 0.5f;
    float limitPos = 20.0f;
    //------------------------------

public:
    //�R���X�g���N�^
    EnemyBullet(GameObject* parent);

    //�f�X�g���N�^
    ~EnemyBullet();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};