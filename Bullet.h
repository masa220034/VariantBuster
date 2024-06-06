#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Bullet : public GameObject
{
    int hModel_;
    int BulletSound_;

    //-----弾の大きさ,速さ,撃てる距離の設定-----
    XMFLOAT3 BULLET_SCL = XMFLOAT3(0.3f, 0.3f, 0.3f);
    float v_shot = 0.5f;
    float limitPos = 50.0f;
    //------------------------------------------

    //-----コライダーの中心位置と大きさの設定-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.1f, 0.1f, 0.1f);
    float c_scale = 0.3f;
    //--------------------------------------------

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
