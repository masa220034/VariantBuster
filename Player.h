#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Player : public GameObject
{
private:
    int hPlayer_;

    bool isJumping;
    float jumpSpeed = 0.4f; 
    float jumpHeight = 1.0f;
    float gravity = 0.02f;
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
};
