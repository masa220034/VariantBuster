#pragma once
#include "EnemyState.h"

class EnemyEnragedState : public EnemyState 
{
public:
    void AttackPattern(Enemy* enemy) override;
};
