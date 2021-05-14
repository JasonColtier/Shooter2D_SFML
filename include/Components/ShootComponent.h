#ifndef SHOOTCOMPONENT_H
#define SHOOTCOMPONENT_H

#include <cstdint>
#include "Component.h"
#include "Managers/InputManager.h"

class ShootComponent : public Component
{
public:
	ShootComponent() = default;
	virtual ~ShootComponent() override = default;

	//gestion du délai entre les tirs
	virtual void TickComponent(int64_t deltaTime = 0) override;

	//on tire, overridé par les classes enfant
	virtual void ShootBullet(int initialAngle) = 0;
	//fonction overridée par les components enfant en fonction des spécificités de chaque arme
	virtual float GetWeaponFireRate() const { return 1; }
	virtual float GetWeaponShootNumber() const { return 1; }

public:
	//modifiées par les amélioration globales de partie, sont indépendantes des armes récupérées
	int m_shootNumber = 1; //nombre de tir quand on shoot, doit être incrémenté de 2 en 2
	float m_fireRate = 2.f; //vitesse de tir, plus c'est grand plus on tire souvent
	float m_dispersion = 15.f;//angle
	float m_damageMultiplier = 1.f;//TODO
	float m_velocityMultiplier = 1.f;//TODO
	bool m_wantToShoot = false;
	bool m_isPlayer = false;
	//Ajouter prise en compte de la portée de l'arme.

private:
	float m_timer = 0;
};
#endif //SHOOTCOMPONENT_H