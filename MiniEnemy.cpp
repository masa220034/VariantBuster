#include "MiniEnemy.h"
#include "Engine/Model.h"
#include "minBullet.h"

//�R���X�g���N�^
MiniEnemy::MiniEnemy(GameObject* parent)
    :GameObject(parent, "Enemy"), hMiniEnemy_(-1)
{
}

//�f�X�g���N�^
MiniEnemy::~MiniEnemy()
{
}

//������
void MiniEnemy::Initialize()
{
    hMiniEnemy_ = Model::Load("miniEnemy.fbx");
    assert(hMiniEnemy_ >= 0);

    tMiniEnemy.scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);
    tMiniEnemy.position_ = XMFLOAT3((float)(rand() % 401 - 200) / 10, 5.8f, 0.0f);
}

//�X�V
void MiniEnemy::Update()
{
    movePattern();
    if (rand() % 100 == 0)
    {
        minBullet* pminBullet = Instantiate<minBullet>(GetParent());
        pminBullet->SetPosition(tMiniEnemy.position_);
    }
}

//�`��
void MiniEnemy::Draw()
{
    Model::SetTransform(hMiniEnemy_, tMiniEnemy);
    Model::Draw(hMiniEnemy_);
}

//�J��
void MiniEnemy::Release()
{
}

void MiniEnemy::movePattern()
{
    if (moveUp)
    {
        tMiniEnemy.position_.x += move;
        if (tMiniEnemy.position_.x >= 4.0f)
        {
            moveUp = false;
        }
    }
    else
    {
        tMiniEnemy.position_.x -= move;
        if (tMiniEnemy.position_.x <= -4.0f)
        {
            moveUp = true;
        }
    }
}