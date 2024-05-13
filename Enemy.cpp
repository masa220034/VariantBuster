#include "Enemy.h"
#include "EnemyGauge.h"
#include "EnemyBullet.h"
#include "EnemyBullet2.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), hEnemy_(-1), DamegeSound_(-1),
    frameCount(0), DelayFrame(150),
    maxHp_(200), nowHp_(0), halfHp_(100)
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
    hEnemy_ = Model::Load("Enemy.fbx");
    assert(hEnemy_ >= 0);

    DamegeSound_ = Audio::Load("DamegeSound.wav");
    assert(DamegeSound_ >= 0);

    transform_.position_ = XMFLOAT3(5.5f, 2.0f, 0.0f);
    transform_.scale_ = XMFLOAT3(0.3f, 0.3f, 0.3f);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 1.0, 0), 1.1f);
    AddCollider(collision);

    moveUp = true;
}

//更新
void Enemy::Update()
{
    if (frameCount >= DelayFrame)
    {
        AttackPattern();
    }
    else
    {
        frameCount++;

        if (!isHpmax)
        {
            nowHp_ += 2;
            if (nowHp_ >= maxHp_)
            {
                nowHp_ = maxHp_;
                isHpmax = true;
            }
        }
    }

    if (nowHp_ <= 0)
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_GAMECLEAR);
    }

    EnemyGauge* pEnemyGauge = (EnemyGauge*)FindObject("EnemyGauge");
    pEnemyGauge->SetHp(nowHp_, maxHp_);
 
    movePattern();
}

//描画
void Enemy::Draw()
{
    Model::SetTransform(hEnemy_, transform_);
    Model::Draw(hEnemy_);
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
        nowHp_ -= 3;
        Audio::Play(DamegeSound_);
    }
}

void Enemy::AttackPattern()
{
    //球の方向を決める
    XMFLOAT3 dir;

    if(nowHp_ > halfHp_ && nowHp_ <= maxHp_) 
    {
        dir = { -0.5f,0.0f,0.0f };
        if (rand() % 100 == 0)
        {
            EnemyBullet* pEnemyBullet = Instantiate<EnemyBullet>(GetParent());
            pEnemyBullet->SetPosition(transform_.position_);
            pEnemyBullet->setdirection(dir);
        }
    }

    if (nowHp_ <= halfHp_)
    {
        dir = { 0.5f,0.5f,0.0f };

        transform_.position_.x -= 0.1f;
        if (transform_.position_.x <= -5.0f)
        {
            transform_.position_.x = -5.0f;
            transform_.rotate_.y -= 180;

            if (rand() % 100 == 0)
            {
                EnemyBullet2* pEnemyBullet2 = Instantiate<EnemyBullet2>(GetParent());
                pEnemyBullet2->SetPosition(transform_.position_);
            }
        }
    }
}

void Enemy::movePattern()
{
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
}