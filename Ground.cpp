#include "Ground.h"
#include "Engine/Image.h"
#include "Engine/Model.h" 

//コンストラクタ
Ground::Ground(GameObject* parent)
	:GameObject(parent, "Ground"), hGround_(-1)
{
}

//デストラクタ
Ground::~Ground()
{
}

//初期化
void Ground::Initialize()
{
	hGround_ = Model::Load("Ground.fbx");
	assert(hGround_ >= 0);
}

//更新
void Ground::Update()
{
}

//描画
void Ground::Draw()
{
	Model::SetTransform(hGround_, transform_);
	Model::Draw(hGround_);
}

//開放
void Ground::Release()
{
}

