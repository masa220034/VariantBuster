#include "DamageEffect.h"
#include "Engine/Model.h"
#include "Engine/VFX.h"

DamageEffect::DamageEffect(GameObject* parent, const XMFLOAT3& position)
	: GameObject(parent, "DamageEffect"), hModel_(-1), position_(position)
{
}

void DamageEffect::Initialize()
{
	EmitterData data;
	data.textureFileName = "flashA_W.png";
	data.position = position_;
	data.delay = DELAY;
	data.number = NUMBER;
	data.lifeTime = LIFE_TIME;
	data.direction = DIRECTION;
	data.directionRnd = DIRECTION_RND;
	data.speed = SPEED;
	data.speedRnd = SPEED_RND;
	data.size = SIZE; 
	data.sizeRnd = SIZE_RND; 
	data.scale = SCALE;
	data.color = COLOR; 
	data.deltaColor = DELTA_COLOR;
	VFX::Start(data);
}

void DamageEffect::Update()
{
}

void DamageEffect::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void DamageEffect::Release()
{
}