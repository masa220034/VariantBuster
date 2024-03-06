#include "Enemy.h"
#include "Gauge.h"
#include "EnemyBullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), hModel_(-1),
    maxHp_(200), nowHp_(0)
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
    hModel_ = Model::Load("Enemy.fbx");
    assert(hModel_ >= 0);

    transform_.position_.x = 5.5f;
    transform_.scale_ = XMFLOAT3(0.3f, 0.3f, 0.3f);
    transform_.rotate_.y = 180;

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 1.5, 0), 1.2f);
    AddCollider(collision);

    moveUp = true;
}

//更新
void Enemy::Update()
{
    nowHp_ += 1;
    if (nowHp_ >= maxHp_)
    {
        nowHp_ = maxHp_;
    }

    Gauge* pGauge = (Gauge*)FindObject("Gauge");
    pGauge->SetPt(nowHp_, maxHp_);
 
    if (moveUp)
    {
        transform_.position_.y += move;
        if (transform_.position_.y >= 2.0f)
        {
            moveUp = false;
        }
    }
    else
    {
        transform_.position_.y -= move;
        if (transform_.position_.y <= 0.0f)
        {
            moveUp = true;
        }
    }

    if (rand() % 100 == 0)
    {
        EnemyBullet* pEnemyBullet = Instantiate<EnemyBullet>(GetParent());
        pEnemyBullet->SetPosition(transform_.position_);
    }
}

//描画
void Enemy::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Bullet")
    {
        pTarget->KillMe();
        nowHp_ = maxHp_ - 10;
    }
}