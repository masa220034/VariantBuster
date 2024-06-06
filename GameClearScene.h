#pragma once
#include "Engine/GameObject.h"

class GameClearScene : public GameObject
{
	int hBackGround_;
	int hPict_;
	int BGM_;

	//-----�Q�[���N���A�̃��S�̈ʒu�A�傫���̐ݒ�-----
	XMFLOAT3 CLEAR_LOGO_POS = XMFLOAT3(0.0f, 0.5f, 0.0f);
	XMFLOAT3 CLEAR_LOGO_SCL = XMFLOAT3(1.5f, 1.5f, 1.5f);
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

