#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Ground : public GameObject
{
private:
    int hGround_;

    Transform tGround;
public:
    //コンストラクタ
    Ground(GameObject* parent, const std::string& name, float xPos);

    //デストラクタ
    ~Ground();

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
