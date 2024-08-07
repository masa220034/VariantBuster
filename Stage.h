#pragma once
#include "Engine/GameObject.h"

class Stage : public GameObject
{
private:
    int hBackGround_;
    int hGround_;
    int IMB = 0; //I=画像、M=モデル、B=BGM
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