#include "TutorialScene.h"
#include "TutorialPlayer.h"
#include "TutorialEnemy.h"
#include "TutorialGround.h"
#include "PlayerGauge.h"
#include "EnemyGauge.h"
#include "Engine/Image.h"
#include "Engine/Camera.h"
#include "Engine/Audio.h"


//コンストラクタ
TutorialScene::TutorialScene(GameObject* parent)
	: GameObject(parent, "TutorialScene"), hBackGorund(-1), hImage_{ 0, 1, 2, 3 }, BGM_(-1)
{
}

//初期化
void TutorialScene::Initialize()
{
	Camera::SetPosition(CAMERA_POS);
	Camera::SetTarget(CAMERA_TGT);

	hBackGorund = Image::Load("TutorialBackGround.png");
	assert(hBackGorund >= 0);
	tBackGround.scale_ = BACKGROUND_SCL;

	const char* ImageNames[EX_MAX] = { "Ex1.png", "Ex2.png", "Ex3.png", "Ex4.png"};
	for (int i = 0; i < EX_MAX; i++)
	{
		hImage_[i] = Image::Load(ImageNames[i]);
		assert(hImage_[i] > 0);
	}

	for (int i = 0; i < EX_MAX; i++)
	{
		tImage_[i].scale_ = IMAGE_SCL;
		switch (i)
		{
		case EX_ONE:
			tImage_[i].position_ = IMAGE_EX_ONE_POS;
			break;
		case EX_TWO:
			tImage_[i].position_ = IMAGE_EX_TWO_POS;
			break;
		case EX_TREE:
			tImage_[i].position_ = IMAGE_EX_TREE_POS;
			break;
		case EX_FOUR:
			tImage_[i].position_ = IMAGE_EX_FOUR_POS;
			break;
		}
	}

	Instantiate<TutorialPlayer>(this);
	Instantiate<TutorialEnemy>(this);
	Instantiate<TutorialGround>(this);
	Instantiate<PlayerGauge>(this);
	Instantiate<EnemyGauge>(this);

	BGM_ = Audio::Load("TutorialBGM.wav");
	assert(BGM_ >= 0);
}

//更新
void TutorialScene::Update()
{
	Audio::Play(BGM_);
}

//描画
void TutorialScene::Draw()
{
	Image::SetTransform(hBackGorund, tBackGround);
	Image::Draw(hBackGorund);

	for (int i = 0; i < EX_MAX; i++)
	{
		Image::SetTransform(hImage_[i], tImage_[i]);
		Image::Draw(hImage_[i]);
	}
}

//開放
void TutorialScene::Release()
{
}
