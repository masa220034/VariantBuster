#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Player : public GameObject
{
private:
    int hPlayer_;
    int JumpSound_;
    int DamegeSound_;

    bool isJump = true;
    float moveSpeed = 0.1f;
    float ground_Y = 0.0f;
    float x = 0.0f;
    float v = 0.4f;
    float gravity = 0.02;
    float fallSpeed = 10.0f;      //落ちる速度
    float fPosition = -6.0f;      //初期足場から落下後の位置

    int nowHp_, maxHp_;
    bool isHpmax;
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
