#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Bullet : public GameObject
{
    int hModel_;
    int BulletSound_;

    float scaleX = 0.3f;
    float scaleY = 0.3f;
    float scaleZ = 0.3f;

    float basePosX = 0.1f;
    float basePosY = 0.1f;
    float basePosZ = 0.1f;
    float c_scale = 0.3f;

    float v_shot = 0.5f;
    float limitPos = 50.0f;
public:
    //�R���X�g���N�^
    Bullet(GameObject* parent);

    //�f�X�g���N�^
    ~Bullet();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
