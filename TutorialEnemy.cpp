#include "TutorialEnemy.h"
#include "EnemyGauge.h"
#include "Engine/Model.h"
#include "Engine/Audio.h"
#include "Engine/SphereCollider.h"

TutorialEnemy::TutorialEnemy(GameObject* parent)
	:GameObject(parent, "TutorialEnemy"), hEnemy_(-1), DeathSound_(-1),
    frameCount(0), DelayFrame(150),
	maxHp_(100), nowHp_(0),
    isDamage(false), d_Amount(0), d_Step(0.1f),
    pKey_(nullptr), isKey_(false)
{
}

TutorialEnemy::~TutorialEnemy()
{
}

void TutorialEnemy::Initialize()
{
	hEnemy_ = Model::Load("TutorialEnemy.fbx");
	assert(hEnemy_ >= 0);

    DeathSound_ = Audio::Load("DeathSound.wav");
    assert(DeathSound_ >= 0);

	tEnemy.position_ = XMFLOAT3(5, -1, 0);
	tEnemy.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);

    SphereCollider* collision = new SphereCollider(BASE_POS, c_scale);
    AddCollider(collision);

	Model::SetAnimFrame(hEnemy_, 1, 60, 0.5);
}

void TutorialEnemy::Update()
{
    if (frameCount >= DelayFrame)
    {
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

    transform_ = tEnemy;
}

void TutorialEnemy::Draw()
{
	Model::SetTransform(hEnemy_, tEnemy);
	Model::Draw(hEnemy_);
}

void TutorialEnemy::Release()
{
}

void TutorialEnemy::StartDamage(float amount)
{
    targetHp = nowHp_ - amount;
    if (targetHp < 0)
    {
        targetHp = 0;
    }
    isDamage = true;
}