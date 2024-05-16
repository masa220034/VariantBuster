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

    BoxCollider* collision = new BoxCollider(XMFLOAT3(basePosX, basePosY, basePosZ), XMFLOAT3(sizeX, sizeY, sizeZ));
    AddCollider(collision);

    m_Bullet.scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);
}

//�X�V
void minBullet::Update()
{
    m_Bullet.position_.y -= v_shot;
    if (m_Bullet.position_.y <= limitPosY)
    {
        KillMe();
    }
}

//�`��
void minBullet::Draw()
{
    Model::SetTransform(hModel_, m_Bullet);
    Model::Draw(hModel_);
}

//�J��
void minBullet::Release()
{
}