#include "Stage.h"
#include "Engine/Image.h"
#include "Engine/Model.h" 

//コンストラクタ
Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"), hBackGround_(-1)
{
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
	hBackGround_ = Image::Load("PlayBackGround.png");
	assert(hBackGround_ >= 0);
}

//更新
void Stage::Update()
{
}

//描画
void Stage::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);
}

//開放
void Stage::Release()
{
}
