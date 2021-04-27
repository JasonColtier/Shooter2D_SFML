#ifndef SHOOTCOMPONENT_H
#define SHOOTCOMPONENT_H
#include <cstdint>


#include "Component.h"
#include "Managers/InputManager.h"

class GenericBullet;


class ShootComponent : public Component
{
public:
    ShootComponent();
    virtual ~ShootComponent() = default;

    //gestion du délai entre les tirs
    virtual void TickComponent(int64_t deltaTime = 0) override;

    //on tire, overridé par les classes enfant
    virtual void ShootBullet(int initialAngle);

    //quand on détecte un changement d'input
    void OnInputChanged(InputMapping input);

    //modifiées par les amélioration globales de partie, sont indépendantes des armes récupérées
    int g_shootNumber = 1; //nombre de tir quand on shoot, doit être incrémenté de 2 en 2
    float g_fireRate = 2.f; //vitesse de tir, plus c'est grand plus on tire souvent
    float g_damageMultiplier = 1.f;//TODO
    float g_velocityMultiplier = 1.f;//TODO
    

    //fonction overridée par les components enfant en fonction des spécificités de chaque arme
    virtual float GetWeaponFireRate() const { return 1; }
    virtual float GetWeaponShootNumber() const { return 1; }


private:

    bool wantToShoot = false;
    float timer = 0;
};
#endif