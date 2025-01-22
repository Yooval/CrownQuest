#pragma once

#include <SFML/Graphics.hpp>
#include "Gift.h"


class LoseTime: public Gift
{
public:
	using Gift::Gift;
	virtual void action(Board&);

protected:
};
