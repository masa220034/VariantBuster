#include "EnemyBullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/BoxCollider.h"

//�R���X�g���N�^
EnemyBullet::EnemyBullet(GameObject* parent)
    :GameObject(parent, "EnemyBullet"), hModel_(-1), eBulletSound_(-1)
{
}

//�f�X�g���N�^
EnemyBullet::~EnemyBullet()
{
}

//������
void EnemyBullet::Initialize()
{
    hModel_ = Model::Load("eBullet.fbx");
    assert(hModel_ >= IMB);

    eBulletSound_ = Audio::Load("eBulletSound.wav");
    assert(eBulletSound_ >= IMB);

    transform_.scale_ = BULLET_SCL;

    BoxCollider* collision = new BoxCollider(BASE_POS, COLLIDER_SIZE);
    AddCollider(collision);

    startTime_ = std::chrono::steady_clock::now();
    soundPlayed_ = false;
}

//�X�V
void EnemyBullet::Update()
{
    transform_.position_.x -= v_shot;

    if (!soundPlayed_) 
    {
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime_).count();

        // �o�ߎ��Ԃ�0.5�b�ȏォ�ǂ������`�F�b�N
        if (elapsedTime >= 500)
        { 
            Audio::Stop(eBulletSound_);
            soundPlayed_ = true;
        }
        else
        {
            Audio::Play(eBulletSound_);
            soundPlayed_ = false;
        }
    }

    if (transform_.position_.x >= limitPos)
    {
        KillMe();
    }

    
}

//�`��
void EnemyBullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void EnemyBullet::Release()
{
}