#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class MiniEnemy : public GameObject
{
    int hMiniEnemy_;
    float move = 0.05f;
    float scaleX = 0.3f;
    float scaleY = 0.3f;
    float scaleZ = 0.3f;
    bool moveUp;

    Transform tMiniEnemy;
public:
    //コンストラクタ
    MiniEnemy(GameObject* parent);

    //デストラクタ
    ~MiniEnemy();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void movePattern();
};