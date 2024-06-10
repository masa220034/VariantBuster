#include "Graphics.h"
#include <iostream> // デバッグ用、実際の実装ではグラフィックスライブラリを使用

namespace Graphics
{
    void Initialize()
    {
        // ここにグラフィックスシステムの初期化コードを追加します
        std::cout << "Graphics system initialized." << std::endl;
    }

    void Shutdown()
    {
        // ここにグラフィックスシステムの終了コードを追加します
        std::cout << "Graphics system shutdown." << std::endl;
    }

    void DrawRect(int x, int y, int width, int height, Color color)
    {
        // デバッグ用の出力、実際にはグラフィックスライブラリを使用
        std::cout << "DrawRect: (" << x << ", " << y << ") "
            << "Width: " << width << ", Height: " << height
            << " Color: (" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")"
            << std::endl;

        // 例：Direct3DやOpenGLのコードをここに追加します
    }

    void DrawString(const std::string& text, int x, int y, Color color)
    {
        // デバッグ用の出力、実際にはグラフィックスライブラリを使用
        std::cout << "DrawString: \"" << text << "\" at (" << x << ", " << y << ") "
            << "Color: (" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")"
            << std::endl;

        // 例：Direct3DやOpenGLのコードをここに追加します
    }
}