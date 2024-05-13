#include "EnemyGauge.h"
#include "Engine/Image.h"

//�R���X�g���N�^
EnemyGauge::EnemyGauge(GameObject* parent)
    :GameObject(parent, "EnemyGauge"), hGauge_(-1), hFrame_(-1),
    maxHp_(200), nowHp_(0)
{
}

//�f�X�g���N�^
EnemyGauge::~EnemyGauge()
{
}

//������
void EnemyGauge::Initialize()
{
    hGauge_ = Image::Load("EnemyGauge.png");
    assert(hGauge_ >= 0);

    hFrame_ = Image::Load("EnemyGaugeFrame.png");
    assert(hFrame_ >= 0);

    transform_.position_ = XMFLOAT3(0.15f, 0.85f, 0.0f);
    transform_.scale_.y = 2.0f;
    transform_.rotate_.z = 90;
}

//�X�V
void EnemyGauge::Update()
{
}

//�`��
void EnemyGauge::Draw()
{
    //�G�l�~�[�̃Q�[�W�̕`��
    Transform transGauge = transform_;
    transGauge.scale_.y = 2 * ((float)nowHp_ / (float)maxHp_);
    Image::SetTransform(hGauge_, transGauge);
    Image::Draw(hGauge_);

    Image::SetTransform(hFrame_, transform_);
    Image::Draw(hFrame_);
}

//�J��
void EnemyGauge::Release()
{
}