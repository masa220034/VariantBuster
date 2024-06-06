#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Bullet : public GameObject
{
    int hModel_;
    int BulletSound_;

    //-----�e�̑傫��,����,���Ă鋗���̐ݒ�-----
    XMFLOAT3 BULLET_SCL = XMFLOAT3(0.3f, 0.3f, 0.3f);
    float v_shot = 0.5f;
    float limitPos = 50.0f;
    //------------------------------------------

    //-----�R���C�_�[�̒��S�ʒu�Ƒ傫���̐ݒ�-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.1f, 0.1f, 0.1f);
    float c_scale = 0.3f;
    //--------------------------------------------

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
