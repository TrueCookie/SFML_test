#pragma once
#include "Animal.h"
#include <SFML/Graphics.hpp>
class Turtle : virtual public Animal{
public:
	Turtle();
	~Turtle();
	int defMove();
};

