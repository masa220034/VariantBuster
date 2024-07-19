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
	int BGM_;
	
	//-----カメラの位置、視点の設定-----
	XMFLOAT3 CAMERA_POS = XMFLOAT3(0.0f, 3.0f, -10.0f);
	XMFLOAT3 CAMERA_TGT = XMFLOAT3(0.0f, 2.0f, 0.0f);
	//--------------------------------------

	//-----背景の大きさの設定-----
	XMFLOAT3 BACKGROUND_SCL = XMFLOAT3(0.8f, 0.8f, 0.8f);
	//----------------------------

	//-----それぞれの画像の位置と大きさの設定-----
	XMFLOAT3 IMAGE_SCL = XMFLOAT3(0.6f, 0.6f, 0.6f);
	XMFLOAT3 IMAGE_EX_ONE_POS = XMFLOAT3(-0.7f, 0.3f, 2.0f);
	XMFLOAT3 IMAGE_EX_TWO_POS = XMFLOAT3(-0.2f, 0.5f, 2.0f);
	XMFLOAT3 IMAGE_EX_TREE_POS = XMFLOAT3(0.7f, 0.3f, 2.0f);
	XMFLOAT3 IMAGE_EX_FOUR_POS = XMFLOAT3(0.2f, 0.0f, 2.0f);
	//--------------------------------------------

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