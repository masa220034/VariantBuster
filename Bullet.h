#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Bullet : public GameObject
{
    int hModel_;
    int BulletSound_;

    //-----�e�̑傫���Ƒ����̐ݒ�-----
    float scaleX = 0.3f;
    float scaleY = 0.3f;
    float scaleZ = 0.3f;
    float v_shot = 0.5f;
    //--------------------------

    //-----�R���C�_�[�̒��S�ʒu�Ƒ傫���̐ݒ�-----
    float basePosX = 0.1f;
    float basePosY = 0.1f;
    float basePosZ = 0.1f;
    float c_scale = 0.3f;
    //--------------------------------------------

    float limitPos = 50.0f;

    XMFLOAT3 direction_;
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

    void SetDirection(const XMFLOAT3& direction);
};
