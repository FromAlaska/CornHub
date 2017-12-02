// Display.cpp
// November 27, 2017
// This is the Display class. It handles the window function.
// Created by:
// 				Jim Samson(jasamson@alaska.edu)

#include "../include/Display.hpp"

// Display() Constructor
// See header for more documentation.

// TODO, organize this in a manner that makes sense
Display::Display() {
	kernels_.resize(100);
	man_.loadTexture("../resources/cornboy.png");
	//Corn::Sprite::loadTexture(kernels_,"../resources/cornKernel.png");
	//corn_.loadTexture(....)
	//kernels_.loadTexture("../resources/corKernel.png");
	for (unsigned i = 0; i < kernels_.size(); i++)
	{
		kernels_[i].loadTexture("../resources/corKernel.png");
	}

	loadTexture();
	window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "CornHub", 
		sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	man_._spriteObject.setPosition(1280/2,0);
	setTexture();
}

// draw() function
// See header for more documentation.
void Display::draw() {
	window.clear(); // Keep this first.
	// Put objects in here!
	draw(man_);
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
void Display::loadTexture() {

}

// setTexture() function
// See header for more documentation.
void Display::setTexture() {

}

// setText function
// See header for more documentation.
void Display::setText(sf::Text&, const sf::Color&, float x, float y) {

}