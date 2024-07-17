#pragma once
#include "Engine/GameObject.h"

class TutorialGround : public GameObject
{
private:
    int hGround_;

    XMFLOAT3 GROUND_POSITION = XMFLOAT3(0.0f, -2.5f, 0.0f);

    Transform tGround;
public:
    TutorialGround(GameObject* parent);

    ~TutorialGround();

    void Initialize() override;

    void Update() override;

    void Draw() override;

    void Release() override;

    int GetModelHandle() { return hGround_; }
};
