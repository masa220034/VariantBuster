#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class EnemyBullet2 : public GameObject
{
    int hModel_;

    //-----弾の大きさの設定-----
    float scaleX = 0.3f;
    float scaleY = 0.3f;
    float scaleZ = 0.3f;
    //--------------------------

    //-----コライダーの中心位置、大きさの設定-----
    float basePosX = 0.0;
    float basePosY = 0.3;
    float basePosZ = 0.0;
    float c_scale = 0.35f;
    //--------------------------------------------

    float v_shot = 0.5f;
    float limitPos = 20.0f;
    bool shot;
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
