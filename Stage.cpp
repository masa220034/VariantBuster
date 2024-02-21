#include "Stage.h"
#include "Gauge.h"
#include "Engine/Image.h"
#include "Engine/Model.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"), hBackGround_(-1), hGround_(-1),
	maxPt_(200), nowPt_(0)
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
	hGround_ = Model::Load("Ground.fbx");
	assert(hBackGround_ >= 0);
	assert(hGround_ >= 0);
}

//更新
void Stage::Update()
{
	nowPt_ += 1;
	if (nowPt_ >= maxPt_)
	{
		nowPt_ = maxPt_;
	}
	Gauge* pGauge = (Gauge*)FindObject("Gauge");
	pGauge->SetPt(nowPt_, maxPt_);
}

//描画
void Stage::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);
	
	Model::SetTransform(hGround_, tGround);
	Model::Draw(hGround_);
}

//開放
void Stage::Release()
{
}