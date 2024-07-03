#ifndef FADE_H
#define FADE_H

class Fade
{
private:
	float duration; //フェードイン/アウトの所要時間
	float opacity;  //現在の不透明度
	bool isFadeIn;  //フェードインかを判定
	bool isActive;  //フェード効果がアクティブかどうか
	std::chrono::time_point<std::chrono::high_resolution_clock> start;

	void fade();

public:
	Fade(float durarion);

	void FadeIn();

	void FadeOut();

	float getOpacity() const;

	void Update();

	void Draw() const;
};

#endif // !FADE_H


