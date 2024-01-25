#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Ground.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Ground>(this);
	Instantiate<Player>(this);
}

//更新
void PlayScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_RESULT);
	}
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
