#include "Select.h"
#include "Engine/Image.h"

//コンストラクタ
Select::Select(GameObject* parent)
    :GameObject(parent, "Select"), hSelectBack_(-1), hButton_(-1)
{
}

//デストラクタ
Select::~Select()
{
}

//初期化
void Select::Initialize()
{
    //画像データのロード
    hSelectBack_ = Image::Load("BackGround.png");
    hButton_ = Image::Load("SelectButton_Sample.png");
    assert(hSelectBack_ >= 0);
    assert(hButton_ >= 0);
}

//更新
void Select::Update()
{
}

//描画
void Select::Draw()
{
    Image::SetTransform(hSelectBack_, transform_);
    Image::SetTransform(hButton_, transform_);
    Image::Draw(hSelectBack_);
    Image::Draw(hButton_);
}

//開放
void Select::Release()
{
}
