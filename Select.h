#pragma once
#include "Engine/GameObject.h"

//セレクトを管理するクラス
class Select : public GameObject
{
private:
    int hSelectBack_;
    int hButton_;
    int hImage_;
    int hSkill_;

    Transform tSelect;
    Transform tSkill;
public:
    //コンストラクタ
    Select(GameObject* parent);

    //デストラクタ
    ~Select();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

