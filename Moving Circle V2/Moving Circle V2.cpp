#include <iostream>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "Moving Circle V2");
	sf::CircleShape circle(50.f);
	circle.setFillColor(sf::Color::Blue);
	circle.setPointCount(1000);
	circle.setPosition(300.f, 300.f);

	float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	cout << y;
	cout << x;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		cout << y;
		cout << x;

		if (x > 0.1) {
			circle.move(1.f, 0.f);
		}
		else if (x < -0.1) {
			circle.move(-1.f, 0.f);
		}
		else if (y > 0.1) {
			circle.move(0.f, 1.f);
		}
		else if (y < -0.1) {
			circle.move(0.f, -1.f);
		}
		else
		{
			circle.setPosition(300.f, 300.f);
		}
		// This is the reset to origin part: to remove change "else if" to "if" and remove "else"


		window.clear();
		window.draw(circle);
		window.display();
	}


	return 0;
}