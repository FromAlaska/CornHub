// Display.cpp
// November 27, 2017
// This is the Display class. It handles the window function.
// Created by:
// 				Jim Samson(jasamson@alaska.edu)

#include "../include/Display.hpp"

// Display() Constructor
// See header for more documentation.
Display::Display() {
	man_.loadTexture("../resources/cornboy.png");
	loadTexture();
	window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Miraculous", 
		sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
	draw(man_);
	setTexture();
}

// draw() function
// See header for more documentation.
void Display::draw() {
	window.clear(); // Keep this first.
	// Put objects in here!
	draw(man_);
	window.display(); // Keep this last.
}

// draw() function
// See header for more documentation.
void Display::draw(const Corn::Sprite & obj) {
	window.draw(obj._spriteObject);
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