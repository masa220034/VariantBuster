#include "Player.h"
#include "Stage.h"
#include "Bullet.h"
#include "PlayerGauge.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hPlayer_(-1),
    JumpSound_(-1), DamegeSound_(-1),
    maxHp_(100), nowHp_(0), targetHp(0),
    isDamage(false), d_Amount(0), d_Step(0.1f),
    cooldown(0.5f), lastBulletTime(std::chrono::high_resolution_clock::now())
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
    hPlayer_ = Model::Load("Player.fbx");
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

//更新
void Player::Update()
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
        Stage* pStage = (Stage*)FindObject("Stage");
        int hGroundModel = pStage->GetModelHandle();

        RayCastData data;
        data.start = tPlayer.position_; //レイの発射位置
        data.dir = RAY_DIR; //レイの方向
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

//描画
void Player::Draw()
{
    Model::SetTransform(hPlayer_, tPlayer);
    Model::Draw(hPlayer_);
}

//開放
void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Enemy")
    {
        StartDamage(e_damage);
    }

    if (pTarget->GetObjectName() == "EnemyBullet")
    {
        pTarget->KillMe();
        StartDamage(eb_damage);
        Audio::Play(DamegeSound_);
    }

    if (pTarget->GetObjectName() == "EnemyBullet2")
    {
        pTarget->KillMe();
        StartDamage(sec_eb_damage);
    }

    if (pTarget->GetObjectName() == "minBullet")
    {
        pTarget->KillMe();
        StartDamage(min_b_damage);
    }

    if (pTarget->GetObjectName() == "Key")
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_GAMECLEAR);
    }
}

void Player::StartDamage(float amount)
{
    targetHp = nowHp_ - amount;
    if (targetHp < noHp_)
    {
        targetHp = noHp_;
    }
    isDamage = true;
}
