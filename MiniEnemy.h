#pragma once
#include "Engine/GameObject.h"

class MiniEnemy : public GameObject
{
    int hMiniEnemy_;
    int IMB = 0; //I=画像、M=モデル、B=BGM

    //-----ミニ敵の位置、大きさの設定-----
    XMFLOAT3 MINIENEMY_POS = XMFLOAT3((float)(rand() % 401 - 200) / 10, 5.8f, 0.0f);
    XMFLOAT3 MINIENEMY_SCL = XMFLOAT3(0.3f, 0.3f, 0.3f);
    //------------------------------------

    //-----敵の行動距離の設定-----
    bool moveUp;
    float move = 0.05f;
    float movedPos = 5.5f;
    //----------------------------
    
    int RANDOM_ATK = 100;
    int TARGET_REMAINDER = 0;

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