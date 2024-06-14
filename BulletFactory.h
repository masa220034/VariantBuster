#pragma once

#include "EnemyBullet.h"
#include "EnemyBullet2.h"

class BulletFactory {
public:
    virtual ~BulletFactory() {}
    virtual EnemyBullet* CreateBullet(GameObject* parent) = 0;
};