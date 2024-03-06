#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Enemy : public GameObject
{
    int hModel_;
    int nowPt_, maxPt_;
    float move = 0.05f;
    bool moveUp;
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
};
