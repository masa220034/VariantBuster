#pragma once
#include "Engine/GameObject.h"

enum ExType {
	EX_ONE,
	EX_TWO,
	EX_TREE,
	EX_FOUR,
	EX_MAX
};

class TutorialScene : public GameObject
{
	int hBackGorund;
	int hImage_[EX_MAX];
	
	//-----カメラの位置、視点の設定-----
	XMFLOAT3 CAMERA_POS = XMFLOAT3(0.0f, 3.0f, -10.0f);
	XMFLOAT3 CAMERA_TGT = XMFLOAT3(0.0f, 2.0f, 0.0f);
	//--------------------------------------

	Transform tBackGround;
	Transform tImage_[EX_MAX];
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TutorialScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};