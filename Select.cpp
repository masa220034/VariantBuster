#include "Select.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
Select::Select(GameObject* parent)
    :GameObject(parent, "Select"), hSelectBack_(-1), hButton_(-1), hImage_(-1)
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
    hImage_ = Image::Load("Select.png");
    hButton_ = Image::Load("SelectButton_Sample.png");
    hSkill_ = Image::Load("SkillUp.png");
    assert(hSelectBack_ >= 0);
    assert(hImage_ >= 0);
    assert(hButton_ >= 0);
    assert(hSkill_ >= 0);

    tSkill.position_ = XMFLOAT3(0.015f, -0.8f, 0.0f);
}

//更新
void Select::Update()
{
    if (Input::IsKeyDown(DIK_DOWN))
    {
        tSelect.position_.y -= 0.85f;
        if (tSelect.position_.y < -0.85)
        {
            tSelect.position_.y = -0.85;
        }
    }
    else if (Input::IsKeyDown(DIK_UP))
    {
        tSelect.position_.y += 0.85f;
        if (tSelect.position_.y > 0.0)
        {
            tSelect.position_.y = 0.0;
        }
    }
}

//描画
void Select::Draw()
{
    Image::SetTransform(hSelectBack_, transform_);
    Image::SetTransform(hImage_, tSelect);
    Image::SetTransform(hButton_, transform_);
    Image::SetTransform(hSkill_, tSkill);
    Image::Draw(hSelectBack_);
    Image::Draw(hImage_);
    Image::Draw(hButton_);   
    Image::Draw(hSkill_);
}

//開放
void Select::Release()
{
}
