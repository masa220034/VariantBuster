#pragma once
#include "Key.h"
#include "Engine/GameObject.h"
#include "EffekseeLib/EffekseerVFX.h"

class TutorialEnemy : public GameObject
{
    int hEnemy_;
    int DeathSound_;

    //-----敵のHPの設定-----
    bool isHpmax;
    int nowHp_, maxHp_;
    int upHp_ = 1;
    int noHp_ = 0;
    //----------------------

    //-----HPゲージの減少関連について-----
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
    //コンストラクタ
    TutorialEnemy(GameObject* parent);

    //デストラクタ
    ~TutorialEnemy();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void StartDamage(float amount);

    std::shared_ptr<EFFEKSEERLIB::EFKTransform> mt;
};

