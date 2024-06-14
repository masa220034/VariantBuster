#pragma once

#include "Engine/Transform.h"

class EnemyMoveStrategy {
public:
    virtual ~EnemyMoveStrategy() {}
    virtual void Move(Transform& transform, bool& moveUp) = 0;
};
