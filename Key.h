#pragma once
#include "Engine/GameObject.h"
#include <DirectXMath.h>
#include <d3d11.h>

class Key : public GameObject
{
    int hKey_;
public:
    //コンストラクタ
    Key(GameObject* parent);

    //デストラクタ
    ~Key();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetPosition(const DirectX::XMFLOAT3& position);

    DirectX::XMFLOAT3 GetPosition() const;
};