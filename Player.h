#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Player : public GameObject
{
private:
    int hPlayer_;

    float jumpSpeed = 0.5f; 
    float jumpHeight = 0.5f;
    float gravity = 0.5;
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
