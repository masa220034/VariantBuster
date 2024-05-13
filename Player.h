#pragma once
#include "Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Player : public GameObject
{
private:
    int hPlayer_;
    int JumpSound_;
    int DamegeSound_;

    bool isJump = true;
    float moveSpeed = 0.1f;
    float ground_Y = 0.0f;
    float x = 0.0f;
    float v = 0.4f;
    float gravity = 0.02;
    float fallSpeed = 10.0f;      //�����鑬�x
    float fPosition = -6.0f;      //�������ꂩ�痎����̈ʒu

    int nowHp_, maxHp_;
    bool isHpmax;
    Transform tPlayer;
public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void OnCollision(GameObject* pTarget) override;
};
