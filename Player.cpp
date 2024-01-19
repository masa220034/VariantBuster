#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Stage.h"

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
        if (Input::IsKey(DIK_A))
        {
            // ジャンプ開始
            isJumping = true;
            jumpSpeed = initialVelocity;  // 初期速度
        }

        XMFLOAT3 newPosition = tPlayer.position_;

        //移動先に足場があるかどうかをレイキャストで確認
        Stage* pStage = (Stage*)FindObject("Stage");
        int hGroundModel = pStage->GetModelHandle();

        RayCastData data;
        data.start = tPlayer.position_;   //レイの発射位置
        data.dir = XMFLOAT3(0, -1, 0);       //レイの方向
        Model::RayCast(hGroundModel, &data); //レイを発射

        if (data.hit)
        {
            //その分位置を下げる
            tPlayer.position_ = newPosition;
        }
        else
        {
            tPlayer.position_.y -= fallSpeed * gravity;
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