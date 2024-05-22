#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class MiniEnemy : public GameObject
{
    int hMiniEnemy_;

    //-----�~�j�G�̈ʒu�A�傫���̐ݒ�-----
    float move = 0.05f;
    float scaleX = 0.3f;
    float scaleY = 0.3f;
    float scaleZ = 0.3f;
    float posX = (float)(rand() % 401 - 200) / 10;
    float posY = 5.8f;
    float posZ = 0.0f;
    //------------------------------------

    float movedPos = 5.5f;
    bool moveUp;

    unsigned int frameCount;
    unsigned int DelayFrame;

    Transform tMiniEnemy;
public:
    //�R���X�g���N�^
    MiniEnemy(GameObject* parent);

    //�f�X�g���N�^
    ~MiniEnemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void movePattern();
};