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

    transform_.position_ = XMFLOAT3(0.15f, 0.85f, 0.0f);
    transform_.scale_.y = 2.0f;
    transform_.rotate_.z = 90;
}

//更新
void Gauge::Update()
{
}

//描画
void Gauge::Draw()
{
    Transform transGauge = transform_;
    transGauge.scale_.y = 2 * ((float)nowPt_ / (float)maxPt_);
    Image::SetTransform(hGauge_, transGauge);
    Image::Draw(hGauge_);

    Image::SetTransform(hFrame_, transform_);
    Image::Draw(hFrame_);
}

//開放
void Gauge::Release()
{
}