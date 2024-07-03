#ifndef FADE_H
#define FADE_H

class Fade
{
private:
	float duration; //�t�F�[�h�C��/�A�E�g�̏��v����
	float opacity;  //���݂̕s�����x
	bool isFadeIn;  //�t�F�[�h�C�����𔻒�
	bool isActive;  //�t�F�[�h���ʂ��A�N�e�B�u���ǂ���
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


