#pragma once
#include "Engine/GameObject.h"

//タイトルシーンを管理するクラス
class TitleScene : public GameObject
{
	int hTitleBack_;
	int hTitle_;
	int BGM_;

	//-----タイトル名の位置、大きさの設定-----
	float titlePos = 0.3f;
	float scaleX = 1.3f;
	float scaleY = 1.3f;
	float scaleZ = 1.3f;
	//----------------------------------------

	Transform tTitleBack;
	Transform tTitle;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TitleScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};


