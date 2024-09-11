#include "GameClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"

//コンストラクタ
GameClearScene::GameClearScene(GameObject* parent)
	: GameObject(parent, "GameClearScene"), 
	hBackGround_(-1), hClearLogo_(-1), hLight_(-1), BGM_(-1),
	hChara1_(-1), hChara2_(-2),
	frameCount(0), DelayFrame(120), alphaSpeed(0.02f), alphaDir(1)
{
}

//初期化
void GameClearScene::Initialize()
{
	//画像データのロード
	hBackGround_ = Image::Load("GameClearBackGround.png");
	assert(hBackGround_ >= IMB);

	hClearLogo_ = Image::Load("GameClear.png");
	assert(hClearLogo_ >= IMB);

	hLight_ = Image::Load("EffectLight.png");
	assert(hLight_ >= IMB);
	
	hChara1_ = Image::Load("Character1.png");
	assert(hChara1_ >= IMB);

	hChara2_ = Image::Load("Character2.png");
	assert(hChara1_ >= IMB);

	BGM_ = Audio::Load("GameClearBGM.wav");
	assert(BGM_ >= IMB);

	tClear.position_ = CLEAR_LOGO_POS;
	tClear.scale_ = CLEAR_LOGO_SCL;

	tLight.position_ = LIGHT_LOGO_POS;
	tLight.scale_ = LIGHT_LOGO_SCL;
	tLight.alpha_ = 1.0f;

	tChara1.position_ = XMFLOAT3(0.65f, -0.5f, 0.0f);
	tChara1.scale_ = XMFLOAT3(0.7f, 0.7f, 0.7f);
	tChara2.position_ = XMFLOAT3(-0.65f, -0.65f, 0.0f);
	tChara2.scale_ = XMFLOAT3(0.7f, 0.7f, 0.7f);
}

//更新
void GameClearScene::Update()
{
	Audio::Play(BGM_);

	//アルファ値の増減処理
	tLight.alpha_ += alphaDir * alphaSpeed;
	if (tLight.alpha_ >= 1.0f) {
		tLight.alpha_ = 1.0f;
		alphaDir = -1;  // 減少方向に変更
	}
	else if (tLight.alpha_ <= 0.0f) {
		tLight.alpha_ = 0.0f;
		alphaDir = 1;  // 増加方向に変更
	}

	frameCount = (frameCount + 1) % 360;

	/// 拡大縮小の変化（強調）
	float scaleVariation = 0.1f * sinf(static_cast<float>(frameCount) / 20.0f);
	tLight.scale_.x = CLEAR_LOGO_SCL.x + scaleVariation;
	tLight.scale_.y = CLEAR_LOGO_SCL.y + scaleVariation;

	if (isJump) 
	{
		x += jumpSpeed;
		if (x >= jumpHeight)
		{
			isJump = false;
		}
	}
	else
	{
		x -= jumpSpeed;
		if (x <= 0.0f)
		{
			isJump = true;
		}
	}

	tChara1.position_.y = 0.15f - x;
	tChara2.position_.y = 0.0f - x;
	//tChara1.position_.y = -0.2f + jumpHeight * sinf(static_cast<float>(frameCount) * jumpSpeed);
	//tChara2.position_.y = -0.2f + jumpHeight * sinf(static_cast<float>(frameCount) * jumpSpeed); // 少しずらして動かす

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

//描画
void GameClearScene::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);

	Image::SetTransform(hLight_, tLight);
	Image::Draw(hLight_);

	Image::SetTransform(hClearLogo_, tClear);
	Image::Draw(hClearLogo_);

	Image::SetTransform(hChara1_, tChara1);
	Image::Draw(hChara1_);

	Image::SetTransform(hChara2_, tChara2);
	Image::Draw(hChara2_);
}

//開放
void GameClearScene::Release()
{
}
