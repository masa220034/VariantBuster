#include "GameClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"

GameClearScene::GameClearScene(GameObject* parent)
	: GameObject(parent, "GameClearScene"), 
	hBackGround_(-1), hClearLogo_(-1), hLight_(-1), BGM_(-1),
	hChara_right_(-1), hChara_left_(-1),
	frameCount(0), DelayFrame(120), alphaSpeed(0.02f), alphaDir(1)
{
}

void GameClearScene::Initialize()
{
	//画像データのロード
	hBackGround_ = Image::Load("GameClearBackGround.png");
	assert(hBackGround_ >= IMB);

	hClearLogo_ = Image::Load("GameClear.png");
	assert(hClearLogo_ >= IMB);

	hLight_ = Image::Load("EffectLight.png");
	assert(hLight_ >= IMB);
	
	hChara_right_ = Image::Load("Character1.png");
	assert(hChara_right_ >= IMB);

	hChara_left_ = Image::Load("Character2.png");
	assert(hChara_left_ >= IMB);

	BGM_ = Audio::Load("GameClearBGM.wav");
	assert(BGM_ >= IMB);

	tClear.position_ = CLEAR_LOGO_POS;
	tClear.scale_ = CLEAR_LOGO_SCL;

	tLight.position_ = LIGHT_LOGO_POS;
	tLight.scale_ = LIGHT_LOGO_SCL;
	tLight.alpha_ = INITAL_ALPHA;

	tChara_right.position_ = RIGHT_CHARA_POS;
	tChara_right.scale_ = CHARA_SCL;
	tChara_left.position_ = LEFT_CHARA_POS;
	tChara_left.scale_ = CHARA_SCL;
}

void GameClearScene::LogoScaling()
{
	//アルファ値の増減処理
	tLight.alpha_ += alphaDir * alphaSpeed;
	if (tLight.alpha_ >= max_alpha) {
		tLight.alpha_ = max_alpha;
		alphaDir = alpha_direction_down;  // 減少方向に変更
	}
	else if (tLight.alpha_ <= min_alpha) {
		tLight.alpha_ = min_alpha;
		alphaDir = alpha_direction_up;  // 増加方向に変更
	}

	frameCount = (frameCount + frame_up) % frame_max;

	/// 拡大縮小の変化（強調）
	float scaleVariation = scale_factor * sinf(static_cast<float>(frameCount) / scale_speed);
	tLight.scale_.x = CLEAR_LOGO_SCL.x + scaleVariation;
	tLight.scale_.y = CLEAR_LOGO_SCL.y + scaleVariation;
}

void GameClearScene::CharaJump()
{
	if (isJump)
	{
		initial_speed += jumpSpeed;
		if (initial_speed >= jumpHeight)
		{
			isJump = false;
		}
	}
	else
	{
		initial_speed -= jumpSpeed;
		if (initial_speed <= initial_speed)
		{
			isJump = true;
		}
	}

	tChara_left.position_.y = left_chara_posY - initial_speed;
	tChara_right.position_.y = right_chara_posY - initial_speed;
}

void GameClearScene::Update()
{
	Audio::Play(BGM_);

	LogoScaling();

	CharaJump();

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

void GameClearScene::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);

	Image::SetTransform(hLight_, tLight);
	Image::Draw(hLight_);

	Image::SetTransform(hClearLogo_, tClear);
	Image::Draw(hClearLogo_);

	Image::SetTransform(hChara_right_, tChara_right);
	Image::Draw(hChara_right_);

	Image::SetTransform(hChara_left_, tChara_left);
	Image::Draw(hChara_left_);
}

void GameClearScene::Release()
{
}