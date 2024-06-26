#pragma once
#include "Engine/GameObject.h"

class EnemyGauge : public GameObject
{
	int hGauge_;
    int hGauge_BG;
	int hFrame_;
    int nowHp_, maxHp_, animHp_;

    //-----ゲージの位置や大きさなどの設定-----
    float Gauge_UP = 2.0f;
    XMFLOAT3 GAUGE_POS = XMFLOAT3(0.15f, 0.85f, 0.0f);
    XMFLOAT3 GAUGE_SCL = XMFLOAT3(1.0f, 2.0f, 1.0f);
    XMFLOAT3 GAUGE_ROT = XMFLOAT3(0.0f, 0.0f, 90.0f);
    //-----------------------------------------

    Transform pGauge;
public:
    //コンストラクタ
    EnemyGauge(GameObject* parent);

    //デストラクタ
    ~EnemyGauge();

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

