#include "Player.h"
#include "Stage.h"
#include "Bullet.h"
#include "PlayerGauge.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hPlayer_(-1),
    maxHp_(100), nowHp_(0)
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
    Camera::SetPosition(XMFLOAT3(0, 3, -10));
    Camera::SetTarget(XMFLOAT3(0, 2, 0));

    hPlayer_ = Model::Load("Player.fbx");
    assert(hPlayer_ >= 0);

    tPlayer.scale_ = XMFLOAT3(0.2f, 0.2f, 0.2f);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0.0, 0.2, 0.0), 0.25f);
    AddCollider(collision);
}

//更新
void Player::Update()
{
    if (!isHpmax)
    {
        nowHp_ += 1;
        if (nowHp_ >= maxHp_)
        {
            nowHp_ = maxHp_;
            isHpmax = true;
        }
    }

    //if (nowHp_ <= 0)
    //{
    //    SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
    //    pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
    //}

    PlayerGauge* pPlayerGauge = (PlayerGauge*)FindObject("PlayerGauge");
    pPlayerGauge->SetHp(nowHp_, maxHp_);

    if (Input::IsKey(DIK_LEFT))
    {
        tPlayer.position_.x -= moveSpeed;
    }

    if (Input::IsKey(DIK_RIGHT))
    {
        tPlayer.position_.x += moveSpeed;
    }

    if (Input::IsKeyDown(DIK_D))
    {
        Bullet* pBullet = Instantiate<Bullet>(GetParent());
        pBullet->SetPosition(tPlayer.position_);
    }

    //移動先に足場があるかどうかをレイキャストで確認
    Stage* pStage = (Stage*)FindObject("Stage");
    int hGroundModel = pStage->GetModelHandle();

    RayCastData data;
    data.start = tPlayer.position_;   //レイの発射位置
    data.dir = XMFLOAT3(0, -1, 0);       //レイの方向
    Model::RayCast(hGroundModel, &data); //レイを発射

    if (isJumping)
    {
        tPlayer.position_.y += jumpSpeed;
        jumpSpeed -= gravity;

        if (tPlayer.position_.y <= 0.0f)
        {
            if (data.hit)
            {
                //足場がある場合、ジャンプした分の位置を下げる
                tPlayer.position_.y -= data.dist;
                tPlayer.position_.y = 0.0f;
            }
            isJumping = false;
        }
    }
    else
    {
        if (Input::IsKeyDown(DIK_A))
        {
            // ジャンプ開始
            isJumping = true;
            jumpSpeed = initialVelocity;
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

    //カメラがプレイヤーを追従
    Camera::SetPosition(XMFLOAT3(0.0f, (tPlayer.position_.y + 3) / 2, tPlayer.position_.z - 10));
    Camera::SetTarget(XMFLOAT3(0.0f, (tPlayer.position_.y + 2) / 2, tPlayer.position_.z));

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
    if (pTarget->GetObjectName() == "EnemyBullet")
    {
        pTarget->KillMe();
        nowHp_ -= 20;
    }
}
