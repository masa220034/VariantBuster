#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class minBullet : public GameObject
{
    int hModel_;

    //-----�R���C�_�[�̒��S�ʒu�A�傫���̐ݒ�-----
    float basePosX = 0.0f;
    float basePosY = 1.8f;
    float basePosZ = 0.0f;
    float c_sizeX = 0.5f;
    float c_sizeY = 3.5f;
    float c_sizeZ = 1.0f;
    //--------------------------------------------

    //-----�e�̑傫���̐ݒ�-----
    float scaleX = 0.3f;
    float scaleY = 0.5f;
    float scaleZ = 0.0f;
    //--------------------------

    float v_shot = 0.3f;
    float limitPosY = -20.0f;
    Transform m_Bullet;
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

