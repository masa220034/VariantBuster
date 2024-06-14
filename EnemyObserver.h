#pragma once

class EnemyObserver {
public:
    virtual ~EnemyObserver() {}
    virtual void OnNotify(float newHp) = 0;
};
