#ifndef BONUSHEAL_H
#define BONUSHEAL_H

#include "IBonus.h"

class BonusHeal final: public IBonus
{
public:
	BonusHeal() = default;
	~BonusHeal() override = default;

	TypeId GetTypeId() override { return GetClassTypeId(); }
	static TypeId GetClassTypeId() { return "BonusHeal"; }

public:
	int m_pdtVie = 1;
};
#endif //BONUSHEAL_H