#include "Init.h"
#include "Race.h"
#include <ctime>
#include <iostream>

//#include <SFML/Graphics.hpp>
using namespace sf;

Race::Race(Animal** animals){
	path = new Path();
	racers = animals;
	finish = false;
}

Race::~Race(){
	delete path;
	delete[] racers;
}

/*bool Race::update() {
	time_t prevTime = 0;
	if (time(nullptr) - prevTime >= 1) {
		move();
	}
	prevTime = time(nullptr);
	return true;
}*/

/*void Race::process() {
	time_t prevTime = 0;
	while(1){
		if (time(nullptr) - prevTime >= 1) {
			path->update(racers);
			if (path->getFinishFlag()) {
				break;
			}
			path->print();
			this->printEnergy();
			prevTime = time(nullptr);
		}
	}
	winner = path->getWinner();
	end();
}*/

void Race::moveToPoint(Animal *racer, Vector2f goalPoint, float time) {
	if (racer->getSprite().getPosition().x < goalPoint.x) {
		racer->setCurrentFrame(0.005*time);
		if (racer->getCurrentFrame() > 13) { racer->setCurrentFrame(13); }
		racer->getSprite().setTextureRect(IntRect(295 * (int)racer->getCurrentFrame(), 0, 295, 355));
		racer->getSprite().move(0.2*time, 0);
	}
}

void Race::process() {
	RenderWindow window(sf::VideoMode(1024, 768), "Game", Style::Default);
	Clock clock;
	int i = 0;
	while (window.isOpen()) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		
			static int goalPointX;
			if (racers[i]->getMovinFlag() == false){//first iter
				finish = racers[i]->setPos();
				goalPointX = racers[i]->getPos() * 10 + 60;
				racers[i]->setMovinFlag(true);
			}else if ((racers[i]->getPos() * 10 + 60) == goalPointX) {//if racer reach the direction
				racers[i]->setMovinFlag(false);
				i >= Init::racersNum ? i = 0 : ++i;
			}else if((racers[i]->getPos() * 10 + 60) < goalPointX){//if racer didn't reach the direction
				moveToPoint(racers[i], Vector2f(goalPointX, 0), time);
			}
			window.draw(racers[i]->getSprite());
		
		window.display();
	}
	winner = path->getWinner();
	end();
}

void Race::end() {
	std::cout << winner.first << " " << winner.second << " win!!!" << std::endl << "Congratulations!!!";
}

void Race::move() {
	for (int i = 0; i < Init::racersNum; ++i) {
		finish = racers[i]->setPos();
		if (finish) {
			winner = std::make_pair(racers[i]->getType(), racers[i]->getName());
		}
	}
}

void Race::printEnergy() {
	std::cout << "| Energy: ";
	for (int i = 0; i < Init::racersNum; ++i) {
		std::cout << racers[i]->getName() << ": " << racers[i]->getEnergy() << " / ";
	}std::cout << std::endl;
}

bool Race::finished() {
	return finish;
}