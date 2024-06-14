#pragma once
#include "BulletFactory.h"

class EnemyBulletFactory : public BulletFactory {
public:
    EnemyBullet* CreateBullet(GameObject* parent) override {
        return Instantiate<EnemyBullet>(parent);
    }
};
