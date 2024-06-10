#include "UI.h"
#include "Graphics.h" // ���z�I�ȃO���t�B�b�N�X���C�u����

namespace UI
{
    void DrawRectangle(int x, int y, int width, int height, Color color)
    {
        // �O���t�B�b�N�X���C�u�������g�p���ċ�`��`��
        Graphics::DrawRect(x, y, width, height, color);
    }

    void DrawText(const std::string& text, int x, int y, Color color)
    {
        // �O���t�B�b�N�X���C�u�������g�p���ăe�L�X�g��`��
        Graphics::DrawString(text, x, y, color);
    }
}

