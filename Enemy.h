#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Enemy : public GameObject
{
    int hEnemy_;
    int hMiniEnemy_;
    int DamegeSound_;

    unsigned int frameCount;
    unsigned int DelayFrame;
    int nowHp_, maxHp_, halfHp_;
    float move = 0.05f;
    float pos;
    bool moveUp;
    bool isHpmax;

    Transform tEnemy;
    Transform tMiniEnemy;
public:
    //�R���X�g���N�^
    Enemy(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void OnCollision(GameObject* pTarget) override;

    void AttackPattern();

    void movePattern();
};
