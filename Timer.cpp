#include "Timer.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

Timer::Timer(GameObject* obj) : GameObject(obj, "Timer"),
pText(nullptr), frame(0), active(false), drawX(610), drawY(30), limitFrame(0)
{
}

Timer::~Timer()
{
}

void Timer::Initialize()
{
	pText = new Text;
	pText->Initialize();

	frame = noFrame;
	active = false;

	SetLimit(time); //制限時間を設定
}

void Timer::Update()
{
	Start();

	if (active) {
		if (frame > noFrame){
			frame--;
		}
	}

	Stop();

	if (IsFinished()) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}
}

void Timer::Draw()
{
	pText->SetScale(textScale);

	int sec = frame / FPS; //経過した秒数を計算
	int minutes = sec / div;
	int seconds = sec % div;

	std::string s_minutes = (minutes < t_pla) ? "0" + std::to_string(minutes) : std::to_string(minutes);
	std::string s_seconds = (seconds < t_pla) ? "0" + std::to_string(seconds) : std::to_string(seconds);
	std::string s_time = s_minutes + ":" + s_seconds; //分:秒の文字列を作成
	pText->Draw(drawX, drawY, s_time.c_str());
}

void Timer::Release()
{
	pText->Release();
}

void Timer::SetLimit(float seconds)
{
	limitFrame = FPS * seconds;
	frame = limitFrame;
}

void Timer::Start()
{
	active = true;
}

void Timer::Stop()
{
	active = false;
}

bool Timer::IsFinished()
{
	return (frame == noFrame);
}
