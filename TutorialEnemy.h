#pragma once
#include "Key.h"
#include "Engine/GameObject.h"
#include "EffekseeLib/EffekseerVFX.h"

class TutorialEnemy : public GameObject
{
    int hEnemy_;
    int DamegeSound_;
    int DeathSound_;

    //-----�G�̈ʒu�Ƒ傫���̐ݒ�-----
    XMFLOAT3 ENEMY_POS = XMFLOAT3(5.0f, 1.5f, 0.0f);
    XMFLOAT3 ENEMY_SCL = XMFLOAT3(0.5f, 0.5f, 0.5f);
    //--------------------------------

    //-----�R���C�_�[�̒��S�ʒu�Ƒ傫���̐ݒ�-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.0f, 0.5f, 0.0f);
    float c_scale = 0.55f;
    //--------------------------------------------

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

    //-----�A�j���[�V�����̐ݒ�-----
    int startAnim = 1;
    int finishAnim = 60;
    float AnimSpeed = 0.5f;
    //------------------------------

    Key* pKey_;
    bool isKey_;

    int B_damage = 20;
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

    void OnCollision(GameObject* pTarget);

    void StartDamage(float amount);

    XMFLOAT3 GetPosition() const { return tEnemy.position_; }

    std::shared_ptr<EFFEKSEERLIB::EFKTransform> mt;
};

