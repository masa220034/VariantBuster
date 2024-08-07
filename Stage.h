#pragma once
#include "Engine/GameObject.h"

class Stage : public GameObject
{
private:
    int hBackGround_;
    int hGround_;
    int IMB = 0; //I=�摜�AM=���f���AB=BGM
public:
    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    int GetModelHandle() { return hGround_; }
};