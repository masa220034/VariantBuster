#include "TutorialScene.h"
#include "TutorialEnemy.h"
#include "TutorialGround.h"
#include "EnemyGauge.h"
#include "Engine/Image.h"

//�R���X�g���N�^
TutorialScene::TutorialScene(GameObject* parent)
	: GameObject(parent, "TutorialScene"), hBackGorund(-1)
{
}

//������
void TutorialScene::Initialize()
{
	hBackGorund = Image::Load("TutorialBackGround.png");
	assert(hBackGorund >= 0);
	transform_.scale_ = XMFLOAT3(0.8f, 0.8f, 0.8f);

	Instantiate<TutorialEnemy>(this);
	Instantiate<TutorialGround>(this);
	Instantiate<EnemyGauge>(this);
}

//�X�V
void TutorialScene::Update()
{
}

//�`��
void TutorialScene::Draw()
{
	Image::SetTransform(hBackGorund, transform_);
	Image::Draw(hBackGorund);
}

//�J��
void TutorialScene::Release()
{
}
