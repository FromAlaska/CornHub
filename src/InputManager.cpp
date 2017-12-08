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
					if(!rowSwitchSFXBuffer_.loadFromFile("../resources/sounds/rowChange.wav"))
						std::cout << "Failed to load rowChange sound"<<std::endl;
					else
						rowSwitchSFX_.setBuffer(rowSwitchSFXBuffer_);
					rowSwitchSFX_.setPitch(.8);
					rowSwitchSFX_.setVolume(50);
					rowSwitchSFX_.play();
					display_->isRotating = true;
				}

				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if(!eatKernelSFXBuffer_.loadFromFile("../resources/sounds/eating.wav"))
						std::cout << "Failed to load rowChange sound"<<std::endl;
					else
						eatKernelSFX_.setBuffer(eatKernelSFXBuffer_);
					eatKernelSFX_.setPitch(.8);
					eatKernelSFX_.setVolume(50);
					eatKernelSFX_.play();
					display_->isPressedSpace = true;
				}
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
				{
					
				
			

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

			//KeyReleased event so we can change the boolean to false upon release of the Space Key
			//Hitting the Space Key means the dude is hungry and he will start eating all the corn
			//When you release the space key the dude dont want to eat no moe.
			case sf::Event::KeyReleased:

                if (event.key.code == sf::Keyboard::Space)
				{
					 display_->isPressedSpace = false;
					 
				}

				if(event.key.code == sf::Keyboard::LControl && sf::Keyboard::RControl)
				{
					display_->isRotating = false;
				}

                break; 
				default:	

			break;	
		}
	}
}


