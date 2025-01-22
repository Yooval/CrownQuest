#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string.h>
#include <filesystem>
#include <stdio.h>
#include "Gift.h"


class KillDwarves: public Gift
{
public:
	using Gift::Gift;
	virtual void action(Board&);
	
protected:
};
