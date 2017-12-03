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
	/*kernels_.resize(144);*/
	for(unsigned int i=0; i<cobSize;i++) {
		Corn::Sprite cornKernel;
		cornKernel.loadTexture("../resources/cornKernel.png");
		cornKernel._spriteObject.setPosition(50, 50);
		kernels_.push_back(cornKernel);
		//cornKernel.loadTexture("../resources/cornKernel.png");
		
	}
	man_.loadTexture("../resources/cornboy.png");
	//aDumbKernel.loadTexture("../resources/cornKernel.png");
	//loadTexture(kernels_,"../resources/cornKernel.png");
	//Corn::Sprite::loadTexture(kernels_,"../resources/cornKernel.png");
	//kernels_.loadTexture("../resources/cornKernel.png");
	cornCob_.loadTexture("../resources/Corncob01.png");
	//loadTexture();
	window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "CornHub", 
		sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	man_._spriteObject.setPosition(1280/2 - 75,50);
	cornCob_._spriteObject.setPosition(0, 720/2);
	//aDumbKernel._spriteObject.setPosition(0, 720/2);
	//kernels_._spriteObject.setPosition(50, 50);
	// for(unsigned int i=0;i<cobSize;i++) {
	// 	kernels_[i]._spriteObject.setPosition(50,50);
	// }
	setTexture();
}

// draw() function
// See header for more documentation.
void Display::draw() {
	for(unsigned int i=0;i<cobSize;i++) {
		kernels_[i]._spriteObject.setPosition(50,50);
	}
	window.clear(); // Keep this first.
	// Put objects in here!
	window.draw(man_._spriteObject);
	window.draw(cornCob_._spriteObject);

	for (unsigned int i = 0; i < kernels_.size(); i++)
	{

		window.draw(kernels_[i]._spriteObject);
	}
	//draw(aDumbKernel);
	// for(unsigned int i=0; i<cobSize; i++) {
	// 	draw(kernels_[i]);
	// }
	//draw(kernels_);
	window.display(); // Keep this last.
}

// draw() function
// See header for more documentation.
// void Display::draw(const Corn::Sprite  obj) {
// 	window.draw(obj._spriteObject);
// }

// void Display::draw(const Corn::Sprite  obj) {
// 	window.draw(obj->_spriteObject);
// }

void Display::draw(const vector<Corn::Sprite> & obj) {
	// for(auto iter = obj.begin(); iter != obj.end(); ++iter)
	// {
	// 	std::cout << "HELL NAH\n";
	// 	window.draw(iter->_spriteObject);
	// 	std::cout << "HELL YEA\n";
	// }
	// for (const auto &i : obj)
	// {
	// 	window.draw(*i);
	// }
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