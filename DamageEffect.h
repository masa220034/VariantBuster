#pragma once
#include "Engine/GameObject.h"

class DamageEffect : public GameObject
{
	int hModel_;

	//-----�G�t�F�N�g�̏ڍׂɂ���-----
	XMFLOAT3 position_;
	int DELAY = 0;
	int NUMBER = 80;
	int LIFE_TIME = 30;
	XMFLOAT3 DIRECTION = XMFLOAT3(0, 1, 0);
	XMFLOAT3 DIRECTION_RND = XMFLOAT3(90, 90, 90);
	float SPEED = 0.1f;
	float SPEED_RND = 0.8f;
	XMFLOAT2 SIZE = XMFLOAT2(0.6, 0.6);
	XMFLOAT2 SIZE_RND = XMFLOAT2(0.2, 0.2);
	XMFLOAT2 SCALE = XMFLOAT2(1.05, 1.05);
	XMFLOAT4 COLOR = XMFLOAT4(1.0, 0.0, 1.0, 0.7);
	XMFLOAT4 DELTA_COLOR = XMFLOAT4(0, 0, 0, -0.003);
	//------------------------------------

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	DamageEffect(GameObject* parent, const XMFLOAT3& position);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

