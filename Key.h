#pragma once
#include "Engine/GameObject.h"
#include <DirectXMath.h>
#include <d3d11.h>

class Key : public GameObject
{
    int hKey_;
    int IMB = 0; //I=画像、M=モデル、B=BGM

    //-----キーの大きさの設定-----
    XMFLOAT3 KEY_SCL = XMFLOAT3(0.5f, 0.5f, 0.5f);
    //----------------------------

    //-----コライダーの中心位置と大きさの設定-----
    XMFLOAT3 BASE_POS = XMFLOAT3(-0.1f, 0.4f, 0.3f);
    float c_scl = 0.3f;
    //--------------------------------------------

    Transform tKey;
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