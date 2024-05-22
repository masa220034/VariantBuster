#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class MiniEnemy : public GameObject
{
    int hMiniEnemy_;

    //-----ミニ敵の位置、大きさの設定-----
    float move = 0.05f;
    float scaleX = 0.3f;
    float scaleY = 0.3f;
    float scaleZ = 0.3f;
    float posX = (float)(rand() % 401 - 200) / 10;
    float posY = 5.8f;
    float posZ = 0.0f;
    //------------------------------------

    float movedPos = 5.5f;
    bool moveUp;

    unsigned int frameCount;
    unsigned int DelayFrame;

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