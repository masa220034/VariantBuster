#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Ground.h"

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
            // ジャンプ開始
            isJumping = true;
            jumpSpeed = initialVelocity;  
        }

        XMFLOAT3 newPosition = tPlayer.position_;

        //移動先に足場があるかどうかをレイキャストで確認
        Ground* pGround = (Ground*)FindObject("Ground");
        int hGroundModel = pGround->GetModelHandle();

        RayCastData data;
        data.start = tPlayer.position_;   //レイの発射位置
        data.dir = XMFLOAT3(0, -1, 0);       //レイの方向
        Model::RayCast(hGroundModel, &data); //レイを発射

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
            }
        }
    }
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