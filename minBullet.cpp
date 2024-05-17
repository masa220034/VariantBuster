#include "minBullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"

//�R���X�g���N�^
minBullet::minBullet(GameObject* parent)
    :GameObject(parent, "minBullet"), hModel_(-1)
{
}

//�f�X�g���N�^
minBullet::~minBullet()
{
}

//������
void minBullet::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("minBullet.fbx");
    assert(hModel_ >= 0);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(basePosX, basePosY, basePosZ), XMFLOAT3(c_sizeX, c_sizeY, c_sizeZ));
    AddCollider(collision);

    transform_.scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);
}

//�X�V
void minBullet::Update()
{
    transform_.position_.y -= v_shot;
    if (transform_.position_.y <= limitPosY)
    {
        KillMe();
    }
}

//�`��
void minBullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void minBullet::Release()
{
}