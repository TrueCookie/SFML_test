#include "Animal.h"
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

Animal::Animal() {
	_energy = 20;
	_pos = 0;
	sleepFlag = false;

	movinFlag = false;
	currentFrame = 0;
}

Animal::~Animal() {}

int Animal::defNum() {
	srand((unsigned int)time(nullptr));
	return rand() % 10 + 1;
}

bool Animal::isOut() {
	return _pos < 0;
}

bool Animal::isFinished() {
	return _pos >= 69;
}

bool Animal::setPos() {
	_pos += defMove();
	if (_energy <= 0) {
		_energy = 0;
		sleepFlag = true;
	}
	if (isOut()) {
		_pos = 0;
		return false;
	}else if (isFinished()) {
		_pos = 69;
		return true;
	}else {
		return false;
	}
}

int Animal::getPos() {
	return _pos;
}

void Animal::decreaseEnergy(int val) {
	_energy -= val;
	if (_energy < 0) {
		_energy = 0;
	}
}

void Animal::setEnergy(int val) {
	_energy = val;
}

void Animal::getUp() {
	sleepFlag = false;
}

bool Animal::isSleep() {
	return sleepFlag;
}

int Animal::getEnergy() {
	return _energy;
}

std::string Animal::getType() {
	return _type;
}

char Animal::getName() {
	return _name;
}

void Animal::eatSnack() {
	if (_energy >= 15) {
		_energy = 20;
	}
	else {
		_energy += 5;
	}
}

void Animal::bite() {
	_energy -= 10;
}

Sprite Animal::getSprite() {
	return sprite;
}

void Animal::setCurrentFrame(float num) {
	currentFrame += num;
}

float Animal::getCurrentFrame() {
	return currentFrame;
}

bool Animal::getMovinFlag() {
	return movinFlag;
}
void Animal::setMovinFlag(bool val) {
	movinFlag = val;
}