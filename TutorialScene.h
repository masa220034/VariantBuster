#pragma once
#include "Engine/GameObject.h"

enum ExType {
	EX_ONE,
	EX_TWO,
	EX_TREE,
	EX_FOUR,
	EX_MAX
};

class TutorialScene : public GameObject
{
	int hBackGorund;
	int hImage_[EX_MAX];
	int BGM_;
	
	//-----�J�����̈ʒu�A���_�̐ݒ�-----
	XMFLOAT3 CAMERA_POS = XMFLOAT3(0.0f, 3.0f, -10.0f);
	XMFLOAT3 CAMERA_TGT = XMFLOAT3(0.0f, 2.0f, 0.0f);
	//--------------------------------------

	//-----�w�i�̑傫���̐ݒ�-----
	XMFLOAT3 BACKGROUND_SCL = XMFLOAT3(0.8f, 0.8f, 0.8f);
	//----------------------------

	//-----���ꂼ��̉摜�̈ʒu�Ƒ傫���̐ݒ�-----
	XMFLOAT3 IMAGE_SCL = XMFLOAT3(0.6f, 0.6f, 0.6f);
	XMFLOAT3 IMAGE_EX_ONE_POS = XMFLOAT3(-0.7f, 0.3f, 2.0f);
	XMFLOAT3 IMAGE_EX_TWO_POS = XMFLOAT3(-0.2f, 0.5f, 2.0f);
	XMFLOAT3 IMAGE_EX_TREE_POS = XMFLOAT3(0.7f, 0.3f, 2.0f);
	XMFLOAT3 IMAGE_EX_FOUR_POS = XMFLOAT3(0.2f, 0.0f, 2.0f);
	//--------------------------------------------

	Transform tBackGround;
	Transform tImage_[EX_MAX];
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TutorialScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};