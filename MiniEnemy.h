#pragma once
#include "Engine/GameObject.h"

class MiniEnemy : public GameObject
{
    int hMiniEnemy_;
    int IMB = 0; //I=�摜�AM=���f���AB=BGM

    //-----�~�j�G�̈ʒu�A�傫���̐ݒ�-----
    XMFLOAT3 MINIENEMY_POS = XMFLOAT3((float)(rand() % 401 - 200) / 10, 5.8f, 0.0f);
    XMFLOAT3 MINIENEMY_SCL = XMFLOAT3(0.3f, 0.3f, 0.3f);
    //------------------------------------

    //-----�G�̍s�������̐ݒ�-----
    bool moveUp;
    float move = 0.05f;
    float movedPos = 5.5f;
    //----------------------------
    
    int RANDOM_ATK = 100;
    int TARGET_REMAINDER = 0;

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