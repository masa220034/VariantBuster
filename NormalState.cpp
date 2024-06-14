#include "NormalState.h"
#include "Enemy.h"
#include "BulletFactory.h"

void NormalState::AttackPattern(Enemy* enemy)
{
    if (rand() % 100 == 0)
    {
        EnemyBullet* pEnemyBullet = enemy->bulletFactory->CreateBullet(enemy->GetParent());
        pEnemyBullet->SetPosition(enemy->GetPosition());
    }
}
