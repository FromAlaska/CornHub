// InputManager.cpp
// November 27, 2017
// This is the input manager class. This checks for any input from the user.
// Created by:
// 				Jim Samson(jasamson@alaska.edu)

#include "../include/InputManager.hpp"
#include <iostream>

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

				if(event.key.code == sf::Keyboard::LControl && sf::Keyboard::RControl)
				{
					
				}

				if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
				{
					
					for (unsigned int i = 0; i < display_->kernels_.size(); i++)
					{
						std::cout << display_->kernels_[i]._spriteObject.getPosition().x << " ";
					}

					if (display_->getPositionX() < 1060)
					{	
					
						display_->man_._spriteObject.move(50,0);
						display_->draw(display_->man_);
					    
						
						
						//std::cout << "isPressed";
						//return isPressed = true;
					
					}
				}

				if(event.key.code == sf::Keyboard::A)
				{
					if (display_->getPositionX() <= 1100 && display_->getPositionX() > 60 )
					{	
						display_->man_._spriteObject.move(-50,0);
						display_->draw(display_->man_);
					
					}
				}
				

				break;
			}
			default:
			break;	
		}
	}
//	display_->isPressed = false;
	
}

