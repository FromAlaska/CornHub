// Display.cpp
// November 27, 2017
// This is the Display class. It handles the window function.
// Created by:
// 				Jim Samson(jasamson@alaska.edu)

#include "../include/Display.hpp"

// Display() Constructor
// See header for more documentation.

// TODO, organize this in a manner that makes sense

int cobSize = 10000;

Display::Display() {
	kernels_.resize(144);

	man_.loadTexture("../resources/cornboy.png");
	cornCob_.loadTexture("../resources/Corncob01.png");

	loadTexture(kernels_,"../resources/cornKernel.png");

	//loadTexture();
	window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "CornHub", 
		sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	man_._spriteObject.setPosition(1280/2 - 75,50);
	cornCob_._spriteObject.setPosition(0, 720/2);
	kernelPositioning(kernels_);

	setTexture();
}

// draw() function
// See header for more documentation.
void Display::draw() {

	window.clear(); // Keep this first.
	// Put objects in here!
	draw(man_);
	draw(cornCob_);
	draw(kernels_);

	window.display(); // Keep this last.
}

// draw() function
// See header for more documentation.
void Display::draw(const Corn::Sprite & obj) {
	window.draw(obj._spriteObject);
}

void Display::draw(const vector<Corn::Sprite> & obj) {
	for(auto iter = obj.begin(); iter != obj.end(); ++iter)
	{
		window.draw(iter->_spriteObject);
	}
}

// update() function
// See header for more documentation.
void Display::update() {

}

// loadTexture() function
// See header for more documentation.
void Display::loadTexture(vector<Corn::Sprite>& obj, string && nameOfFile) {
	for(auto iterator = obj.begin(); iterator != obj.end(); ++iterator)
		{
			if (!iterator->_textureObject.loadFromFile(nameOfFile))
			{ std::cout << "cannot load " << nameOfFile << std::endl; }

			iterator->_spriteObject.setTexture(iterator->_textureObject);
		}
}

// setTexture() function
// See header for more documentation.
void Display::setTexture() {

}

// setText function
// See header for more documentation.
void Display::setText(sf::Text&, const sf::Color&, float x, float y) {

}

void Display::kernelPositioning(std::vector<Corn::Sprite> &v)
{
	for(unsigned int row =0; row<=23; row++) {
		for (unsigned int col =0; col<6; col++) {
			v[col+row]._spriteObject.setPosition(20+(50*row),((720/2)+50*col));
		}
	}
}