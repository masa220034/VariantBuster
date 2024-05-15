#pragma once
#include "Engine/GameObject.h"

//�^�C�g���V�[�����Ǘ�����N���X
class TitleScene : public GameObject
{
	int hTitleBack_;
	int hTitle_;
	int BGM_;

	float titlePos = 0.3f;
	float scaleX = 1.3f;
	float scaleY = 1.3f;
	float scaleZ = 1.3f;

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


