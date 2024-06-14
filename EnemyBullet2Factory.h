#pragma once
#include "BulletFactory.h"

class EnemyBullet2Factory : public BulletFactory {
public:
    EnemyBullet* CreateBullet(GameObject* parent) override {
        return Instantiate<EnemyBullet2>(parent);
    }
};
