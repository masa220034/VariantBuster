#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

static const int FPS = 60;

class Timer : public GameObject
{
private:
	//-----フレームおよび時間などの設定-----
	int frame;
	int noFrame = 0;
	int limitFrame;
	int time = 120;  //制限時間
	int div = 60;    //60分割
	int t_pla = 10;  //10の位
	//--------------------------------------

	int drawX, drawY; //XとYの位置座標
	float textScale = 1.0f;
	bool active;      //動いてるかどうか

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