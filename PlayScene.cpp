#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "MiniEnemy.h"
#include "Stage.h"
#include "PlayerGauge.h"
#include "EnemyGauge.h"
#include "Timer.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"), BGM_(-1)
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
	for (int i = 0; i < 2; i++)
	{
		Instantiate<MiniEnemy>(this);
	}
	Instantiate<PlayerGauge>(this);
	Instantiate<EnemyGauge>(this);
	Instantiate<Timer>(this);

	BGM_ = Audio::Load("BattleBGM.wav");
	assert(BGM_ >= 0);
}

//更新
void PlayScene::Update()
{
	Audio::Play(BGM_);
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
