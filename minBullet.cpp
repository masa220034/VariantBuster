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

    BoxCollider* collision = new BoxCollider(BASE_POS, COLLIDER_SIZE);
    AddCollider(collision);

    transform_.scale_ = BULLET_SCL;
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