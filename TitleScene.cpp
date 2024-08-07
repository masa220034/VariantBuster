#include "TitleScene.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"

//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"), hTitleBack_(-1), hTitle_(-1), BGM_(-1)
{
}

//初期化
void TitleScene::Initialize()
{
	//画像データのロード
	hTitleBack_ = Image::Load("TitleBackGround.png");
	hTitle_ = Image::Load("TitleName.png");
	BGM_ = Audio::Load("TitleBGM.wav");
	assert(hTitleBack_ >= IMB);
	assert(hTitle_ >= IMB);
	assert(BGM_ >= IMB);

	tTitle.position_.y += titlePos;
	tTitle.scale_ = TITLE_SCALE;
}

//更新
void TitleScene::Update()
{
	Audio::Play(BGM_);
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_SELECT);
	}
}

//描画
void TitleScene::Draw()
{
	Image::SetTransform(hTitleBack_, tTitleBack);
	Image::SetTransform(hTitle_, tTitle);
	Image::Draw(hTitleBack_);
	Image::Draw(hTitle_);
}

//開放
void TitleScene::Release()
{
}