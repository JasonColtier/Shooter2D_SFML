#include "Components/Sniper.h"

#include <SFML/Graphics/Sprite.hpp>

#include "GameWindow.h"
#include "GameObjects/Bullet.h"
#include "GameObjects/PlayerBullet.h"
#include "Managers/AudioManager.h"
#include "Managers/TextureManager.h"


void Sniper::ShootBullet(int initialAngle)
{
    GameWindow::GetGameLevel()->SpawnActor<PlayerBullet>(Owner->m_position,sf::Vector2f(0,0),10,Owner->m_rotation + static_cast<float>(initialAngle),TextureManager::GetTexturePtr(TextureManager::ETextures::Bullet),true); 
    AudioManager::PlaySound(AudioManager::ESounds::FireBullet, 10);
}
