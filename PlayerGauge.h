#pragma once
#include "Engine/GameObject.h"

class PlayerGauge : public GameObject
{
    int hGauge_;
    int hFrame_;
    int nowHp_, maxHp_, animHp_;

    Transform pGauge;
public:
    //�R���X�g���N�^
    PlayerGauge(GameObject* parent);

    //�f�X�g���N�^
    ~PlayerGauge();

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

