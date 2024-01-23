#include "Cloud_Scaffold.h"
#include "Engine/Model.h" 

//コンストラクタ
Cloud_Scaffold::Cloud_Scaffold(GameObject* parent)
	:GameObject(parent, "Cloud_Scaffold"),hCloud_Scaff_(-1)
{
}

//デストラクタ
Cloud_Scaffold::~Cloud_Scaffold()
{
}


//初期化
void Cloud_Scaffold::Initialize()
{
	hCloud_Scaff_ = Model::Load("Ground.fbx");
	assert(hCloud_Scaff_ >= 0);
}

//更新
void Cloud_Scaffold::Update()
{
}

//描画
void Cloud_Scaffold::Draw()
{
	Model::SetTransform(hCloud_Scaff_, tCloud);
	Model::Draw(hCloud_Scaff_);
}

//開放
void Cloud_Scaffold::Release()
{
}

