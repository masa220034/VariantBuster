#include "TutorialScene.h"
#include "TutorialEnemy.h"

//�R���X�g���N�^
TutorialScene::TutorialScene(GameObject* parent)
	: GameObject(parent, "TutorialScene")
{
}

//������
void TutorialScene::Initialize()
{
	Instantiate<TutorialEnemy>(this);
	Instantiate<
}

//�X�V
void TutorialScene::Update()
{
}

//�`��
void TutorialScene::Draw()
{
}

//�J��
void TutorialScene::Release()
{
}
