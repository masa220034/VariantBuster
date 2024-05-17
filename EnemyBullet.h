#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class EnemyBullet : public GameObject
{
    int hModel_;
    int eBulletSound_;

    //-----�e�̑傫���̐ݒ�-----
    float scaleX = 0.3f;
    float scaleY = 0.3f;
    float scaleZ = 0.3f;
    //--------------------------

    //-----�R���C�_�[�̒��S�ʒu�Ƒ傫���̐ݒ�-----
    float basePosX = 0.0f;
    float basePosY = 0.1f;
    float basePosZ = 0.1f;
    float c_sizeX = 1.5f;
    float c_sizeY = 1.5f;
    float c_sizeZ = 1.0f;
    //--------------------------------------------

    float v_shot = 0.5f;
    float limitPos = 20.0f;
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