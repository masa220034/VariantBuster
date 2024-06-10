#include "UI.h"
#include "Graphics.h" // 仮想的なグラフィックスライブラリ

namespace UI
{
    void DrawRectangle(int x, int y, int width, int height, Color color)
    {
        // グラフィックスライブラリを使用して矩形を描画
        Graphics::DrawRect(x, y, width, height, color);
    }

    void DrawText(const std::string& text, int x, int y, Color color)
    {
        // グラフィックスライブラリを使用してテキストを描画
        Graphics::DrawString(text, x, y, color);
    }
}

