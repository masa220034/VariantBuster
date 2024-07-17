#pragma once
#include "Key.h"
#include "Engine/GameObject.h"
#include "EffekseeLib/EffekseerVFX.h"

class TutorialEnemy : public GameObject
{
    int hEnemy_;
    int DeathSound_;

    //-----�G��HP�̐ݒ�-----
    bool isHpmax;
    int nowHp_, maxHp_;
    int upHp_ = 1;
    int noHp_ = 0;
    //----------------------

    //-----HP�Q�[�W�̌����֘A�ɂ���-----
    bool isDamage;
    float d_Amount;
    float d_Step;
    float targetHp;
    //------------------------------------

    Key* pKey_;
    bool isKey_;

    unsigned int frameCount;
    unsigned int DelayFrame;

    Transform tEnemy;
public:
    //�R���X�g���N�^
    TutorialEnemy(GameObject* parent);

    //�f�X�g���N�^
    ~TutorialEnemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void StartDamage(float amount);

    std::shared_ptr<EFFEKSEERLIB::EFKTransform> mt;
};

