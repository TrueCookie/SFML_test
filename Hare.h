#pragma once
#include "Animal.h"
#include <SFML/Graphics.hpp>
class Hare : virtual public Animal{
public:
	Hare();
	~Hare();
	int defMove();
};

