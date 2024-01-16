#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Result : public GameObject
{
private:
    int hPict_;
public:
    //コンストラクタ
    Result(GameObject* parent);

    //デストラクタ
    ~Result();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};
