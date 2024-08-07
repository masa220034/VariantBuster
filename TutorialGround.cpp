#include "TutorialGround.h"
#include "Engine/Model.h"

//コンストラクタ
TutorialGround::TutorialGround(GameObject* parent)
	:GameObject(parent, "TutorialGround"), hGround_(-1)
{
}

//デストラクタ
TutorialGround::~TutorialGround()
{
}

//初期化
void TutorialGround::Initialize()
{
	hGround_ = Model::Load("TutorialGround.fbx");
	assert(hGround_ >= IMB);
}

//更新
void TutorialGround::Update()
{
}

//描画
void TutorialGround::Draw()
{
	Model::SetTransform(hGround_, transform_);
	Model::Draw(hGround_);
}

//開放
void TutorialGround::Release()
{
}
