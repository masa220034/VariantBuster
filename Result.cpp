#include "Result.h"
#include "Engine/Image.h"

//コンストラクタ
Result::Result(GameObject* parent)
    :GameObject(parent, "Result"), hPict_(-1)
{
}

//デストラクタ
Result::~Result()
{
}

//初期化
void Result::Initialize()
{
    //画像データのロード
    hPict_ = Image::Load("Result.png");
    assert(hPict_ >= 0);
}

//更新
void Result::Update()
{
}

//描画
void Result::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//開放
void Result::Release()
{
}


