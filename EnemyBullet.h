#pragma once
#include "Engine/GameObject.h"

class EnemyBullet : public GameObject
{
    int hModel_;
    int eBulletSound_;

    //-----弾の大きさの設定-----
    XMFLOAT3 BULLET_SCL = XMFLOAT3(0.3f, 0.3f, 0.3f);
    //--------------------------

    //-----コライダーの中心位置と大きさの設定-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.0f, 0.1f, 0.1f);
    XMFLOAT3 COLLIDER_SIZE = XMFLOAT3(1.5f, 1.5f, 1.0f);
    //--------------------------------------------

    //-----弾の速度と距離の設定-----
    float v_shot = 0.5f;
    float limitPos = 20.0f;
    //------------------------------

public:
    //コンストラクタ
    EnemyBullet(GameObject* parent);

    //デストラクタ
    ~EnemyBullet();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};