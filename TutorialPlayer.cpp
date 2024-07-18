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
    assert(hPlayer_ >= 0);

    JumpSound_ = Audio::Load("JumpSound.wav");
    DamegeSound_ = Audio::Load("DamegeSound2.wav");
    assert(JumpSound_ >= 0);
    assert(DamegeSound_ >= 0);

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
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
    }

    PlayerGauge* pPlayerGauge = (PlayerGauge*)FindObject("PlayerGauge");
    pPlayerGauge->SetHp(nowHp_, maxHp_);

    if (isHpmax)
    {
        if (Input::IsKey(DIK_LEFT))
        {
            tPlayer.position_.x -= moveSpeed;
            P_Right = false;
        }

        if (Input::IsKey(DIK_RIGHT))
        {
            tPlayer.position_.x += moveSpeed;
            P_Right = true;
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

        //移動先に足場があるかどうかをレイキャストで確認
        TutorialGround* pTutorialGround = (TutorialGround*)FindObject("TutorialGround");
        int hGroundModel = pTutorialGround->GetModelHandle();

        RayCastData data;
        data.start = tPlayer.position_;   //レイの発射位置
        data.dir = RAY_DIR;       //レイの方向
        Model::RayCast(hGroundModel, &data);

        if (isJump)
        {

            tPlayer.position_.y += x;
            x -= gravity;

            if (tPlayer.position_.y <= ground_Y)
            {
                if (data.hit)
                {
                    //足場がある場合、ジャンプした分の位置を下げる
                    tPlayer.position_.y = ground_Y;
                }
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

            if (!data.hit)
            {
                //足場がない場合、プレイヤーの高さを下げる
                tPlayer.position_.y -= fallSpeed * gravity;

                if (tPlayer.position_.y <= fPosition)
                {
                    SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
                    pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
                }
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

    if (pTarget->GetObjectName() == "Key")
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_GAMECLEAR);
    }
}

void TutorialPlayer::StartDamage(float amount)
{
    targetHp = nowHp_ - amount;
    if (targetHp < 0)
    {
        targetHp = 0;
    }
    isDamage = true;
}