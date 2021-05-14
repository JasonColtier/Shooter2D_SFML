#include "GameObjects/SniperBullet.h"
#include "Enemy.h"
#include "Components/RenderHandler.h"

SniperBullet::SniperBullet(sf::Vector2f position, sf::Vector2f offsetPos, float scale, float rotation) : Bullet(1, position, rotation, scale, offsetPos)
{
	m_damage *= 3;
	m_speed *= 3;

	auto* Sprite = GetRenderHandler()->GetRenderedItemWithKey<sf::Sprite>("bullet");

	if (Sprite)
	{
		Sprite->setScale(sf::Vector2f(10, 10));
	}

}

//void SniperBullet::OnCollision(sf::Vector2f hitPoint, GameObject* otherObject)
//{
//    if(typeid(*otherObject) == typeid(Enemy))
//    {
//        auto enemy = dynamic_cast<Enemy*>(otherObject);
//        enemy->m_lifeComponent->ModifyHealth(-m_damage*m_damageMultiplier);
//    }
//}
