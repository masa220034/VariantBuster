#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Player : public GameObject
{
private:
    int hPlayer_;
    int JumpSound_;
    int DamegeSound_;

    float moveSpeed = 0.1f;

    //-----カメラの位置、視点の初期設定-----
    float cmrPosX = 0.0f;
    float cmrPosY = 3.0f;
    float cmrPosZ = 10.0f;
    float cmrTgtX = 0.0f;
    float cmrTgtY = 2.0f;
    float cmrTgtZ = 0.0f;
    //---------------------------------------
 
    //-----プレイヤーの位置、大きさの初期設定-----
    float posX = -3.0f;
    float posY = 0.0f;
    float posZ = 0.0f;
    float scaleX = 0.2f;
    float scaleY = 0.2f;
    float scaleZ = 0.2f;
    //---------------------------------------------
    
    //-----レイの発射方向-----
    float R_dirX = 0.0f;
    float R_dirY = -1.0f;
    float R_dirZ = 0.0f;
    //------------------------

    //-----ジャンプに使用している変数達-----
    bool isJump = true;      //ジャンプしてるかどうかのフラグ
    float ground_Y = 0.0f;   //地面の位置
    float x = 0.0f;          //経過時間
    float v = 0.4f;          //ジャンプの初速度
    float gravity = 0.02;    //重力加速度
    float fallSpeed = 10.0f; //落ちる速度
    float fPosition = -6.0f; //初期足場から落下後の位置
    //---------------------------------------

    //-----プレイヤーのHP、およびダメージについて-----
    bool isHpmax;
    int nowHp_, maxHp_;
    int upHp_ = 1;
    int noHp_ = 0;
    int e_damage = 2;
    int eb_damege = 4;
    int sec_eb_damege = 8;
    int min_b_damege = 4;
    //-------------------------------------------------

    Transform tPlayer;
public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void OnCollision(GameObject* pTarget) override;
};
