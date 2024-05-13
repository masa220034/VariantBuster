#pragma once
#include "Engine/GameObject.h"

class PlayerGauge : public GameObject
{
    int hGauge_;
    int hFrame_;
    int nowHp_, maxHp_, animHp_;

    Transform pGauge;
public:
    //コンストラクタ
    PlayerGauge(GameObject* parent);

    //デストラクタ
    ~PlayerGauge();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetHp(int nowHp, int maxHp)
    {
        nowHp_ = nowHp;
        maxHp_ = maxHp;
        animHp_ = (animHp_ * 9 + nowHp_) / 10;
    }
};

