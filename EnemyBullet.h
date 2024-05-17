#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class EnemyBullet : public GameObject
{
    int hModel_;
    int eBulletSound_;

    //-----弾の大きさの設定-----
    float scaleX = 0.3f;
    float scaleY = 0.3f;
    float scaleZ = 0.3f;
    //--------------------------

    //-----コライダーの中心位置と大きさの設定-----
    float basePosX = 0.0f;
    float basePosY = 0.1f;
    float basePosZ = 0.1f;
    float c_sizeX = 1.5f;
    float c_sizeY = 1.5f;
    float c_sizeZ = 1.0f;
    //--------------------------------------------

    float v_shot = 0.5f;
    float limitPos = 20.0f;
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