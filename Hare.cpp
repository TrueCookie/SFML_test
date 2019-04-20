#include "Hare.h"

Hare::Hare(){
	_energy = 20;
	_name = 'H';
	_type = "hare";

	texture.loadFromFile("images/hareSL.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 295, 355));

	sprite.setPosition(60, 90);
	sprite.setScale(0.2, 0.2);
}

Hare::~Hare(){}

int Hare::defMove() {
	_energy -= 2;
	int randNum = defNum();
	if (randNum <= 2) {
		return 0;
	}
	else if(randNum >= 3 && randNum <= 4){
		return 9;
	}
	else if (randNum == 5) {
		return -12;
	}
	else if (randNum >= 6 && randNum <= 8) {
		return 1;
	}
	else if (randNum >= 9) {
		return -2;
	}
}