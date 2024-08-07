#pragma once
#include "Engine/GameObject.h"

class PlayerGauge : public GameObject
{
    int hGauge_;
    int hGauge_BG;
    int hFrame_;
    int nowHp_, maxHp_, animHp_;
    int IMB = 0; //I=画像、M=モデル、B=BGM

    //-----ゲージの位置や大きさなどの設定-----
    float Gauge_UP = 2.0f;
    XMFLOAT3 GAUGE_POS = XMFLOAT3(-0.95f, 0.85f, 0.0f);
    XMFLOAT3 GAUGE_SCL= XMFLOAT3(1.0f, 2.0f, 1.0f);
    XMFLOAT3 GAUGE_ROT = XMFLOAT3(0.0f, 0.0f, 90.0f);
    //----------------------------------------

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

