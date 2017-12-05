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

	man_._spriteObject.setPosition(1240/2 - 75,50);
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

float Display::getPositionX(){
	std::cout << "   " <<man_._spriteObject.getPosition().x;
	return man_._spriteObject.getPosition().x;
}

float Display::getPositionY(){
	for(unsigned i = 0; i < kernels_.size(); i++){
		std::cout << "     "<<kernels_[i]._spriteObject.getPosition().y;
		return kernels_[i]._spriteObject.getPosition().y;
	}
}

float Display::getKernelPositionX(Corn::Sprite & kernel){
		for(unsigned i = 0; i < kernels_.size(); i++){
		std::cout << "     "<<kernels_[i]._spriteObject.getPosition().x;
		return kernels_[i]._spriteObject.getPosition().x;
	}

}

void Display::kernelPositioning(std::vector<Corn::Sprite> &v)
{
	unsigned int row;
	int _x =0;
	int _y = 360;
	

	for (unsigned int horizontal = 0; horizontal < 72; horizontal++) {
		v[horizontal]._spriteObject.setPosition(40+_x, _y);
		_x+=50;
		if (horizontal == 23){
			_y = 410;
			_x=0;
		} 
		if (horizontal == 47){
			_y = 460;
			_x = 0;
		}
	}
}
		
		
	