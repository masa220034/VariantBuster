#pragma once
#include "Engine/GameObject.h"

class GameOverScene : public GameObject
{
	int hPict_;
	int hBack_;
	int BGM_;
	int IMB = 0; //I=画像、M=モデル、B=BGM

	unsigned int frameCount;
	unsigned int DelayFrame;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameOverScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};