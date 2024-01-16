#include "Stage.h"
#include "Engine/Image.h"
#include "Engine/Model.h" 
#include "Engine/Camera.h"
#include "Engine/BoxCollider.h"


//コンストラクタ
Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"), hBackGround_(-1), hGround_(-1)
{
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
	Camera::SetPosition(XMFLOAT3(0, 3, -10));
	Camera::SetTarget(XMFLOAT3(0, 2, 0));

	hBackGround_ = Image::Load("PlayBackGround.png");
	hGround_ = Model::Load("Ground.fbx");
	assert(hBackGround_ >= 0);
	assert(hGround_ >= 0);

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0.15, -1, 0), XMFLOAT3(11, 2.3, 1));
	AddCollider(collision);
}

//更新
void Stage::Update()
{
}

//描画
void Stage::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Model::SetTransform(hGround_, trGround);
	Image::Draw(hBackGround_);
	Model::Draw(hGround_);
}

//開放
void Stage::Release()
{
}
