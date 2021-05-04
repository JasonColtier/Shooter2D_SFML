#include "Components/ClassicPistol.h"


#include "GameWindow.h"
#include "GameObjects/Bullet.h"
#include "Managers/AudioManager.h"

ClassicPistol::ClassicPistol()
{
    g_shootNumber = 1;
    g_fireRate = 2.f;
    g_dispersion = 15.f;
}

void ClassicPistol::ShootBullet(int initialAngle)
{
    auto level = GameWindow::GetGameLevel();
    Bullet* bullet = level->SpawnActor<Bullet>();
    bullet->position = Owner->position;
    bullet->rotation = Owner->rotation + initialAngle;

    AudioManager::PlaySound(AudioManager::FireBullet);

}
