#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include <SFML/Graphics/Texture.hpp>


#include "Bullet.h"
#include "Components/CollisionHandler.h"
#include "GameObjects/GameObject.h"
#include "Managers/TextureManager.h"

class PlayerBullet : public Bullet
{
public:

	PlayerBullet(sf::Vector2f position, sf::Vector2f offsetPos = sf::Vector2f(0.f, 0.f), float scale = 1.f, float rotation = 0.f,sf::Texture* texture = TextureManager::GetTexturePtr(TextureManager::ETextures::Bullet),bool piercing = false)
		: Bullet(position,offsetPos,scale,rotation,texture,piercing)
	{
		m_collisionHandler->m_eType = CollisionType::PlayerProjectileChannel;
		m_collisionHandler->m_lExcludedCollisionType = std::vector<CollisionType>({CollisionType::PlayerChannel, CollisionType::EnemyProjectileChannel, CollisionType::PlayerProjectileChannel });
	};
	virtual ~PlayerBullet() override = default;

};
#endif //BULLET_H