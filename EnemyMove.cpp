#include "EnemyMove.h"

void EnemyMove::Move(Transform& transform, bool& moveUp)
{
    if (moveUp)
    {
        transform.position_.y += move;
        if (transform.position_.y >= moveUp_lim)
        {
            moveUp = false;
        }
    }
    else
    {
        transform.position_.y -= move;
        if (transform.position_.y <= moveDown_lim)
        {
            moveUp = true;
        }
    }
}

