#pragma once
#include "Engine/GameObject.h"

class GameClearScene : public GameObject
{
	int hBackGround_;
	int hPict_;
	int BGM_;

	//-----�Q�[���N���A�̃��S�̈ʒu�A�傫���̐ݒ�-----
	float posX = 0.0f;
	float posY = 0.5f;
	float posZ = 0.0f;
	float scaleX = 1.5f;
	float scaleY = 1.5f;
	float scaleZ = 1.5f;
	//------------------------------------------------

	unsigned int frameCount;
	unsigned int DelayFrame;

	Transform tClear;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameClearScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

