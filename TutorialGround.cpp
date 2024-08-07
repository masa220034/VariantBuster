#include "TutorialGround.h"
#include "Engine/Model.h"

//�R���X�g���N�^
TutorialGround::TutorialGround(GameObject* parent)
	:GameObject(parent, "TutorialGround"), hGround_(-1)
{
}

//�f�X�g���N�^
TutorialGround::~TutorialGround()
{
}

//������
void TutorialGround::Initialize()
{
	hGround_ = Model::Load("TutorialGround.fbx");
	assert(hGround_ >= IMB);
}

//�X�V
void TutorialGround::Update()
{
}

//�`��
void TutorialGround::Draw()
{
	Model::SetTransform(hGround_, transform_);
	Model::Draw(hGround_);
}

//�J��
void TutorialGround::Release()
{
}
