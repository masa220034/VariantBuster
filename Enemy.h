#pragma once
#include "Key.h"
#include "Engine/GameObject.h"
#include "EffekseeLib/EffekseerVFX.h"

class Enemy : public GameObject
{
    int hEnemy_;
    int hMiniEnemy_;
    int DamegeSound_;

    //-----敵の位置、大きさの設定-----
    XMFLOAT3 ENEMY_POS = XMFLOAT3(5.5f, 2.0f, 0.0f);
    XMFLOAT3 ENEMY_SCL = XMFLOAT3(0.3f, 0.3f, 0.3f);
    //--------------------------------

    //-----コライダーの中心位置、大きさの設定-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.0f, 1.0f, 0.0f);
    float c_scale = 1.1f;
    //--------------------------------------------

    //-----敵のHPの設定-----
    bool isHpmax;
    int nowHp_, maxHp_, halfHp_;
    int upHp_ = 2;
    int noHp_ = 0;
    //----------------------

    //-----HPゲージの減少関連について-----
    bool isDamage;
    float d_Amount;
    float d_Step;
    float targetHp;
    //------------------------------------

    //-----敵の動きに関する設定-----
    bool moveUp;
    float move = 0.05f;
    float moveUp_lim = 2.0f;
    float moveDown_lim = 0.0f;
    //------------------------------

    Key* pKey_;
    bool isKey_;

    int B_damage = 20;
    float ene_move = 0.1f;
    float lim_ene_pos = -5.0f;
    float ene_rotate = 180;
    unsigned int frameCount;
    unsigned int DelayFrame;

    Transform tEnemy;
public:
    //コンストラクタ
    Enemy(GameObject* parent);

    //デストラクタ
    ~Enemy();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void OnCollision(GameObject* pTarget) override;

    void AttackPattern();

    void movePattern();

    void StartDamage(float amount);

    XMFLOAT3 GetPosition() const { return tEnemy.position_; }

    std::shared_ptr<EFFEKSEERLIB::EFKTransform> mt;
};
