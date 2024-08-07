#include "TutorialEnemy.h"
#include "EnemyGauge.h"
#include "DamageEffect.h"
#include "Engine/Model.h"
#include "Engine/Audio.h"
#include "Engine/SphereCollider.h"

TutorialEnemy::TutorialEnemy(GameObject* parent)
	:GameObject(parent, "TutorialEnemy"), hEnemy_(-1), DamegeSound_(-1), DeathSound_(-1),
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
	assert(hEnemy_ >= IMB);

    DamegeSound_ = Audio::Load("DamegeSound.wav");
    DeathSound_ = Audio::Load("DeathSound.wav");
    assert(DamegeSound_ >= IMB);
    assert(DeathSound_ >= IMB);

	tEnemy.position_ = ENEMY_POS;
	tEnemy.scale_ = ENEMY_SCL;

    SphereCollider* collision = new SphereCollider(BASE_POS, c_scale);
    AddCollider(collision);

	Model::SetAnimFrame(hEnemy_, startAnim, finishAnim, AnimSpeed);
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
        t.maxFrame = EffectFlame;
        t.speed = EffectSpeed;
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

void TutorialEnemy::OnCollision(GameObject* pTarget)
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

void TutorialEnemy::StartDamage(float amount)
{
    targetHp = nowHp_ - amount;
    if (targetHp < noHp_)
    {
        targetHp = noHp_;
    }
    isDamage = true;
}