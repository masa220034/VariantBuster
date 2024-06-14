#include "EnemyEnragedState.h"
#include "Enemy.h"
#include "BulletFactory.h"

void EnemyEnragedState::AttackPattern(Enemy* enemy)
{
    enemy->MoveLeft();
    if (enemy->AtLeftLimit())
    {
        enemy->Rotate();
        if (rand() % 100 == 0)
        {
            EnemyBullet2* pEnemyBullet2 = enemy->bulletFactory2->CreateBullet(enemy->GetParent());
            pEnemyBullet2->SetPosition(enemy->GetPosition());
        }
    }
}
