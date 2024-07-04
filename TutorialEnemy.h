#pragma once
#include "Engine/GameObject.h"

class TutorialEnemy : public GameObject
{
    int hEnemy_;

    Transform tEnemy;
public:
    //�R���X�g���N�^
    TutorialEnemy(GameObject* parent);

    //�f�X�g���N�^
    ~TutorialEnemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

