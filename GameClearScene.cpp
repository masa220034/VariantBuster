#include "GameClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
GameClearScene::GameClearScene(GameObject* parent)
	: GameObject(parent, "GameClearScene"), hImage_{ 0, 1, 2 }, BGM_(-1),
	frameCount(0), DelayFrame(120), alphaSpeed(0.02f), alphaDir(1)
{
}

//������
void GameClearScene::Initialize()
{
	/*�摜�f�[�^�̃��[�h
	hBackGround_ = Image::Load("GameClearBackGround.png");
	assert(hBackGround_ >= IMB);

	hClearLogo_ = Image::Load("GameClear.png");
	assert(hClearLogo_ >= IMB);

	hLight_ = Image::Load("EffectLight.png");
	assert(hLight_ >= IMB);
	*/

	const char* ImageNames[IMAGE_MAX] = { "GameClearBackGround.png", "GameClear.png", "EffectLight.png" };
	for (int i = 0; i < IMAGE_MAX; i++)
	{
		hImage_[i] = Image::Load(ImageNames[i]);
		assert(hImage_[i] > IMB);

		switch (i)
		{
		case BACKGROUND:
			break;
		case CLEAR_LOGO:
			tImage_[i].position_ = CLEAR_LOGO_POS;
			tImage_[i].scale_ = CLEAR_LOGO_SCL;
			break;
		case LIGHT_LOGO:
			tImage_[i].position_ = LIGHT_LOGO_POS;
			tImage_[i].scale_ = LIGHT_LOGO_SCL;
			tImage_[i].alpha_ = 1.0f;
			break;
		}
	}

	BGM_ = Audio::Load("GameClearBGM.wav");
	assert(BGM_ >= IMB);

	/*tClear.position_ = CLEAR_LOGO_POS;
	tClear.scale_ = CLEAR_LOGO_SCL;

	tLight.position_ = LIGHT_LOGO_POS;
	tLight.scale_ = LIGHT_LOGO_SCL;
	tLight.alpha_ = 1.0f;
	*/
}

//�X�V
void GameClearScene::Update()
{
	Audio::Play(BGM_);

	/*
	// �A���t�@�l�̑�������
	tLight.alpha_ += alphaDir * alphaSpeed;
	if (tLight.alpha_ >= 1.0f) {
		tLight.alpha_ = 1.0f;
		alphaDir = -1;  // ���������ɕύX
	}
	else if (tLight.alpha_ <= 0.0f) {
		tLight.alpha_ = 0.0f;
		alphaDir = 1;  // ���������ɕύX
	}

	frameCount = (frameCount + 1) % 360;

	/// �g��k���̕ω��i�����j
	float scaleVariation = 0.1f * sinf(static_cast<float>(frameCount) / 20.0f);
	tLight.scale_.x = CLEAR_LOGO_SCL.x + scaleVariation;
	tLight.scale_.y = CLEAR_LOGO_SCL.y + scaleVariation;
	*/

	for (int i = 0; i < IMAGE_MAX; i++)
	{
		switch (i)
		{
		case BACKGROUND:
			break;
		case CLEAR_LOGO:
			break;
		case LIGHT_LOGO:
			// �G�t�F�N�g���C�g�̏����i��F�A���t�@�l��ω�������j
			tImage_[i].alpha_ += alphaDir * alphaSpeed;
			if (tImage_[i].alpha_ >= 1.0f) {
				tImage_[i].alpha_ = 1.0f;
				alphaDir = -1;  // ���������ɕύX
			}
			else if (tImage_[i].alpha_ <= 0.0f) {
				tImage_[i].alpha_ = 0.0f;
				alphaDir = 1;  // ���������ɕύX
			}

			// �g��k���̕ω��i�����j
			float scaleVariation = 0.1f * sinf(static_cast<float>(frameCount) / 20.0f);
			tImage_[i].scale_.x = CLEAR_LOGO_SCL.x + scaleVariation;
			tImage_[i].scale_.y = CLEAR_LOGO_SCL.y + scaleVariation;

			break;
		}
	}

	// �t���[���J�E���g�̍X�V
	frameCount = (frameCount + 1) % 360;


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
	/*Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);

	Image::SetTransform(hLight_, tLight);
	Image::Draw(hLight_);

	Image::SetTransform(hClearLogo_, tClear);
	Image::Draw(hClearLogo_);
	*/

	for (int i = 0; i < IMAGE_MAX; i++)
	{
		Image::SetTransform(hImage_[i], tImage_[i]);
		Image::Draw(hImage_[i]);
	}
}

//�J��
void GameClearScene::Release()
{
}
