#ifndef SPAWNER_H
#define SPAWNER_H

#include "GameObjects/GameObject.h"

class Spawner : public GameObject
{

public:

	Spawner() = default;
	~Spawner() override = default;

	void Tick(int64_t deltaTime) override;

	int ChooseSide();
	void RandomLocation();
	void DoSpawn(int X, int Y);

	int64_t m_timer = 0;
	bool m_canSpawn = true;
};

#endif //SPAWNER_H
