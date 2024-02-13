#include "Player.h"
#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hPlayer_(-1)
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
}

//更新
void Player::Update()
{
    if (Input::IsKey(DIK_LEFT))
    {
        tPlayer.position_.x -= moveSpeed;
    }

    if (Input::IsKey(DIK_RIGHT))
    {
        tPlayer.position_.x += moveSpeed;
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
            tPlayer.position_.y = 0.0f;
            isJumping = false;
        }
    }
    else
    {
        if (Input::IsKeyDown(DIK_A))
        {
            if (data.hit)
            {
                // ジャンプ開始
                isJumping = true;
                jumpSpeed = initialVelocity;
            }
        }

        XMFLOAT3 newPosition = tPlayer.position_;

        if (data.hit)
        {
            //足場がある場合、ジャンプした分の位置を下げる
            tPlayer.position_ = newPosition;
        }
        else
        {
            //足場がない場合、プレイヤーの高さを下げる
            tPlayer.position_.y -= fallSpeed * gravity;

            if (tPlayer.position_.y <= fPosition)
            {
                //初期位置に戻す
                tPlayer.position_ = XMFLOAT3(0.0f, 0.0f, 0.0f);
                isJumping = false;
            }
        }
    }

    //カメラがプレイヤーを追従
    Camera::SetPosition(XMFLOAT3(0.0f, (tPlayer.position_.y + 3) / 2, tPlayer.position_.z - 10));
    Camera::SetTarget(XMFLOAT3(0.0f, (tPlayer.position_.y + 2) / 2, tPlayer.position_.z));
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