#include "TutorialClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"

TutorialClearScene::TutorialClearScene(GameObject* parent)
	: GameObject(parent, "GameClearScene"), hBackGround_(-1), BGM_(-1),
	frameCount(0), DelayFrame(120)
{
}

void TutorialClearScene::Initialize()
{
	//画像データのロード
	hBackGround_ = Image::Load("TutorialClearBackGround.png");
	assert(hBackGround_ >= IMB);

	BGM_ = Audio::Load("GameClearBGM.wav");
	assert(BGM_ >= IMB);
}

void TutorialClearScene::Update()
{
	Audio::Play(BGM_);

	if (frameCount >= DelayFrame)
	{
		if (Input::IsKeyDown(DIK_SPACE))
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_SELECT);
		}
		else if (Input::IsKeyDown(DIK_RETURN))
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_TUTORIAL);
		}
	}
	else
	{
		frameCount++;
	}
}

void TutorialClearScene::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);
}

//開放
void TutorialClearScene::Release()
{
}
