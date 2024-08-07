#include "Stage.h"
#include "Engine/Image.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"), hBackGround_(-1), hGround_(-1)
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
	hBackGround_ = Image::Load("PlayBackGround.png");
	assert(hBackGround_ >= IMB);

	hGround_ = Model::Load("Ground.fbx");
	assert(hGround_ >= IMB);
}

//�X�V
void Stage::Update()
{
}

//�`��
void Stage::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);

	Model::SetTransform(hGround_, transform_);
	Model::Draw(hGround_);
}

//�J��
void Stage::Release()
{
}