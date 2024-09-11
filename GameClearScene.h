#pragma once
#include "Engine/GameObject.h"

class GameClearScene : public GameObject
{
	int hBackGround_;
	int hClearLogo_;
	int hLight_;
	int hChara1_;
	int hChara2_;
	int BGM_;
	int IMB = 0; //I=�摜�AM=���f���AB=BGM

	//-----�Q�[���N���A�̃��S�̈ʒu�A�傫���̐ݒ�-----
	XMFLOAT3 CLEAR_LOGO_POS = XMFLOAT3(0.0f, 0.5f, 0.0f);
	XMFLOAT3 CLEAR_LOGO_SCL = XMFLOAT3(1.5f, 1.5f, 1.5f);
	//------------------------------------------------

	//-----���S�̌���̈ʒu�A�傫���A�����x�̐ݒ�-----
	XMFLOAT3 LIGHT_LOGO_POS = XMFLOAT3(-0.02f, 0.35f, 0.0f);
	XMFLOAT3 LIGHT_LOGO_SCL = XMFLOAT3(1.1f, 1.1f, 1.1f);
	//------------------------------------------------

	int alphaDir;
	float alphaSpeed;

	float x = 0.0f;
	float jumpHeight = 0.7f;
	float jumpSpeed = 0.03f;
	bool isJump = true;

	unsigned int frameCount;
	unsigned int DelayFrame;

	Transform tLight;
	Transform tClear;

	Transform tChara1;
	Transform tChara2;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameClearScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};