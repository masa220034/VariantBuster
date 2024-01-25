#include "Ground.h"
#include "Engine/Image.h"
#include "Engine/Model.h" 

//コンストラクタ
Ground::Ground(GameObject* parent, const std::string& name, float xPos)
	:GameObject(parent, name)
{
	tGround.position_ = XMFLOAT3(xPos, 0, 0);
}

//デストラクタ
Ground::~Ground()
{
}

//初期化
void Ground::Initialize()
{
	hGround_ = Image::Load("Ground.fbx");
	assert(hGround_ >= 0);
}

//更新
void Ground::Update()
{
}

//描画
void Ground::Draw()
{
	Image::SetTransform(hGround_, tGround);
	Image::Draw(hGround_);
}

//開放
void Ground::Release()
{
}

