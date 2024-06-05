#include "DamageEffect.h"
#include "Engine/Model.h"
#include "Engine/VFX.h"

DamageEffect::DamageEffect(GameObject* parent)
	: GameObject(parent, "DamageEffect"), hModel_(-1)
{
}

void DamageEffect::Initialize()
{
	EmitterData data;
	data.textureFileName = "flashA_W.png";
	data.delay = 0;
	data.number = 80;
	data.lifeTime = 30;
	data.direction = XMFLOAT3(0, 1, 0);
	data.directionRnd = XMFLOAT3(90, 90, 90);
	data.speed = 0.1f;
	data.speedRnd = 0.8;
	data.size = XMFLOAT2(0.3, 0.3); // ”ÍˆÍ‚ğ¬‚³‚­‚·‚é
	data.sizeRnd = XMFLOAT2(0.2, 0.2); // ”ÍˆÍ‚ğ¬‚³‚­‚·‚é
	data.scale = XMFLOAT2(1.5, 1.5); // –¾‚é‚³‚ğ‘‚â‚·
	data.color = XMFLOAT4(1.0, 0.0, 1.0, 0.7); // –¾‚é‚³‚ğ‘‚â‚·
	data.deltaColor = XMFLOAT4(0, 0, 0, -0.003);
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