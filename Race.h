#pragma once
#include "Init.h"
#include "Animal.h"
#include "Hare.h"
#include "Turtle.h"
#include "Path.h"
#include <utility>
#include <string>
#include <SFML/Graphics.hpp>


class Race{
private:
	Path *path;
	Animal** racers;
	bool finish;
	std::pair<std::string, std::string> winner;
public:
	Race(Animal** animals);
	~Race();
	void move();
	//bool update();
	void process();
	void printEnergy();
	bool finished();
	void end();

	void moveToPoint(Animal *racer, sf::Vector2f goalPoint, float time);
};

