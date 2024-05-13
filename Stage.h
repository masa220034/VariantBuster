#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Stage : public GameObject
{
private:
    int hBackGround_;
    int hGround_;

public:
    //コンストラクタ
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    int GetModelHandle() { return hGround_; }
};