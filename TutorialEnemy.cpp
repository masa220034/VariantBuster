#include "TutorialEnemy.h"
#include "Engine/Model.h"

TutorialEnemy::TutorialEnemy(GameObject* parent)
	:GameObject(parent, "TutorialEnemy"), hEnemy_(-1)
{
}

TutorialEnemy::~TutorialEnemy()
{
}

void TutorialEnemy::Initialize()
{
	hEnemy_ = Model::Load("TutorialEnemy.fbx");
	assert(hEnemy_ >= 0);

	tEnemy.position_ = XMFLOAT3(5, 0, 0);
	tEnemy.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);

	Model::SetAnimFrame(hEnemy_, 1, 60, 0.5);
}

void TutorialEnemy::Update()
{
}

void TutorialEnemy::Draw()
{
	Model::SetTransform(hEnemy_, tEnemy);
	Model::Draw(hEnemy_);
}

void TutorialEnemy::Release()
{
}
