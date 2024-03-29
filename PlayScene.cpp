#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Stage.h"
#include "PlayerGauge.h"
#include "EnemyGauge.h"
#include "Timer.h"
#include "Engine/Input.h"


//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
	Instantiate<EnemyBullet>(this);
	Instantiate<PlayerGauge>(this);
	Instantiate<EnemyGauge>(this);
	Instantiate<Timer>(this);
}

//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
