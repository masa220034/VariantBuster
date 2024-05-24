#pragma once
#include "Engine/GameObject.h"

//�v���C���[���Ǘ�����N���X
class Player : public GameObject
{
private:
    int hPlayer_;
    int JumpSound_;
    int DamegeSound_;

    float moveSpeed = 0.1f;

    //-----�J�����̈ʒu�A���_�̐ݒ�-----
    float cmrPosX = 0.0f;
    float cmrPosY = 3.0f;
    float cmrPosZ = 10.0f;
    float cmrTgtX = 0.0f;
    float cmrTgtY = 2.0f;
    float cmrTgtZ = 0.0f;
    //--------------------------------------
 
    //-----�v���C���[�̈ʒu�A�傫���̐ݒ�-----
    float posX = -3.0f;
    float posY = 0.0f;
    float posZ = 0.0f;
    float scaleX = 0.2f;
    float scaleY = 0.2f;
    float scaleZ = 0.2f;
    //----------------------------------------
    
     //-----�v���C���[�̌�����ݒ�-----
    bool P_Right; //�E�������Ă��邩�ǂ���
    float P_dirX = 1.0f;
    float P_dirY = 0.0f;
    float P_dirZ = 0.0f;
    //--------------------------------

    //-----�R���C�_�[�̒��S�ʒu�A�傫���̐ݒ�-----
    float basePosX = 0.0f;
    float basePosY = 0.2f;
    float basePosZ = 0.0f;
    float c_scale = 0.25f;
    //--------------------------------------------
    
    //-----���C�̔��˕���-----
    float R_dirX = 0.0f;
    float R_dirY = -1.0f;
    float R_dirZ = 0.0f;
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
