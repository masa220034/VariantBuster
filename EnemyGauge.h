#pragma once
#include "Engine/GameObject.h"

class EnemyGauge : public GameObject
{
	int hGauge_;
    int hGauge_BG;
	int hFrame_;
    int nowHp_, maxHp_, animHp_;

    //-----�Q�[�W�̈ʒu��傫���Ȃǂ̐ݒ�-----
    float posX = 0.15f;
    float posY = 0.85f;
    float posZ = 0.0f;
    float scaleX = 1.0f;
    float scaleY = 2.0f;
    float scaleZ = 1.0f;
    float rotateX = 0.0f;
    float rotateY = 0.0f;
    float rotateZ = 90.0f;
    //-----------------------------------------

    Transform pGauge;
public:
    //�R���X�g���N�^
    EnemyGauge(GameObject* parent);

    //�f�X�g���N�^
    ~EnemyGauge();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetHp(int nowHp, int maxHp)
    {
        nowHp_ = nowHp;
        maxHp_ = maxHp;
        animHp_ = (animHp_ * 9 + nowHp_) / 10;
    }
};

