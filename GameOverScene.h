#pragma once
#include "Engine/GameObject.h"

class GameOverScene : public GameObject
{
	int hPict_;
	int hBack_;
	int BGM_;
	int IMB = 0; //I=�摜�AM=���f���AB=BGM

	unsigned int frameCount;
	unsigned int DelayFrame;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameOverScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};