#include "PlayerGauge.h"
#include "Engine/Image.h"

//コンストラクタ
PlayerGauge::PlayerGauge(GameObject* parent)
    :GameObject(parent, "PlayerGauge"), hGauge_(-1), hFrame_(-1),
    maxHp_(100), nowHp_(0)
{
}

//デストラクタ
PlayerGauge::~PlayerGauge()
{
}

//初期化
void PlayerGauge::Initialize()
{
    hGauge_ = Image::Load("PlayerGauge.png");
    assert(hGauge_ >= 0);

    hFrame_ = Image::Load("PlayerGaugeFrame.png");
    assert(hFrame_ >= 0);

    pGauge.position_ = XMFLOAT3(-0.95f, 0.85f, 0.0f);
    pGauge.scale_.y = 2.0f;
    pGauge.rotate_.z = 90;
}

//更新
void PlayerGauge::Update()
{
}

//描画
void PlayerGauge::Draw()
{
    //プレイヤーゲージの描画
    Transform PlayerGauge = pGauge;
    PlayerGauge.scale_.y = 2 * ((float)nowHp_ / (float)maxHp_);
    Image::SetTransform(hGauge_, PlayerGauge);
    Image::Draw(hGauge_);

    Image::SetTransform(hFrame_, pGauge);
    Image::Draw(hFrame_);
}

//開放
void PlayerGauge::Release()
{
}
