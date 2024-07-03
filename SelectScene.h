#pragma once
#include "Engine/GameObject.h"

enum BossType {
	BOSS_first,
	BOSS_second,
	BOSS_third,
	BOSS_MAX
};

class SelectScene : public GameObject
{
private:
	int hSelectBack_;
	int hSelBoss_[BOSS_MAX];
	int SelectSound_;

	//-----画像の移動量などの設定-----
	int center = 0;
	int limitLeftPos= -2;
	float move = 1.0f;
	//--------------------------------

	//-----画像の大きさの設定-----
	float scaleX = 0.5f;
	float scaleY = 0.5f;
	float scaleZ = 0.5f;
	float scaleUp = 1.5f;
	//----------------------------

	Transform tSelBoss_[BOSS_MAX];
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	SelectScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};