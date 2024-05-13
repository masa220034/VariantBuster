#include "SelectScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
SelectScene::SelectScene(GameObject* parent)
    : GameObject(parent, "SelectScene"), hSelectBack_(-1), hSelBoss_{ 0, 1, 2 }
{
}

//初期化
void SelectScene::Initialize()
{
    //画像データのロード
    hSelectBack_ = Image::Load("BackGround.png");
    assert(hSelectBack_ >= 0);

    const char* ImageNames[BOSS_MAX] = { "SelectBoss1.png", "SelectBoss2.png", "SelectBoss3.png" };
    for (int i = 0; i < BOSS_MAX; i++)
    {
        hSelBoss_[i] = Image::Load(ImageNames[i]);
        assert(hSelBoss_[i] > 0);
    }

    //セレクトボス(1,2,3)の初期位置と大きさ
    for (int i = 0; i < BOSS_MAX; i++)
    {
        tSelBoss_[i].scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);
        tSelBoss_[i].position_.x = i;
    }
}

//更新
void SelectScene::Update()
{
    if (Input::IsKeyDown(DIK_LEFT))
    {
        for (int i = 0; i < BOSS_MAX; i++)
        {
            tSelBoss_[i].position_.x += move;
            if (tSelBoss_[BOSS_first].position_.x >= center)
            {
                tSelBoss_[i].position_.x = i;
            }
        }
    }

    if (Input::IsKeyDown(DIK_RIGHT))
    {
        for (int i = 0; i < BOSS_MAX; i++)
        {
            tSelBoss_[i].position_.x -= move;
            if (tSelBoss_[BOSS_third].position_.x <= center)
            {
                tSelBoss_[i].position_.x = limitLeftPos + i;
            }
        }
    }

    if (Input::IsKeyDown(DIK_SPACE))
    {
        if (tSelBoss_[BOSS_second].position_.x == center)
        {
            SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
            pSceneManager->ChangeScene(SCENE_ID_PLAY);
        }
    }
}

//描画
void SelectScene::Draw()
{
    Image::SetTransform(hSelectBack_, transform_);
    Image::Draw(hSelectBack_);

    for (int i = 0; i < BOSS_MAX; i++)
    {
        //位置が0なら拡大、それ以外は変化なし
        if (tSelBoss_[i].position_.x == center)
        {
            tSelBoss_[i].scale_ = XMFLOAT3(scaleX * scaleUp, scaleY * scaleUp, scaleZ * scaleUp);
        }
        else
        {
            tSelBoss_[i].scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);
        }
        Image::SetTransform(hSelBoss_[i], tSelBoss_[i]);
        Image::Draw(hSelBoss_[i]);
    }
}

//開放
void SelectScene::Release()
{
}