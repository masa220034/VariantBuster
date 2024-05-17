#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class minBullet : public GameObject
{
    int hModel_;

    //-----コライダーの中心位置、大きさの設定-----
    float basePosX = 0.0f;
    float basePosY = 1.8f;
    float basePosZ = 0.0f;
    float c_sizeX = 0.5f;
    float c_sizeY = 3.5f;
    float c_sizeZ = 1.0f;
    //--------------------------------------------

    //-----弾の大きさの設定-----
    float scaleX = 0.3f;
    float scaleY = 0.5f;
    float scaleZ = 0.0f;
    //--------------------------

    float v_shot = 0.3f;
    float limitPosY = -20.0f;
    Transform m_Bullet;
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

