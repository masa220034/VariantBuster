#pragma once
#include "Engine/GameObject.h"

class EnemyBullet2 : public GameObject
{
    int hModel_;

    //-----弾の大きさの設定-----
    XMFLOAT3 BULLET_SCL = XMFLOAT3(0.3f, 0.3f, 0.3f);
    //--------------------------

    //-----コライダーの中心位置、大きさの設定-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.0f, 0.3f, 0.0f);
    float c_scale = 0.35f;
    //--------------------------------------------

    float v_shot = 0.5f;
    float limitPos = 20.0f;
public:
    //コンストラクタ
    EnemyBullet2(GameObject* parent);

    //デストラクタ
    ~EnemyBullet2();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};
