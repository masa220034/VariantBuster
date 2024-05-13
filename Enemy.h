#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Enemy : public GameObject
{
    int hEnemy_;
    int hMiniEnemy_;
    int DamegeSound_;

    unsigned int frameCount;
    unsigned int DelayFrame;
    int nowHp_, maxHp_, halfHp_;
    float move = 0.05f;
    float pos;
    bool moveUp;
    bool isHpmax;

    Transform tEnemy;
    Transform tMiniEnemy;
public:
    //コンストラクタ
    Enemy(GameObject* parent);

    //デストラクタ
    ~Enemy();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void OnCollision(GameObject* pTarget) override;

    void AttackPattern();

    void movePattern();
};
