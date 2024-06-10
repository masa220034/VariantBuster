#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include "Color.h"

namespace Graphics
{
    void Initialize(); // �O���t�B�b�N�X�V�X�e���̏�����
    void Shutdown();   // �O���t�B�b�N�X�V�X�e���̏I��

    void DrawRect(int x, int y, int width, int height, Color color); // ��`�̕`��
    void DrawString(const std::string& text, int x, int y, Color color); // �e�L�X�g�̕`��
}

#endif // GRAPHICS_H