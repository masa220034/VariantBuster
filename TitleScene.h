#pragma once
#include "Engine/GameObject.h"

//�^�C�g���V�[�����Ǘ�����N���X
class TitleScene : public GameObject
{
	int hTitleBack_;
	int hTitle_;
	int BGM_;

	//-----�^�C�g�����̈ʒu�A�傫���̐ݒ�-----
	float titlePos = 0.3f;
	XMFLOAT3 TITLE_SCALE = XMFLOAT3(1.3f, 1.3f, 1.3f);
	//----------------------------------------

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


