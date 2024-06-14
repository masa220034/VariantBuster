#pragma once
#include "EnemyState.h"

class NormalState : public EnemyState {
public:
    void AttackPattern(Enemy* enemy) override;
};
