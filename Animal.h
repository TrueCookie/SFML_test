#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Animal{
protected:
	char _name;
	int _energy;
	int _pos;
	std::string _type;
	bool sleepFlag;
	bool movinFlag;

	sf::Texture texture;
	sf::Sprite sprite;
	float currentFrame;

	Animal();
	~Animal();
public:
	int defNum();
	virtual int defMove() = 0;
	bool setPos();
	int getPos();
	void decreaseEnergy(int val);
	void setEnergy(int val);
	int getEnergy();
	bool isSleep();
	void getUp();
	std::string getType();
	char getName();
	bool isOut();
	bool isFinished();
	void eatSnack();
	void bite();

	sf::Sprite getSprite();
	void setCurrentFrame(float num);
	float getCurrentFrame();
	bool getMovinFlag();
	void setMovinFlag(bool val);
};