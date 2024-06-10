#ifndef COLOR_H
#define COLOR_H

struct Color
{
    int r, g, b, a;
    Color(int red, int green, int blue, int alpha = 255) : r(red), g(green), b(blue), a(alpha) {}

    static const Color Black;
    static const Color White;
    static const Color Red;
};

const Color Color::Black = Color(0, 0, 0);
const Color Color::White = Color(255, 255, 255);
const Color Color::Red = Color(255, 0, 0);

#endif // COLOR_H