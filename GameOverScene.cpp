#include "GameOverScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"
#include "Engine/UI.h"


//コンストラクタ
GameOverScene::GameOverScene(GameObject* parent)
	: GameObject(parent, "GameOverScene"), hPict_(-1), hBack_(-1), BGM_(-1),
	frameCount(0), DelayFrame(120), isOptionWindowOpen(false), selectOption(0)
{
}

//初期化
void GameOverScene::Initialize()
{
	//画像データのロード
	hPict_ = Image::Load("GameOver.png");
	assert(hPict_ >= 0);

	hBack_ = Image::Load("GameOverBackGround.png");
	assert(hPict_ >= 0);

	BGM_ = Audio::Load("GameOverBGM.wav");
	assert(BGM_ >= 0);
}

//更新
void GameOverScene::Update()
{
	Audio::Play(BGM_);

	if (frameCount >= DelayFrame)
	{
		if (isOptionWindowOpen)
		{
			if (Input::IsKeyDown(DIK_UP))
			{
				selectOption = (selectOption + 2) % 3;
			}
			if (Input::IsKeyDown(DIK_DOWN))
			{
				selectOption = (selectOption + 1) % 3;
			}
			if (Input::IsKeyDown(DIK_SPACE))
			{
				SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
				switch (selectOption)
				{
				case 0:
					pSceneManager->ChangeScene(SCENE_ID_PLAY);
					break;
				case 1:
					pSceneManager->ChangeScene(SCENE_ID_SELECT);
					break;
				case 2:
					pSceneManager->ChangeScene(SCENE_ID_TITLE);
					break;
				}
			}
		}
		else
		{
			if (Input::IsKeyDown(DIK_SPACE))
			{
				isOptionWindowOpen = true;
			}
		}
	}
	else
	{
		frameCount++;
	}
}

//描画
void GameOverScene::Draw()
{
	Image::SetTransform(hBack_, transform_);
	Image::Draw(hBack_);

	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

	if (isOptionWindowOpen)
	{
		DrawOptionWindow();
	}
}

//開放
void GameOverScene::Release()
{
}

void GameOverScene::DrawOptionWindow()
{
	UI::DrawRectangle(100, 100, 300, 200, Color::Black);

	const char* options[] = { "もう一度遊ぶ", "選択画面に戻る", "タイトルに戻る" };
	for (int i = 0; i < 3; ++i)
	{
		if (i == selectOption)
		{
			UI::DrawText(options[i], 120, 120 + i * 30, Color::Red);
		}
		else
		{
			UI::DrawText(options[i], 120, 120 + i * 30, Color::White);
		}
	}
}

