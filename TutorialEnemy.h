#pragma once
#include "Engine/GameObject.h"

class TutorialEnemy : public GameObject
{
    int hEnemy_;

    Transform tEnemy;
public:
    //コンストラクタ
    TutorialEnemy(GameObject* parent);

    //デストラクタ
    ~TutorialEnemy();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

