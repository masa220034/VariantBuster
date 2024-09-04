#include "TutorialPlayer.h"
#include "TutorialGround.h"
#include "Bullet.h"
#include "PlayerGauge.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

TutorialPlayer::TutorialPlayer(GameObject* parent)
    :GameObject(parent, "TutorialPlayer"), hPlayer_(-1),
    JumpSound_(-1), DamegeSound_(-1),
    maxHp_(100), nowHp_(0), targetHp(0),
    isDamage(false), d_Amount(0), d_Step(0.1f),
    cooldown(0.5f), lastBulletTime(std::chrono::high_resolution_clock::now())
{
}

TutorialPlayer::~TutorialPlayer()
{
}

void TutorialPlayer::Initialize()
{
    hPlayer_ = Model::Load("TutorialPlayer.fbx");
    assert(hPlayer_ >= IMB);

    JumpSound_ = Audio::Load("JumpSound.wav");
    DamegeSound_ = Audio::Load("DamegeSound2.wav");
    assert(JumpSound_ >= IMB);
    assert(DamegeSound_ >= IMB);

    tPlayer.position_ = PLAYER_POS;
    tPlayer.scale_ = PLAYER_SCL;
    tPlayer.rotate_ = PLAYER_ROT;

    SphereCollider* collision = new SphereCollider(BASE_POS, c_scale);
    AddCollider(collision);
}

void TutorialPlayer::Update()
{
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = currentTime - lastBulletTime;

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
        nowHp_ = immortality_Hp_;
    }

    PlayerGauge* pPlayerGauge = (PlayerGauge*)FindObject("PlayerGauge");
    pPlayerGauge->SetHp(nowHp_, maxHp_);

    if (isHpmax)
    {
        if (Input::IsKey(DIK_LEFT))
        {
            tPlayer.position_.x -= moveSpeed;
            P_Right = false;
            if (tPlayer.position_.x < limitLeftPos)
            {
                tPlayer.position_.x = limitLeftPos;
            }
        }

        if (Input::IsKey(DIK_RIGHT))
        {
            tPlayer.position_.x += moveSpeed;
            P_Right = true;
            if (tPlayer.position_.x > limitRightPos)
            {
                tPlayer.position_.x = limitRightPos;
            }
        }

        if (Input::IsKeyDown(DIK_SPACE) && elapsed.count() >= cooldown)
        {
            Bullet* pBullet = Instantiate<Bullet>(GetParent());
            pBullet->SetPosition(tPlayer.position_);

            if (P_Right)
            {
                pBullet->SetDirection(RIGHT_DIR);
            }
            else
            {
                pBullet->SetDirection(LEFT_DIR);
            }

            lastBulletTime = currentTime;
        }

        if (isJump)
        {
            tPlayer.position_.y += x;
            x -= gravity;

            if (tPlayer.position_.y <= ground_Y)
            {
                tPlayer.position_.y = ground_Y;
                isJump = false;
            }
        }
        else
        {
            if (Input::IsKeyDown(DIK_UP))
            {
                // ジャンプ開始
                isJump = true;
                x = v;
                Audio::Play(JumpSound_);
            }
        }
    }

    transform_ = tPlayer;
}

void TutorialPlayer::Draw()
{
    Model::SetTransform(hPlayer_, tPlayer);
    Model::Draw(hPlayer_);
}

void TutorialPlayer::Release()
{
}

void TutorialPlayer::OnCollision(GameObject* pTarget) 
{
    if (pTarget->GetObjectName() == "TutorialEnemy")
    {
        StartDamage(e_damage);
    }

    if (pTarget->GetObjectName() == "ClearItem")
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_TUTORIAL_CLEAR);
    }
}

void TutorialPlayer::StartDamage(float amount)
{
    targetHp = nowHp_ - amount;
    if (targetHp < noHp_)
    {
        targetHp = noHp_;
    }
    isDamage = true;
}