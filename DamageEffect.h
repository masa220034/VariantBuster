#pragma once
#include "Engine/GameObject.h"

class DamageEffect : public GameObject
{
	int hModel_;
	XMFLOAT3 position_;
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

