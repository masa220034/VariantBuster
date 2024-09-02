#include "TitleScene.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "Engine/Audio.h"
#include "Engine/VFX.h"
#include "Engine/SceneManager.h"
#include <cmath>

//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"), hTitleBack_(-1), hTitle_(-1), BGM_(-1)
{
}

//������
void TitleScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hTitleBack_ = Image::Load("TitleBackGround.png");
	hTitle_ = Image::Load("TitleName.png");
	BGM_ = Audio::Load("TitleBGM.wav");
	assert(hTitleBack_ >= IMB);
	assert(hTitle_ >= IMB);
	assert(BGM_ >= IMB);

	tTitle.position_.y += titlePos;
	initPosY = tTitle.position_.y;
	tTitle.scale_ = TITLE_SCALE;
}

//�X�V
void TitleScene::Update()
{
	Audio::Play(BGM_);

	time += floatingSpeed;

	tTitle.position_.y = initPosY + std::sin(time) * FLOAT_AMPLITUDE;
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_SELECT);
	}
}

//�`��
void TitleScene::Draw()
{
	Image::SetTransform(hTitleBack_, tTitleBack);
	Image::SetTransform(hTitle_, tTitle);
	Image::Draw(hTitleBack_);
	Image::Draw(hTitle_);
}

//�J��
void TitleScene::Release()
{
}