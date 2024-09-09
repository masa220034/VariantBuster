#pragma once
#include "Engine/GameObject.h"

enum ImageID {
	BACKGROUND,
	CLEAR_LOGO,
	LIGHT_LOGO,
	IMAGE_MAX
};

class GameClearScene : public GameObject
{
	int hImage_[IMAGE_MAX];
	//int hBackGround_;
	//int hClearLogo_;
	//int hLight_;
	int BGM_;
	int IMB = 0; //I=画像、M=モデル、B=BGM

	//-----ゲームクリアのロゴの位置、大きさの設定-----
	XMFLOAT3 CLEAR_LOGO_POS = XMFLOAT3(0.0f, 0.5f, 0.0f);
	XMFLOAT3 CLEAR_LOGO_SCL = XMFLOAT3(1.5f, 1.5f, 1.5f);
	//------------------------------------------------

	//-----ロゴの後光の位置、大きさ、透明度の設定-----
	XMFLOAT3 LIGHT_LOGO_POS = XMFLOAT3(-0.02f, 0.35f, 0.0f);
	XMFLOAT3 LIGHT_LOGO_SCL = XMFLOAT3(1.1f, 1.1f, 1.1f);
	//------------------------------------------------

	int alphaDir;
	float alphaSpeed;

	unsigned int frameCount;
	unsigned int DelayFrame;

	//Transform tLight;
	//Transform tClear;
	Transform tImage_[IMAGE_MAX];
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

