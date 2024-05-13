#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class EnemyBullet2 : public GameObject
{
    int hModel_;
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
