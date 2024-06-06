#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class minBullet : public GameObject
{
    int hModel_;

    //-----コライダーの中心位置、大きさの設定-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.0f, 1.8f, 0.0f);
    XMFLOAT3 COLLIDER_SIZE = XMFLOAT3(0.5f, 3.5f, 1.0f);
    //--------------------------------------------

    //-----弾の大きさの設定-----
    XMFLOAT3 BULLET_SCL = XMFLOAT3(0.3f, 0.5f, 0.0f);
    //--------------------------

    float v_shot = 0.3f;
    float limitPosY = -20.0f;
public:
    //コンストラクタ
    minBullet(GameObject* parent);

    //デストラクタ
    ~minBullet();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

