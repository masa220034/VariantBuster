#pragma once
#include "Engine/GameObject.h"

class GameClearScene : public GameObject
{
	int hBackGround_;
	int hPict_;
	int BGM_;

	//-----ゲームクリアのロゴの位置、大きさの設定-----
	float posX = 0.0f;
	float posY = 0.5f;
	float posZ = 0.0f;
	float scaleX = 1.5f;
	float scaleY = 1.5f;
	float scaleZ = 1.5f;
	//------------------------------------------------

	unsigned int frameCount;
	unsigned int DelayFrame;

	Transform tClear;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameClearScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

