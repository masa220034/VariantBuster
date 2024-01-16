#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
//#include "Engine/SphereCollider.h"

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

    //SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.1, 0), 1.2f);
    //AddCollider(collision);

    tPlayer.scale_ = XMFLOAT3(0.2f, 0.2f, 0.2f);
}

//更新
void Player::Update()
{
    if (Input::IsKey(DIK_LEFT))
    {
        tPlayer.position_.x -= 0.1f;
    }

    if (Input::IsKey(DIK_RIGHT))
    {
        tPlayer.position_.x += 0.1f;
    }

    if (Input::IsKey(DIK_A))
    {
        tPlayer.position_.y += jumpSpeed;
    }
    else if (tPlayer.position_.y >= jumpHeight)
    {
        tPlayer.position_.y -= gravity;   
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