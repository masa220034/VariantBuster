#include "Title.h"
#include "Engine/Image.h"


//コンストラクタ
Title::Title(GameObject* parent)
    :GameObject(parent, "Title"), hTitleBack_(-1), hTitle_(-1)

{
}

//デストラクタ
Title::~Title()
{
}

//初期化
void Title::Initialize()
{
    //画像データのロード
    hTitleBack_ = Image::Load("BackGround.png");
    hTitle_ = Image::Load("TitleName.png");
    assert(hTitleBack_ >= 0);
    assert(hTitle_ >= 0);
}

//更新
void Title::Update()
{
}

//描画
void Title::Draw()
{
    Image::SetTransform(hTitleBack_, tTitleBack);
    Image::SetTransform(hTitle_, transform_);
    Image::Draw(hTitleBack_);
    Image::Draw(hTitle_); 
}

//開放
void Title::Release()
{
}