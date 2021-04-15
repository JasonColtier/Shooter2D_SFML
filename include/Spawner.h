#include "GameObject.h"


class Spawner : public GameObject
{

public:

	Spawner();
	~Spawner() = default;

	void Tick(int64_t deltaTime) override;

	int ChooseSide();
	void RandomLocation();
	void DoSpawn(int X, int Y);

	int64_t Timer = 0;

private:

	

};