#pragma once
#include "Key.h"
#include "Engine/GameObject.h"
#include "EffekseeLib/EffekseerVFX.h"

class TutorialEnemy : public GameObject
{
    int hEnemy_;
    int DamegeSound_;
    int DeathSound_;

    //-----敵の位置と大きさの設定-----
    XMFLOAT3 ENEMY_POS = XMFLOAT3(5.0f, 1.5f, 0.0f);
    XMFLOAT3 ENEMY_SCL = XMFLOAT3(0.5f, 0.5f, 0.5f);
    //--------------------------------

    //-----コライダーの中心位置と大きさの設定-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.0f, 0.5f, 0.0f);
    float c_scale = 0.55f;
    //--------------------------------------------

    //-----敵のHPの設定-----
    bool isHpmax;
    int nowHp_, maxHp_;
    int upHp_ = 1;
    int noHp_ = 0;
    //----------------------

    //-----HPゲージの減少関連について-----
    bool isDamage;
    float d_Amount;
    float d_Step;
    float targetHp;
    //------------------------------------

    //-----アニメーションの設定-----
    int startAnim = 1;
    int finishAnim = 60;
    float AnimSpeed = 0.5f;
    //------------------------------

    Key* pKey_;
    bool isKey_;

    int B_damage = 20;
    unsigned int frameCount;
    unsigned int DelayFrame;

    Transform tEnemy;
public:
    //コンストラクタ
    TutorialEnemy(GameObject* parent);

    //デストラクタ
    ~TutorialEnemy();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void OnCollision(GameObject* pTarget);

    void StartDamage(float amount);

    XMFLOAT3 GetPosition() const { return tEnemy.position_; }

    std::shared_ptr<EFFEKSEERLIB::EFKTransform> mt;
};

