#pragma once
#include "Engine/GameObject.h"

//タイトルを管理するクラス
class Title : public GameObject
{
private:
    int hTitleBack_;
    int hTitle_;

    Transform tTitleBack;
    Transform tTitle;
public:
    //コンストラクタ
    Title(GameObject* parent);

    //デストラクタ
    ~Title();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};
