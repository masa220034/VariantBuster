#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class EnemyBullet : public GameObject
{
    int hModel_;
    int eBulletSound_;
    XMFLOAT3 direction;
public:
    //�R���X�g���N�^
    EnemyBullet(GameObject* parent);

    //�f�X�g���N�^
    ~EnemyBullet();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void setdirection(XMFLOAT3 dir_) { direction = dir_; }
};