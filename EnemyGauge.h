#pragma once
#include "Engine/GameObject.h"

class EnemyGauge : public GameObject
{
	int hGauge_;
    int hGauge_BG;
	int hFrame_;
    int nowHp_, maxHp_, animHp_;

    //-----ゲージの位置や大きさなどの設定-----
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

