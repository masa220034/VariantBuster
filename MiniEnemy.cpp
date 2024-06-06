#include "MiniEnemy.h"
#include "Engine/Model.h"
#include "minBullet.h"

//�R���X�g���N�^
MiniEnemy::MiniEnemy(GameObject* parent)
    :GameObject(parent, "Enemy"), hMiniEnemy_(-1),
    frameCount(0), DelayFrame(150)
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

    tMiniEnemy.position_ = MINIENEMY_POS;
    tMiniEnemy.scale_ = MINIENEMY_SCL;  
}

//�X�V
void MiniEnemy::Update()
{
    movePattern();

    if (frameCount >= DelayFrame)
    {
        if (rand() % 100 == 0)
        {
            minBullet* pminBullet = Instantiate<minBullet>(GetParent());
            pminBullet->SetPosition(tMiniEnemy.position_);
        }
    }
    else
    {
        frameCount++;
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
        if (tMiniEnemy.position_.x >= movedPos)
        {
            moveUp = false;
        }
    }
    else
    {
        tMiniEnemy.position_.x -= move;
        if (tMiniEnemy.position_.x <= -movedPos)
        {
            moveUp = true;
        }
    }
}