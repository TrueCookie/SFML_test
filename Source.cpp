#include <SFML/Graphics.hpp>

using namespace sf;

/*void moveToPoint(Animal racer, Vector2f goalPoint, float time) {
	if (racer.sprite.getPosition().x < goalPoint.x) {
		racer.currentFrame += 0.005*time;
		if (racer.currentFrame > 13) { racer.currentFrame -= 13; }
		racer.sprite.setTextureRect(IntRect(295 * (int)racer.currentFrame, 0, 295, 355));
		racer.sprite.move(0.2*time, 0);
	}
}*/

int output(){
	//RenderWindow window(sf::VideoMode(1024, 768), "Game", Style::Default);

	Texture hareTxtr;
	hareTxtr.loadFromFile("images/hareSL.png");
	Texture turtleTxtr;
	turtleTxtr.loadFromFile("images/turtleSL.png");

	Sprite hareSprt;
	hareSprt.setTexture(hareTxtr);

	hareSprt.setTextureRect(IntRect(0,0,295,355));

	hareSprt.setPosition(60, 90);
	hareSprt.setScale(0.2, 0.2);

	Clock clock;
	float currentFrame = 0;

	/*while (window.isOpen()){
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		int goalPointX = 800;	//goal point = new racer.pos
		Vector2f goalPoint(goalPointX,0);
		moveToPoint();

		window.clear();
		window.draw(hareSprt);
		window.display();
	}*/
	return 0;
}