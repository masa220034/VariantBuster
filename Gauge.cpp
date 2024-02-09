#include "Gauge.h"
#include "Engine/Image.h"

//コンストラクタ
Gauge::Gauge(GameObject* parent)
    :GameObject(parent, "Gauge"), hGauge_(-1), hFrame_(-1),
    maxPt_(200), nowPt_(0)
{
}

//デストラクタ
Gauge::~Gauge()
{
}

//初期化
void Gauge::Initialize()
{
    hGauge_ = Image::Load("Gauge.png");
    assert(hGauge_ >= 0);

    hFrame_ = Image::Load("GaugeFrame.png");
    assert(hFrame_ >= 0);

    transform_.position_.x = 0.8f;
    transform_.position_.y = 0.7f;
    transform_.scale_ = XMFLOAT3(0.3f, 0.3f, 0.3f);
}

//更新
void Gauge::Update()
{
}

//描画
void Gauge::Draw()
{
    transGauge.scale_.x = (float)animPt_ / (float)maxPt_;
    Image::SetTransform(hGauge_, transGauge);
    Image::Draw(hGauge_);

    Image::SetTransform(hFrame_, transform_);
    Image::Draw(hFrame_);
}

//開放
void Gauge::Release()
{
}