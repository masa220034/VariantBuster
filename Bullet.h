#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Bullet : public GameObject
{
    int hModel_;
    int BulletSound_;

    //-----弾の大きさと速さの設定-----
    float scaleX = 0.3f;
    float scaleY = 0.3f;
    float scaleZ = 0.3f;
    float v_shot = 0.5f;
    //--------------------------

    //-----コライダーの中心位置と大きさの設定-----
    float basePosX = 0.1f;
    float basePosY = 0.1f;
    float basePosZ = 0.1f;
    float c_scale = 0.3f;
    //--------------------------------------------

    float limitPos = 50.0f;

    XMFLOAT3 direction_;
public:
    //コンストラクタ
    Bullet(GameObject* parent);

    //デストラクタ
    ~Bullet();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetDirection(const XMFLOAT3& direction);
};
