#pragma once
#include "Engine/GameObject.h"

//セレクトシーンを管理するクラス
class SelectScene : public GameObject
{
	int hSelectBack_;
	int hButton_;
	int hImage_;
	int hSkill_;

	Transform tSelect;
	Transform tSkill;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	SelectScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

