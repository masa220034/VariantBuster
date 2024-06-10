#include "GameOverScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"
#include "Engine/UI.h"


//�R���X�g���N�^
GameOverScene::GameOverScene(GameObject* parent)
	: GameObject(parent, "GameOverScene"), hPict_(-1), hBack_(-1), BGM_(-1),
	frameCount(0), DelayFrame(120), isOptionWindowOpen(false), selectOption(0)
{
}

//������
void GameOverScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("GameOver.png");
	assert(hPict_ >= 0);

	hBack_ = Image::Load("GameOverBackGround.png");
	assert(hPict_ >= 0);

	BGM_ = Audio::Load("GameOverBGM.wav");
	assert(BGM_ >= 0);
}

//�X�V
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

//�`��
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

//�J��
void GameOverScene::Release()
{
}

void GameOverScene::DrawOptionWindow()
{
	UI::DrawRectangle(100, 100, 300, 200, Color::Black);

	const char* options[] = { "������x�V��", "�I����ʂɖ߂�", "�^�C�g���ɖ߂�" };
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

