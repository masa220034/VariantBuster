#include "PlayerGauge.h"
#include "Engine/Image.h"

//コンストラクタ
PlayerGauge::PlayerGauge(GameObject* parent)
    :GameObject(parent, "PlayerGauge"), hGauge_(-1), hFrame_(-1), hGauge_BG(-1),
    maxHp_(0), nowHp_(0)
{
}

//デストラクタ
PlayerGauge::~PlayerGauge()
{
}

//初期化
void PlayerGauge::Initialize()
{
    hGauge_BG = Image::Load("PlayerGaugeBG.png");
    assert(hGauge_BG >= IMB);

    hGauge_ = Image::Load("PlayerGauge.png");
    assert(hGauge_ >= IMB);

    hFrame_ = Image::Load("PlayerGaugeFrame.png");
    assert(hFrame_ >= IMB);



    pGauge.position_ = GAUGE_POS;
    pGauge.scale_ = GAUGE_SCL;
    pGauge.rotate_ = GAUGE_ROT;
}

//更新
void PlayerGauge::Update()
{
}

//描画
void PlayerGauge::Draw()
{
    Image::SetTransform(hGauge_BG, pGauge);
    Image::Draw(hGauge_BG);

    //プレイヤーゲージの描画
    Transform PlayerGauge = pGauge;
    PlayerGauge.scale_.y = Gauge_UP * ((float)nowHp_ / (float)maxHp_);
    Image::SetTransform(hGauge_, PlayerGauge);
    Image::Draw(hGauge_);

    Image::SetTransform(hFrame_, pGauge);
    Image::Draw(hFrame_);
}

//開放
void PlayerGauge::Release()
{
}
