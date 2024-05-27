#include "EnemyGauge.h"
#include "Engine/Image.h"

//コンストラクタ
EnemyGauge::EnemyGauge(GameObject* parent)
    :GameObject(parent, "EnemyGauge"), hGauge_(-1), hFrame_(-1), hGauge_BG(-1),
    maxHp_(200), nowHp_(0)
{
}

//デストラクタ
EnemyGauge::~EnemyGauge()
{
}

//初期化
void EnemyGauge::Initialize()
{
    hGauge_BG = Image::Load("EnemyGaugeBG.png");
    assert(hGauge_BG >= 0);

    hGauge_ = Image::Load("EnemyGauge.png");
    assert(hGauge_ >= 0);

    hFrame_ = Image::Load("EnemyGaugeFrame.png");
    assert(hFrame_ >= 0);

    pGauge.position_ = XMFLOAT3(posX, posY, posZ);
    pGauge.scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);
    pGauge.rotate_ = XMFLOAT3(rotateX, rotateY, rotateZ);
}

//更新
void EnemyGauge::Update()
{
}

//描画
void EnemyGauge::Draw()
{
    Image::SetTransform(hGauge_BG, pGauge);
    Image::Draw(hGauge_BG);

    //敵のゲージの描画
    Transform transGauge = pGauge;
    transGauge.scale_.y = scaleY * ((float)nowHp_ / (float)maxHp_);
    Image::SetTransform(hGauge_, transGauge);
    Image::Draw(hGauge_);

    Image::SetTransform(hFrame_, pGauge);
    Image::Draw(hFrame_);
}

//開放
void EnemyGauge::Release()
{
}