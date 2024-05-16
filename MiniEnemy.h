#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class MiniEnemy : public GameObject
{
    int hMiniEnemy_;
    float move = 0.05f;
    float scaleX = 0.3f;
    float scaleY = 0.3f;
    float scaleZ = 0.3f;
    bool moveUp;

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