#include "GameOverScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
GameOverScene::GameOverScene(GameObject* parent)
	: GameObject(parent, "GameOverScene"), hPict_(-1), hBack_(-1), BGM_(-1),
	frameCount(0), DelayFrame(180)
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
		if (Input::IsKeyDown(DIK_SPACE))
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_PLAY);
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
}

//�J��
void GameOverScene::Release()
{
}

