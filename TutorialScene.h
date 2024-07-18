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
	
	//-----�J�����̈ʒu�A���_�̐ݒ�-----
	XMFLOAT3 CAMERA_POS = XMFLOAT3(0.0f, 3.0f, -10.0f);
	XMFLOAT3 CAMERA_TGT = XMFLOAT3(0.0f, 2.0f, 0.0f);
	//--------------------------------------

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