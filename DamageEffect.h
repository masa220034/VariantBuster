#pragma once
#include "Engine/GameObject.h"

class DamageEffect : public GameObject
{
	int hModel_;
	XMFLOAT3 position_;
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

