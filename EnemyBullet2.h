#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class EnemyBullet2 : public GameObject
{
    int hModel_;
    bool shot;
public:
    //�R���X�g���N�^
    EnemyBullet2(GameObject* parent);

    //�f�X�g���N�^
    ~EnemyBullet2();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
