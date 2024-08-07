#pragma once
#include "Engine/GameObject.h"

class PlayScene : public GameObject
{
	int BGM_;
	int enemyNum = 2;
	int IMB = 0; //I=画像、M=モデル、B=BGM

	//-----カメラの位置、視点の設定-----
	XMFLOAT3 CAMERA_POS = XMFLOAT3(0.0f, 3.0f, -10.0f);
	XMFLOAT3 CAMERA_TGT = XMFLOAT3(0.0f, 2.0f, 0.0f);
	//--------------------------------------

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};
