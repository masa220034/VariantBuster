#pragma once
#include "Engine/GameObject.h"

class TutorialGround : public GameObject
{
private:
    int hGround_;
    int IMB = 0; //I=画像、M=モデル、B=BGM
public:
    TutorialGround(GameObject* parent);

    ~TutorialGround();

    void Initialize() override;

    void Update() override;

    void Draw() override;

    void Release() override;

    int GetModelHandle() { return hGround_; }
};
