#pragma once
#include "Engine/GameObject.h"

class TutorialClearScene : public GameObject
{
	int hBackGround_;
	int BGM_;
	int IMB = 0; //I=�摜�AM=���f���AB=BGM

	unsigned int frameCount;
	unsigned int DelayFrame;

	Transform tClear;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TutorialClearScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};