#include "SelectScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
SelectScene::SelectScene(GameObject* parent)
    : GameObject(parent, "SelectScene"), hSelectBack_(-1), hSelBoss_{ 0, 1, 2, 3 }, SelectSound_(-1)
{
}

//������
void SelectScene::Initialize()
{
    hSelectBack_ = Image::Load("BackGround.png");
    assert(hSelectBack_ >= 0);

    const char* ImageNames[BOSS_MAX] = { "Tutorial.png", "SelectBoss1.png", "SelectBoss2.png", "SelectBoss3.png" };
    for (int i = 0; i < BOSS_MAX; i++)
    {
        hSelBoss_[i] = Image::Load(ImageNames[i]);
        assert(hSelBoss_[i] > 0);
    }

    //�`���[�g���A��+�Z���N�g�{�X(�摜)�̏����ʒu�Ƒ傫��
    for (int i = 0; i < BOSS_MAX; i++)
    {
        tSelBoss_[i].scale_ = XMFLOAT3(scaleX, scaleY, scaleZ);
        tSelBoss_[i].position_.x = i;
    }

    SelectSound_ = Audio::Load("SelectSound.wav");
    assert(SelectSound_ >= 0);
}

//�X�V
void SelectScene::Update()
{
    if (Input::IsKeyDown(DIK_LEFT))
    {
        Audio::Play(SelectSound_);
        for (int i = 0; i < BOSS_MAX; i++)
        {
            tSelBoss_[i].position_.x += move;
            if (tSelBoss_[BOSS_TUTORIAL].position_.x >= center)
            {
                tSelBoss_[i].position_.x = i;
            }
        }
    }

    if (Input::IsKeyDown(DIK_RIGHT))
    {
        Audio::Play(SelectSound_);
        for (int i = 0; i < BOSS_MAX; i++)
        {
            tSelBoss_[i].position_.x -= move;
            if (tSelBoss_[BOSS_TREE].position_.x <= center)
            {
                tSelBoss_[i].position_.x = limitLeftPos + i;
            }
        }
    }

    if (Input::IsKeyDown(DIK_SPACE))
    {
        for (int i = 0; i < BOSS_MAX; i++)
        {
            if (tSelBoss_[i].position_.x == center)
            {
                selectedBoss = i;
                break;
            }
        }

        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");

        switch(selectedBoss)
        {
        case BOSS_TUTORIAL:
            pSceneManager->ChangeScene(SCENE_ID_TUTORIAL);
            break;
        case BOSS_ONE:
            break;
        case BOSS_TWO:
            pSceneManager->ChangeScene(SCENE_ID_PLAY);
            break;
        case BOSS_TREE:
            break;
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