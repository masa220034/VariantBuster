#include "TutorialScene.h"
#include "TutorialPlayer.h"
#include "TutorialEnemy.h"
#include "TutorialGround.h"
#include "PlayerGauge.h"
#include "EnemyGauge.h"
#include "Engine/Image.h"

//コンストラクタ
TutorialScene::TutorialScene(GameObject* parent)
	: GameObject(parent, "TutorialScene"), hBackGorund(-1)
{
}

//初期化
void TutorialScene::Initialize()
{
	hBackGorund = Image::Load("TutorialBackGround.png");
	assert(hBackGorund >= 0);
	transform_.scale_ = XMFLOAT3(0.8f, 0.8f, 0.8f);

	Instantiate<TutorialPlayer>(this);
	Instantiate<TutorialEnemy>(this);
	Instantiate<TutorialGround>(this);
	Instantiate<PlayerGauge>(this);
	Instantiate<EnemyGauge>(this);
}

//更新
void TutorialScene::Update()
{
}

//描画
void TutorialScene::Draw()
{
	Image::SetTransform(hBackGorund, transform_);
	Image::Draw(hBackGorund);
}

//開放
void TutorialScene::Release()
{
}
