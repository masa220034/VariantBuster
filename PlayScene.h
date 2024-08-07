#pragma once
#include "Engine/GameObject.h"

class PlayScene : public GameObject
{
	int BGM_;
	int enemyNum = 2;
	int IMB = 0; //I=�摜�AM=���f���AB=BGM

	//-----�J�����̈ʒu�A���_�̐ݒ�-----
	XMFLOAT3 CAMERA_POS = XMFLOAT3(0.0f, 3.0f, -10.0f);
	XMFLOAT3 CAMERA_TGT = XMFLOAT3(0.0f, 2.0f, 0.0f);
	//--------------------------------------

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
