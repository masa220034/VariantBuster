#pragma once
#include "Engine/GameObject.h"

enum BossType {
	BOSS_TUTORIAL,
	BOSS_ONE,
	BOSS_TWO,
	BOSS_TREE,
	BOSS_MAX
};

class SelectScene : public GameObject
{
private:
	int hSelectBack_;
	int hSelBoss_[BOSS_MAX];
	int SelectSound_;
	int selectedBoss;

	//-----�摜�̈ړ��ʂȂǂ̐ݒ�-----
	int center = 0;
	int limitLeftPos = -3;
	float move = 1.0f;
	//--------------------------------

	//-----�摜�̑傫���̐ݒ�-----
	float scaleX = 0.5f;
	float scaleY = 0.5f;
	float scaleZ = 0.5f;
	float scaleUp = 1.5f;
	//----------------------------

	Transform tSelBoss_[BOSS_MAX];
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	SelectScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};