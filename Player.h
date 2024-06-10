#pragma once
#include "Engine/GameObject.h"
#include <chrono>

class Player : public GameObject
{
private:
    int hPlayer_;
    int JumpSound_;
    int DamegeSound_;

    float moveSpeed = 0.1f;

    float cooldown;
    std::chrono::high_resolution_clock::time_point lastBulletTime;

    //-----�J�����̈ʒu�A���_�̐ݒ�-----
    XMFLOAT3 CAMERA_POS = XMFLOAT3(0.0f, 3.0f, -10.0f);
    XMFLOAT3 CAMERA_TGT = XMFLOAT3(0.0f, 2.0f, 0.0f);
    //--------------------------------------
 
    //-----�v���C���[�̈ʒu�A�傫���̐ݒ�-----
    XMFLOAT3 PLAYER_POS = XMFLOAT3(-3.0f, 0.0f, 0.0f);
    XMFLOAT3 PLAYER_SCL = XMFLOAT3(0.2f, 0.2f, 0.2f);
    //----------------------------------------
    
     //-----�v���C���[�������Ă�������ɒe�������ǂ���-----
    bool P_Right; //�E�������Ă��邩�ǂ���
    XMFLOAT3 RIGHT_DIR = XMFLOAT3(1.0f, 0.0f, 0.0f);
    XMFLOAT3 LEFT_DIR = XMFLOAT3(-1.0f, 0.0f, 0.0f);
    //-------------------------------------------------------

    //-----�R���C�_�[�̒��S�ʒu�A�傫���̐ݒ�-----
    XMFLOAT3 BASE_POS = XMFLOAT3(0.0f, 0.2f, 0.0f);
    float c_scale = 0.25f;
    //--------------------------------------------
    
    //-----���C�̔��˕���-----
    XMFLOAT3 RAY_DIR = XMFLOAT3(0.0f, -1.0f, 0.0f);
    //------------------------

    //-----�W�����v�Ɏg�p���Ă���ϐ��B-----
    bool isJump = true;      //�W�����v���Ă邩�ǂ���
    float ground_Y = 0.0f;   //�n�ʂ̈ʒu
    float x = 0.0f;          //�㏸��
    float v = 0.4f;          //�W�����v�̏����x
    float gravity = 0.02;    //�d�͉����x
    float fallSpeed = 10.0f; //�����鑬�x
    float fPosition = -6.0f; //�������ꂩ�痎����̈ʒu
    //---------------------------------------

    //-----�v���C���[��HP�Q�[�W�̐ݒ�-----
    bool isHpmax;
    int nowHp_, maxHp_;
    int upHp_ = 1;
    int noHp_ = 0;
    //------------------------------------

    //-----HP�Q�[�W�̌����֘A�ɂ���-----
    bool isDamage;
    float d_Amount;
    float d_Step;
    float targetHp;
    //------------------------------------

    //-----�_���[�W�ʂ̐ݒ�-----
    int e_damage = 2;
    int eb_damage = 4;
    int sec_eb_damage = 8;
    int min_b_damage = 4;
    //--------------------------

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

    void StartDamage(float amount);
};
