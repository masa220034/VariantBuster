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

    transform_.position_ = XMFLOAT3(posX, posY, posZ);
    transform_.scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);
    transform_.rotate_ = XMFLOAT3(rotateX, rotateY, rotateZ);
}

//�X�V
void EnemyGauge::Update()
{
}

//�`��
void EnemyGauge::Draw()
{
    //�G�̃Q�[�W�̕`��
    Transform transGauge = transform_;
    transGauge.scale_.y = scaleY * ((float)nowHp_ / (float)maxHp_);
    Image::SetTransform(hGauge_, transGauge);
    Image::Draw(hGauge_);

    Image::SetTransform(hFrame_, transform_);
    Image::Draw(hFrame_);
}

//�J��
void EnemyGauge::Release()
{
}