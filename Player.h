#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Player : public GameObject
{
private:
    int hPlayer_;

    bool isJumping;               //ジャンプしてるかどうか
    float moveSpeed = 0.1f;       //移動速度
    float initialVelocity = 0.4f; //ジャンプの初期速度
    float jumpSpeed = 0.4f;       //垂直方向(Y軸)の速度
    float jumpHeight = 1.0f;      //ジャンプの高さ
    float gravity = 0.02f;        //重力
    float fallSpeed = 10.0f;      //落ちる速度
    float fPosition = -6.0f;      //初期足場から落下後の位置

    int nowPt_, maxPt_;
    Transform tPlayer;
public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void OnCollision(GameObject* pTarget) override;
};
