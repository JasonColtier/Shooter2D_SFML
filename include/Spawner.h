#ifndef SPAWNER_H
#define SPAWNER_H

#include "GameObjects/GameObject.h"

class Spawner : public GameObject
{

public:

	Spawner();
	~Spawner() override = default;

	void Tick(int64_t deltaTime) override;

	int ChooseSide();
	void RandomLocation();
	void DoSpawn(int X, int Y);

	int64_t Timer = 0;

private:

};

#endif //SPAWNER_H
