#include "TutorialScene.h"
#include "TutorialEnemy.h"

//コンストラクタ
TutorialScene::TutorialScene(GameObject* parent)
	: GameObject(parent, "TutorialScene")
{
}

//初期化
void TutorialScene::Initialize()
{
	Instantiate<TutorialEnemy>(this);
	Instantiate<
}

//更新
void TutorialScene::Update()
{
}

//描画
void TutorialScene::Draw()
{
}

//開放
void TutorialScene::Release()
{
}
