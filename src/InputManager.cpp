// InputManager.cpp
// November 27, 2017
// This is the input manager class. This checks for any input from the user.
// Created by:
// 				Jim Samson(jasamson@alaska.edu)

#include "../include/InputManager.hpp"

// Input() constructor
// See header for more documentation.
Input::Input() {
	display_ = make_unique<Display>();
}

// mouseOverObject() function
// See header for more documentation.
void Input::mouseOverObject()
{

}

// clickOnSprite() constructor
// See header for more documentation.
bool Input::clickOnSprite(sf::Sprite, int, int) {
	return true; // Dummy function
}

// handleInput() function
// See header for more documentation.
void Input::handleInput() {
	sf::Event event;
	while (display_->window.pollEvent(event)) {
		auto mousePosX = sf::Mouse::getPosition(display_->window).x; // x position
		auto mousePosY = sf::Mouse::getPosition(display_->window).y; // y position

		switch (event.type) {
			case sf::Event::Closed: {
				display_->window.close();
				break;
			}

			// Key Pressed
			case sf::Event::KeyPressed: {
				if (event.key.code == sf::Keyboard::Escape) {
					display_->window.close();
				}
				break;
			}
			default:
			break;	
		}
	}
	return;
}