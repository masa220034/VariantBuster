#pragma once
#include "EnemyMoveStrategy.h"

class EnemyMove : public EnemyMoveStrategy 
{
private:

    //-----“G‚Ì“®‚«‚ÉŠÖ‚·‚éİ’è-----
    float move = 0.05f;
    float moveUp_lim = 2.0f;
    float moveDown_lim = 0.0f;
    //------------------------------

public:
    void Move(Transform& transform, bool& moveUp) override;
};