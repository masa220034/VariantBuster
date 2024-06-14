#pragma once

class Enemy;

class EnemyState {
public:
    virtual ~EnemyState() {}
    virtual void AttackPattern(Enemy* enemy) = 0;
};