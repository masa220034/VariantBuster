#pragma once
#include "Engine/GameObject.h"

class TutorialClearScene : public GameObject
{
	int hBackGround_;
	int BGM_;
	int IMB = 0; //I=画像、M=モデル、B=BGM

	unsigned int frameCount;
	unsigned int DelayFrame;

	Transform tClear;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TutorialClearScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};