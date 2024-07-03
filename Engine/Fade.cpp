#include "Fade.h"
#include <iostream>
#include <chrono>
#include <thread>

Fade::Fade(float duration)
	:duration(duration), opacity(0.0f), isFadeIn(true), isActive(false)
{
}

void Fade::FadeIn()
{
	isFadeIn = true;
	opacity = 0.0f;
	isActive = true;
	start = std::chrono::high_resolution_clock::now();
}

void Fade::FadeOut()
{
	isFadeIn = false;
	opacity = 1.0f;
	isActive = true;
	start = std::chrono::high_resolution_clock::now();
}

float Fade::getOpacity() const
{
	return opacity;
}

void Fade::Update()
{
	if (isActive)
	{
		fade();
	}
}

void Fade::Draw() const
{
	if (isActive)
	{
		std::cout << "Current opacity: " << opacity << std::endl;
	}
}

void Fade::fade()
{
	auto now = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> elapsed = now - start;
	float progress = elapsed.count() / duration;

	if (isFadeIn)
	{
		opacity = std::min(1.0f, progress);
		if (opacity >= 1.0f)
		{
			isActive = false;
		}
	}
	else
	{
		opacity = std::max(0.0f, 1.0f - progress);
		if (opacity <= 0.0f)
		{
			isActive = false;
		}
	}
}