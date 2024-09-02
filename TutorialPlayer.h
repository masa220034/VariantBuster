#pragma once
#include "Engine/GameObject.h"
#include <chrono>

class TutorialPlayer : public GameObject
{
private:
    int hPlayer_;
    int JumpSound_;
    int DamegeSound_;

    int IMB = 0; //I=画像、M=モデル、B=BGM

    float cooldown;
    std::chrono::high_resolution_clock::time_point lastBulletTime;

    //-----プレイヤーの位置、大きさ、向きの設定-----
    XMFLOAT3 PLAYER_POS = XMFLOAT3(-3.0f, 0.0f, 0.0f);
    XMFLOAT3 PLAYER_SCL = XMFLOAT3(0.2f, 0.2f, 0.2f);
    XMFLOAT3 PLAYER_ROT = XMFLOAT3(0.0f, 90.0f, 0.0f);
    //----------------------------------------------

    //-----プレイヤーの移動に関する設定-----
    float moveSpeed = 0.1f;     //移動速度
    float limitLeftPos = -7.3f; //左の限界値
    float limitRightPos = 7.3f; //右の限界値
    //--------------------------------------

     //-----プレイヤーが向いている方向に弾を撃つかどうか-----
    bool P_Right; //右を向いているかどうか
    XMFLOAT3 RIGHT_DIR = XMFLOAT3(1.0f, 0.0f, 0.0f);
    XMFLOAT3 LEFT_DIR = XMFLOAT3(-1.0f, 0.0f, 0.0f);
    //-------------------------------------------------------

    //-----コライダーの中心位置、大きさの設定-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.0f, 0.2f, 0.0f);
    float c_scale = 0.25f;
    //--------------------------------------------

    //-----レイの発射方向-----
    XMFLOAT3 RAY_DIR = XMFLOAT3(0.0f, -1.0f, 0.0f);
    //------------------------

    //-----ジャンプに使用している変数達-----
    bool isJump = true;      //ジャンプしてるかどうか
    float ground_Y = 0.0f;   //地面の位置
    float x = 0.0f;          //上昇量
    float v = 0.4f;          //ジャンプの初速度
    float gravity = 0.02;    //重力加速度
    float fallSpeed = 10.0f; //落ちる速度
    float fPosition = -6.0f; //初期足場から落下後の位置
    //---------------------------------------

    //-----プレイヤーのHPゲージの設定-----
    bool isHpmax;
    int nowHp_, maxHp_;
    int upHp_ = 1;
    int noHp_ = 0;
    int immortality_Hp_ = 1;
    //------------------------------------

    //-----HPゲージの減少関連について-----
    bool isDamage;
    float d_Amount;
    float d_Step;
    float targetHp;
    //------------------------------------

    //-----ダメージ量の設定-----
    int e_damage = 2;
    //--------------------------

    Transform tPlayer;
public:
    //コンストラクタ
    TutorialPlayer(GameObject* parent);

    //デストラクタ
    ~TutorialPlayer();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void OnCollision(GameObject* pTarget) override;

    void StartDamage(float amount);
};

