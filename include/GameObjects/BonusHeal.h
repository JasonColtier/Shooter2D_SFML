#ifndef BONUSHEAL_H
#define BONUSHEAL_H

#include "IBonus.h"

class BonusHeal : public IBonus
{

public:
	BonusHeal() = default;
	~BonusHeal() override = default;

	virtual TypeId getTypeId() override { return getClassTypeId(); }
	static TypeId getClassTypeId() { return 4; }

	int pdtVie = 1;
};

#endif //BONUSHEAL_H