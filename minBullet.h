#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class minBullet : public GameObject
{
    int hModel_;
    bool shot;
public:
    //�R���X�g���N�^
    minBullet(GameObject* parent);

    //�f�X�g���N�^
    ~minBullet();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

