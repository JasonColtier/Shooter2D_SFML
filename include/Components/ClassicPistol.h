#ifndef CLASSICPISTOL_H
#define CLASSICPISTOL_H

#include "ShootComponent.h"

class ClassicPistol : public ShootComponent
{
public:
	ClassicPistol(Character* characterShooter);
	void ShootBullet(int initialAngle) override;
};

#endif //CLASSICPISTOL_H