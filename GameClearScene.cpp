#include "GameClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"

//コンストラクタ
GameClearScene::GameClearScene(GameObject* parent)
	: GameObject(parent, "GameClearScene"), hBackGround_(-1), hPict_(-1), BGM_(-1)
{
}

//初期化
void GameClearScene::Initialize()
{
	//画像データのロード
	hBackGround_ = Image::Load("GameClearBackGround.png");
	assert(hBackGround_ >= 0);

	hPict_ = Image::Load("GameClear.png");
	assert(hPict_ >= 0);

	BGM_ = Audio::Load("GameClearBGM.wav");
	assert(BGM_ >= 0);

	tClear.position_ = XMFLOAT3(posX, posY, posZ);
	tClear.scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);
}

//更新
void GameClearScene::Update()
{
	Audio::Play(BGM_);
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void GameClearScene::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);

	Image::SetTransform(hPict_, tClear);
	Image::Draw(hPict_);
}

//開放
void GameClearScene::Release()
{
}
