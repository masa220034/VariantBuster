#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include "Color.h"

namespace Graphics
{
    void Initialize(); // グラフィックスシステムの初期化
    void Shutdown();   // グラフィックスシステムの終了

    void DrawRect(int x, int y, int width, int height, Color color); // 矩形の描画
    void DrawString(const std::string& text, int x, int y, Color color); // テキストの描画
}

#endif // GRAPHICS_H