#include "Enemy.h"
#include "Bullet.h"
#include "EnemyGauge.h"
#include "EnemyBullet.h"
#include "EnemyBullet2.h"
#include "DamageEffect.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), hEnemy_(-1), DamegeSound_(-1), DeathSound_(-1),
    frameCount(0), DelayFrame(150),
    maxHp_(200), nowHp_(0), halfHp_(100),
    isDamage(false), d_Amount(0), d_Step(0.1f),
    pKey_(nullptr), isKey_(false)
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
    DeathSound_ = Audio::Load("DeathSound.wav");
    assert(DamegeSound_ >= 0);
    assert(DeathSound_ >= 0);

    tEnemy.position_ = ENEMY_POS;
    tEnemy.scale_ = ENEMY_SCL;

    SphereCollider* collision = new SphereCollider(BASE_POS, c_scale);
    AddCollider(collision);

    moveUp = true;
}

//更新
void Enemy::Update()
{
    if (frameCount >= DelayFrame)
    {
        if (!mt)
        {
            EFFEKSEERLIB::gEfk->AddEffect("MASPA", "Maspa.efk");
            EFFEKSEERLIB::EFKTransform t;
            DirectX::XMStoreFloat4x4(&(t.matrix), transform_.GetWorldMatrix());
            t.isLoop = false;  //繰り返しON
            t.maxFrame = 700; //エフェクシアのフレーム
            t.speed = 1.0;    //スピード
            mt = EFFEKSEERLIB::gEfk->Play("MASPA", t);
        }

        AttackPattern();

        XMMATRIX tr = XMMatrixTranslation(-3.0, 2.9, 0.5);
        XMMATRIX rt = XMMatrixRotationY(XM_PI);
        DirectX::XMStoreFloat4x4(&(mt->matrix), rt * tr * this->GetWorldMatrix());
    }
    else
    {
        frameCount++;

        //始まった時、HPゲージ上昇
        if (!isHpmax)
        {
            nowHp_ += upHp_;
            if (nowHp_ >= maxHp_)
            {
                nowHp_ = maxHp_;
                isHpmax = true;
            }
        }
    }

    //ダメージを受けたときのHPゲージの減少速度
    if (isDamage)
    {
        nowHp_ -= d_Step;
        if (nowHp_ <= targetHp)
        {
            nowHp_ = targetHp;
            isDamage = false;
        }
    }

    if (nowHp_ <= noHp_)
    {
        if (!isKey_)
        {
            pKey_ = Instantiate<Key>(GetParent());
            pKey_->SetPosition(tEnemy.position_);
            isKey_ = true;
        }

        Audio::Play(DeathSound_);

        EFFEKSEERLIB::gEfk->AddEffect("DEATH", "Death.efk");
        EFFEKSEERLIB::EFKTransform t;
        DirectX::XMStoreFloat4x4(&(t.matrix), transform_.GetWorldMatrix());
        t.isLoop = false;  //繰り返しON
        t.maxFrame = 120; //エフェクシアのフレーム
        t.speed = 1.0;    //スピード
        mt = EFFEKSEERLIB::gEfk->Play("DEATH", t);

        KillMe();
    }

    EnemyGauge* pEnemyGauge = (EnemyGauge*)FindObject("EnemyGauge");
    pEnemyGauge->SetHp(nowHp_, maxHp_);

    movePattern();

    transform_ = tEnemy;
}

//描画
void Enemy::Draw()
{
    Model::SetTransform(hEnemy_, tEnemy);
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
        StartDamage(B_damage);

        Audio::Play(DamegeSound_);

        DamageEffect* damageEffect = new DamageEffect(GetParent(), tEnemy.position_);
        damageEffect->Initialize();

        pTarget->KillMe();
    }
}

void Enemy::AttackPattern()
{
    if(nowHp_ > halfHp_ && nowHp_ <= maxHp_) 
    {
        if (rand() % 100 == 0)
        {
            EnemyBullet* pEnemyBullet = Instantiate<EnemyBullet>(GetParent());
            pEnemyBullet->SetPosition(tEnemy.position_);
        }
    }

    if (nowHp_ <= halfHp_)
    {
        tEnemy.position_.x -= ene_move;
        if (tEnemy.position_.x <= lim_ene_pos)
        {
            tEnemy.position_.x = lim_ene_pos;
            tEnemy.rotate_.y -= ene_rotate;

            if (rand() % 100 == 0)
            {
                EnemyBullet2* pEnemyBullet2 = Instantiate<EnemyBullet2>(GetParent());
                pEnemyBullet2->SetPosition(tEnemy.position_);
            }
        }
    }
}

void Enemy::movePattern()
{
    if (moveUp)
    {
        tEnemy.position_.y += move;
        if (tEnemy.position_.y >= moveUp_lim)
        {
            moveUp = false;
        }
    }
    else
    {
        tEnemy.position_.y -= move;
        if (tEnemy.position_.y <= moveDown_lim)
        {
            moveUp = true;
        }
    }
}

void Enemy::StartDamage(float amount)
{
    targetHp = nowHp_ - amount;
    if (targetHp < 0)
    {
        targetHp = 0;
    }
    isDamage = true;
}
