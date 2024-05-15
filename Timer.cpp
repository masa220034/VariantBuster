#include "Timer.h"
#include "Engine/Input.h"

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

	frame = 0;
	active = false;

	SetLimit(time); //�������Ԃ�ݒ�
}

void Timer::Update()
{
	Start();

	if (active) {
		if (frame > 0) {
			frame--;
		}
	}

	Stop();

	IsFinished();
}

void Timer::Draw()
{
	pText->SetScale(textScale);

	int sec = frame / FPS; //�o�߂����b�����v�Z
	int minutes = sec / 60;
	int seconds = sec % 60;

	std::string s_minutes = (minutes < 10) ? "0" + std::to_string(minutes) : std::to_string(minutes);
	std::string s_seconds = (seconds < 10) ? "0" + std::to_string(seconds) : std::to_string(seconds);
	std::string s_time = s_minutes + ":" + s_seconds; //��:�b�̕�������쐬
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
	return (frame == 0);
}
