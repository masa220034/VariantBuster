#include "PlayerGauge.h"
#include "Engine/Image.h"

//�R���X�g���N�^
PlayerGauge::PlayerGauge(GameObject* parent)
    :GameObject(parent, "PlayerGauge"), hGauge_(-1), hFrame_(-1),
    maxHp_(100), nowHp_(0)
{
}

//�f�X�g���N�^
PlayerGauge::~PlayerGauge()
{
}

//������
void PlayerGauge::Initialize()
{
    hGauge_ = Image::Load("PlayerGauge.png");
    assert(hGauge_ >= 0);

    hFrame_ = Image::Load("PlayerGaugeFrame.png");
    assert(hFrame_ >= 0);

    pGauge.position_ = XMFLOAT3(posX, posY, posZ);
    pGauge.scale_.y = scaleY;
    pGauge.rotate_.z = rotateZ;
}

//�X�V
void PlayerGauge::Update()
{
}

//�`��
void PlayerGauge::Draw()
{
    //�v���C���[�Q�[�W�̕`��
    Transform PlayerGauge = pGauge;
    PlayerGauge.scale_.y = scaleY * ((float)nowHp_ / (float)maxHp_);
    Image::SetTransform(hGauge_, PlayerGauge);
    Image::Draw(hGauge_);

    Image::SetTransform(hFrame_, pGauge);
    Image::Draw(hFrame_);
}

//�J��
void PlayerGauge::Release()
{
}
