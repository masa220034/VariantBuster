#pragma once
#include "Engine/GameObject.h"

class GameClearScene : public GameObject
{
	int hBackGround_;
	int hClearLogo_;
	int hLight_;
	int hChara_right_;
	int hChara_left_;
	int BGM_;
	int IMB = 0; //I=�摜�AM=���f���AB=BGM

	//-----�Q�[���N���A�̃��S�̈ʒu�A�傫���̐ݒ�-----
	XMFLOAT3 CLEAR_LOGO_POS = XMFLOAT3(0.0f, 0.5f, 0.0f);
	XMFLOAT3 CLEAR_LOGO_SCL = XMFLOAT3(1.5f, 1.5f, 1.5f);
	//------------------------------------------------

	//-----���S�̌���̈ʒu�A�傫���A�����x�̐ݒ�-----
	XMFLOAT3 LIGHT_LOGO_POS = XMFLOAT3(-0.02f, 0.35f, 0.0f);
	XMFLOAT3 LIGHT_LOGO_SCL = XMFLOAT3(1.1f, 1.1f, 1.1f);
	float INITAL_ALPHA = 1.0f;
	//------------------------------------------------

	//-----�L�����N�^�[�̈ʒu��傫���̐ݒ�-----
	XMFLOAT3 RIGHT_CHARA_POS = XMFLOAT3(0.65f, -0.5f, 0.0f);
	XMFLOAT3 LEFT_CHARA_POS = XMFLOAT3(-0.65f, -0.65f, 0.0f);
	XMFLOAT3 CHARA_SCL = XMFLOAT3(0.7f, 0.7f, 0.7f);
	//------------------------------------------

	//-----LogoScaling�֐����̕ϐ��ɂ���-----
	int alphaDir;
	float alphaSpeed;
	float min_alpha = 0.0f;
	float max_alpha = 1.0f;
	int alpha_direction_up = 1;
	int alpha_direction_down = -1;
	int frame_up = 1;
	int frame_max = 360;
	float scale_factor = 0.1f;
	float scale_speed = 20.0f;
	//-----------------------------------------

	//-----CharaJump�֐����̕ϐ��ɂ���-----
	bool isJump = true;
	float jump_value = 0.0f;
	float initial_speed = 0.0f;
	float jumpHeight = 0.7f;
	float jumpSpeed = 0.03f;
	float left_chara_posY = 0.0f;
	float right_chara_posY = 0.15f;
	//---------------------------------------

	unsigned int frameCount;
	unsigned int DelayFrame;

	Transform tLight;
	Transform tClear;

	Transform tChara_right;
	Transform tChara_left;
public:
	GameClearScene(GameObject* parent);

	void Initialize() override;

	void LogoScaling();

	void CharaJump();

	void Update() override;

	void Draw() override;

	void Release() override;
};