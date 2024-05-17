#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class EnemyBullet2 : public GameObject
{
    int hModel_;

    //-----�e�̑傫���̐ݒ�-----
    float scaleX = 0.3f;
    float scaleY = 0.3f;
    float scaleZ = 0.3f;
    //--------------------------

    //-----�R���C�_�[�̒��S�ʒu�A�傫���̐ݒ�-----
    float basePosX = 0.0;
    float basePosY = 0.3;
    float basePosZ = 0.0;
    float c_scale = 0.35f;
    //--------------------------------------------

    float v_shot = 0.5f;
    float limitPos = 20.0f;
    bool shot;
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
