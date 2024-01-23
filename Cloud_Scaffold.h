#pragma once
#include "Engine/GameObject.h"

//プレイヤーを管理するクラス
class Cloud_Scaffold : public GameObject
{
private:
    int hCloud_Scaff_;

    Transform tCloud;
public:
    //コンストラクタ
    Cloud_Scaffold(GameObject* parent);

    //デストラクタ
    ~Cloud_Scaffold();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    int GetModelHandle() { return hCloud_Scaff_; }
};