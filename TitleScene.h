#pragma once
#include "Engine/GameObject.h"

class TitleScene : public GameObject
{
	int hTitleBack_;
	int hTitle_;
	int BGM_;
	int IMB = 0; //I=�摜�AM=���f���AB=BGM

	//-----�^�C�g�����̈ʒu�A�傫���̐ݒ�-----
	float titlePos = 0.3f;
	XMFLOAT3 TITLE_SCALE = XMFLOAT3(1.3f, 1.3f, 1.3f);
	//----------------------------------------

	float initPosY;
	float time = 0.0f;
	float floatingSpeed = 0.05f;   //���V���x
	float FLOAT_AMPLITUDE = 0.02f;

	Transform tTitleBack;
	Transform tTitle;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TitleScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};


