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

	FireEffect();
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

void TitleScene::FireEffect()
{
	//��
	EmitterData data;
	data.textureFileName = "cloudA.png";
	data.position = XMFLOAT3(4, -5, 0);
	data.positionRnd = XMFLOAT3(0.1, 0, 0.1);
	data.delay = 5;
	data.number = 1;
	data.lifeTime = 5;
	data.gravity = -0.002f;
	data.direction = XMFLOAT3(0, 1, 0);
	data.directionRnd = XMFLOAT3(0, 0, 0);
	data.speed = 0.01f;
	data.speedRnd = 0.0;
	data.size = XMFLOAT2(1.5, 1.5);
	data.sizeRnd = XMFLOAT2(0.4, 0.4);
	data.scale = XMFLOAT2(1.01, 1.01);
	data.color = XMFLOAT4(1, 1, 0, 1);
	data.deltaColor = XMFLOAT4(0, -0.03, 0, -0.02);
	VFX::Start(data);

	//�΂̕�
	data.number = 3;
	data.positionRnd = XMFLOAT3(0.8, 0, 0.8);
	data.direction = XMFLOAT3(0, 1, 0);
	data.directionRnd = XMFLOAT3(10, 10, 10);
	data.size = XMFLOAT2(0.2, 0.2);
	data.scale = XMFLOAT2(0.95, 0.95);
	data.lifeTime = 10;
	data.speed = 0.1f;
	data.gravity = 0;
	VFX::Start(data);
}

void TitleScene::BulleFireEffect()
{
}
