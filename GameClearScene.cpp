#include "GameClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
GameClearScene::GameClearScene(GameObject* parent)
	: GameObject(parent, "GameClearScene"), hBackGround_(-1), hClear_(-1), BGM_(-1),
	frameCount(0), DelayFrame(120), alphaSpeed(0.02f), alphaDir(1)
{
}

//������
void GameClearScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hBackGround_ = Image::Load("GameClearBackGround.png");
	assert(hBackGround_ >= IMB);

	hClear_ = Image::Load("GameClear.png");
	assert(hClear_ >= IMB);

	BGM_ = Audio::Load("GameClearBGM.wav");
	assert(BGM_ >= IMB);

	tClear.position_ = CLEAR_LOGO_POS;
	tClear.scale_ = CLEAR_LOGO_SCL;
	tClear.alpha_ = 1.0f;
}

//�X�V
void GameClearScene::Update()
{
	Audio::Play(BGM_);

	// �A���t�@�l�̑�������
	tClear.alpha_ += alphaDir * alphaSpeed;
	if (tClear.alpha_ >= 1.0f) {
		tClear.alpha_ = 1.0f;
		alphaDir = -1;  // ���������ɕύX
	}
	else if (tClear.alpha_ <= 0.0f) {
		tClear.alpha_ = 0.0f;
		alphaDir = 1;  // ���������ɕύX
	}

	frameCount = (frameCount + 1) % 360;

	/// �g��k���̕ω��i�����j
	float scaleVariation = 0.1f * sinf(static_cast<float>(frameCount) / 20.0f);
	tClear.scale_.x = CLEAR_LOGO_SCL.x + scaleVariation;
	tClear.scale_.y = CLEAR_LOGO_SCL.y + scaleVariation;

	if (frameCount >= DelayFrame)
	{
		if (Input::IsKeyDown(DIK_SPACE))
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_PLAY);
		}

		if (Input::IsKeyDown(DIK_RETURN))
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_SELECT);
		}
	}
	else
	{
		frameCount++;
	}
}

//�`��
void GameClearScene::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);

	Image::SetTransform(hClear_, tClear);
	Image::Draw(hClear_);
}

//�J��
void GameClearScene::Release()
{
}
