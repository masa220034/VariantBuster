#pragma once
#include "Engine/GameObject.h"

class Enemy : public GameObject
{
    int hEnemy_;
    int hMiniEnemy_;
    int DamegeSound_;

    //-----�G�̈ʒu�A�傫���̐ݒ�-----
    float posX = 5.5f;
    float posY = 2.0f;
    float posZ = 0.0f;
    float scaleX = 0.3f;
    float scaleY = 0.3f;
    float scaleZ = 0.3f;
    //--------------------------------

    //-----�R���C�_�[�̒��S�ʒu�A�傫���̐ݒ�-----
    float basePosX = 0.0f;
    float basePosY = 1.0f;
    float basePosZ = 0.0f;
    float c_scale = 1.1f;
    //--------------------------------------------

    //-----�G��HP�̐ݒ�-----
    int nowHp_, maxHp_, halfHp_;
    int noHp_ = 0;
    int upHp_ = 2;
    bool isHpmax;
    //----------------------

    //-----�G�̓����Ɋւ���ݒ�-----
    bool moveUp;
    float move = 0.05f;
    float moveUp_lim = 2.0f;
    float moveDown_lim = 0.0f;
    //------------------------------

    int B_damage = 3;
    float ene_move = 0.1f;
    float lim_ene_pos = -5.0f;
    float ene_rotate = 180;
    unsigned int frameCount;
    unsigned int DelayFrame;

    Transform tEnemy;
    Transform tMiniEnemy;
public:
    //�R���X�g���N�^
    Enemy(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void OnCollision(GameObject* pTarget) override;

    void AttackPattern();

    void movePattern();
};
