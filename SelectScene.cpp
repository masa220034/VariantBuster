#include "SelectScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
SelectScene::SelectScene(GameObject* parent)
    : GameObject(parent, "SelectScene"), hSelectBack_(-1), hSelBoss_{ 0, 1, 2 }
{
}

//������
void SelectScene::Initialize()
{
    //�摜�f�[�^�̃��[�h
    hSelectBack_ = Image::Load("BackGround.png");
    assert(hSelectBack_ >= 0);

    const char* ImageNames[BOSS_MAX] = { "SelectBoss1.png", "SelectBoss2.png", "SelectBoss3.png" };
    for (int i = 0; i < BOSS_MAX; i++)
    {
        hSelBoss_[i] = Image::Load(ImageNames[i]);
        assert(hSelBoss_[i] > 0);
    }

    //�Z���N�g�{�X(1,2,3)�̏����ʒu�Ƒ傫��
    for (int i = 0; i < BOSS_MAX; i++)
    {
        tSelBoss_[i].scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);
        tSelBoss_[i].position_.x = i;
    }
}

//�X�V
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

//�`��
void SelectScene::Draw()
{
    Image::SetTransform(hSelectBack_, transform_);
    Image::Draw(hSelectBack_);

    for (int i = 0; i < BOSS_MAX; i++)
    {
        //�ʒu��0�Ȃ�g��A����ȊO�͕ω��Ȃ�
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

//�J��
void SelectScene::Release()
{
}