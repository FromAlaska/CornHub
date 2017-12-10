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
static int kernelsEaten = 0;


Display::Display() {

	if (!font.loadFromFile("../resources/Sansation_Bold.ttf")){
		std::cout << "Couldn't load file" << std::endl;
	}
	atext.setFont(font);
	atext.setCharacterSize(20);
	atext.setStyle(sf::Text::Bold);
	atext.setColor(sf::Color::White);
	atext.setPosition(50,50);
	kernels_.resize(144);

	man_.loadTexture("../resources/cornboy.png");
	cornCob_.loadTexture("../resources/Corncob01.png");

	loadTexture(kernels_,"../resources/cornKernel.png");

	//loadTexture();
	window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "CornHub", 
		sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(10);

	man_._spriteObject.setPosition(1240/2 - 75,50);
	cornCob_._spriteObject.setPosition(0, 720/2);
	kernelPositioning(kernels_);

	setTexture();
}

time_t Display::clockTime(){
	__asm__("mov $201, %rax\n"
			"xor %rdi, %rdi\n"
			"syscall\n"
			);
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

void Display::draw(sf::Text & atext){
	time_t _systemClock = clockTime();
	time (&_systemClock);
	atext.setString(ctime (&_systemClock));
	window.draw(atext);
}

// update() function
// See header for more documentation.
void Display::update() {


	for (unsigned int i = 0; i < kernels_.size(); i++)
	{
		//std::cout << kernels_[i]._spriteObject.getPosition().x;
		if (kernels_[i]._spriteObject.getPosition().x  <= man_._spriteObject.getPosition().x+100
				&& kernels_[i]._spriteObject.getPosition().x >= man_._spriteObject.getPosition().x-50 
				&& kernels_[i]._spriteObject.getPosition().y == 360 && isPressedSpace)
		{
			kernels_[i]._spriteObject.setPosition(10000,10000);
			kernelsEaten++;
			std::cout<< "Kernels eaten =" << kernelsEaten << std::endl;
			if(kernelsEaten>=120)
			{
					{
					if(!theGongBuffer_.loadFromFile("../resources/sounds/gameOverSound.wav"))
						std::cout << "Failed to load the gameOverSound sound"<<std::endl;
					else
						theGong_.setBuffer(theGongBuffer_);
					theGong_.setPitch(.8);
					theGong_.setVolume(100);
					theGong_.play();
				}
			}

		}
	}

	if(isRotating)
	{
		for (unsigned int i = 0; i < kernels_.size(); i++)
		{
			if(kernels_[i]._spriteObject.getPosition().y == 360)
			{
				kernels_[i]._spriteObject.setPosition(kernels_[i]._spriteObject.getPosition().x, 1810);
			}

			if(kernels_[i]._spriteObject.getPosition().y == 410)
			{
				kernels_[i]._spriteObject.setPosition(kernels_[i]._spriteObject.getPosition().x, 360);
			}

			if(kernels_[i]._spriteObject.getPosition().y == 460)
			{
				kernels_[i]._spriteObject.setPosition(kernels_[i]._spriteObject.getPosition().x, 410);
			}

			if(kernels_[i]._spriteObject.getPosition().y == 1510)
			{
				kernels_[i]._spriteObject.setPosition(kernels_[i]._spriteObject.getPosition().x, 460);
			}

			if(kernels_[i]._spriteObject.getPosition().y == 1610)
			{
				kernels_[i]._spriteObject.setPosition(kernels_[i]._spriteObject.getPosition().x, 1510);
			}

			if(kernels_[i]._spriteObject.getPosition().y == 1810)
			{
				kernels_[i]._spriteObject.setPosition(kernels_[i]._spriteObject.getPosition().x, 1610);
			}
	

		}
	}

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
	return man_._spriteObject.getPosition().x;
}

float Display::getPositionY(){
	for(unsigned i = 0; i < kernels_.size(); i++){
	//	std::cout << "     "<<kernels_[i]._spriteObject.getPosition().y;
		return kernels_[i]._spriteObject.getPosition().y;
	}
}

float Display::getKernelPositionX(Corn::Sprite  kernel){
		for(unsigned i = 0; i < kernels_.size(); i++){
	//	std::cout << "     "<<kernels_[i]._spriteObject.getPosition().x;
		return kernels_[i]._spriteObject.getPosition().x;
	}

}

void Display::kernelPositioning(std::vector<Corn::Sprite> &v)
{
	unsigned int row;
	int _x =0;
	int _y = 360;
	

	for (unsigned int horizontal = 0; horizontal < 144; horizontal++) {
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
		if (horizontal == 71){
			_y = 1510;
			_x = 0;
		}
		if (horizontal == 95){
			_y = 1560;
			_x = 0;
		}
		if (horizontal == 119){
			_y = 1610;
			_x = 0;
		}
	}

	
}



		
		
	