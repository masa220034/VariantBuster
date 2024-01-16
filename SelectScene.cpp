#include "SelectScene.h"
#include "Select.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
SelectScene::SelectScene(GameObject* parent)
	: GameObject(parent, "SelectScene")
{
}

//初期化
void SelectScene::Initialize()
{
	Instantiate<Select>(this);
}

//更新
void SelectScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void SelectScene::Draw()
{
}

//開放
void SelectScene::Release()
{
}
