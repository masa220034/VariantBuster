#include "MiniEnemy.h"
#include "Engine/Model.h"
#include "minBullet.h"

//コンストラクタ
MiniEnemy::MiniEnemy(GameObject* parent)
    :GameObject(parent, "Enemy"), hMiniEnemy_(-1),
    frameCount(0), DelayFrame(150)
{
}

//デストラクタ
MiniEnemy::~MiniEnemy()
{
}

//初期化
void MiniEnemy::Initialize()
{
    hMiniEnemy_ = Model::Load("miniEnemy.fbx");
    assert(hMiniEnemy_ >= 0);

    tMiniEnemy.position_ = MINIENEMY_POS;
    tMiniEnemy.scale_ = MINIENEMY_SCL;  
}

//更新
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

//描画
void MiniEnemy::Draw()
{
    Model::SetTransform(hMiniEnemy_, tMiniEnemy);
    Model::Draw(hMiniEnemy_);
}

//開放
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