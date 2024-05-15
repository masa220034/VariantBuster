#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

static const int FPS = 60;

class Timer : public GameObject
{
private:
	int frame;
	int limitFrame;
	int time = 120;
	int drawX, drawY; //X��Y�̈ʒu���W
	float textScale = 1.0f;
	bool active;      //�����Ă邩�ǂ���

	Text* pText;
public:
	Timer(GameObject* obj);
	~Timer();

	void Initialize();
	void Update();
	void Draw();
	void Release();

	void SetLimit(float seconds);
	void Start();
	void Stop();
	bool IsFinished();
};