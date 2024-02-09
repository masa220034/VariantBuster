#pragma once
#include "Engine/GameObject.h"

class Gauge : public GameObject
{
	int hGauge_;
	int hFrame_;

	int nowPt_, maxPt_, animPt_;
    Transform transGauge;
public:
    //コンストラクタ
    Gauge(GameObject* parent);

    //デストラクタ
    ~Gauge();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetPt(int nowPt, int maxPt)
    {
        nowPt_ = nowPt;
        maxPt_ = maxPt;
        animPt_ = (animPt_ * 9 + nowPt_) / 10;
    }
};

