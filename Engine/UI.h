#ifndef ENGINE_UI_H
#define ENGINE_UI_H

#include <string>
#include "Color.h"

namespace UI
{
    void DrawRectangle(int x, int y, int width, int height, Color color);
    void DrawText(const std::string& text, int x, int y, Color color);
}

#endif // ENGINE_UI_H

