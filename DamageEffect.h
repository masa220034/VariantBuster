#pragma once
#include "Engine/GameObject.h"

class DamageEffect : public GameObject
{
	int hModel_;

	//-----エフェクトの詳細について-----
	XMFLOAT3 position_;
	int DELAY = 0;
	int NUMBER = 80;
	int LIFE_TIME = 30;
	XMFLOAT3 DIRECTION = XMFLOAT3(0, 1, 0);
	XMFLOAT3 DIRECTION_RND = XMFLOAT3(90, 90, 90);
	float SPEED = 0.1f;
	float SPEED_RND = 0.8f;
	XMFLOAT2 SIZE = XMFLOAT2(0.6, 0.6);
	XMFLOAT2 SIZE_RND = XMFLOAT2(0.2, 0.2);
	XMFLOAT2 SCALE = XMFLOAT2(1.05, 1.05);
	XMFLOAT4 COLOR = XMFLOAT4(1.0, 0.0, 1.0, 0.7);
	XMFLOAT4 DELTA_COLOR = XMFLOAT4(0, 0, 0, -0.003);
	//------------------------------------

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	DamageEffect(GameObject* parent, const XMFLOAT3& position);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

