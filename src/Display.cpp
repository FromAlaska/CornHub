// Display.cpp
// November 27, 2017
// This is the Display class. It handles the window function.
// Created by:
// 				Jim Samson(jasamson@alaska.edu)
//				Samuel Grenon
//				Cameron Titus
//				Jacob Fairbanks

#include "../include/Display.hpp"

// Display() Constructor
// See header for more documentation.

int cobSize = 10000;
static int kernelsEaten = 0;

Display::Display() {

	// Font section
	if (!font.loadFromFile("../resources/fonts/Chava-Regular.ttf")){
		std::cout << "Couldn't load file" << std::endl;
	}
	atext.setFont(font);
	atext.setCharacterSize(50);
	atext.setStyle(sf::Text::Bold);
	atext.setColor(sf::Color::White);
	atext.setPosition(0,0);

	// Kernel section
	kernels_.resize(144);
	kernelPositioning(kernels_);

	// Load texture section
	setTexture();

	// Window section
	window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "CornHub", 
		sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(10);

	// Set positioning section
	man_._spriteObject.setPosition(1240/2 - 75,50);
	cornCob_._spriteObject.setPosition(0, 720/2);
}

// clockTime() function
// See header for more documentation.
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
	draw(atext);

	window.display(); // Keep this last.
}

// draw() function
// See header for more documentation.
void Display::draw(const Corn::Sprite & obj) {
	window.draw(obj._spriteObject);
}

// draw() function (for each kernel)
// See header for more documentation.
void Display::draw(const vector<Corn::Sprite> & obj) {
	for(auto iter = obj.begin(); iter != obj.end(); ++iter)
	{
		window.draw(iter->_spriteObject);
	}
}

// draw() function (for the text)
// See header for more documentation.
void Display::draw(sf::Text & text)
{	
	//std::cout << (ctime (&_systemClock)); // Uncomment to see the system time
	//atext.setString(ctime (&_systemClock));
	window.draw(text);
}

// update() function
// See header for more documentation.
void Display::update() {

	_systemClock = clockTime();
	time (&_systemClock);
	atext.setString(ctime (&_systemClock));

	// This is a function in this class
	checkKernelPosition();
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
void Display::setTexture() 
{
	man_.loadTexture("../resources/cornboy.png");
	cornCob_.loadTexture("../resources/Corncob01.png");
	loadTexture(kernels_,"../resources/cornKernel.png");
}

// setText function
// See header for more documentation.
void Display::setText(sf::Text&, const sf::Color&, float x, float y) 
{

}

// getPositionX() function
// See header for more documentation.
float Display::getPositionX(){
	return man_._spriteObject.getPosition().x;
}

// getPositionY() function
// See header for more documentation.
float Display::getPositionY(){
	for(unsigned i = 0; i < kernels_.size(); i++){
	//	std::cout << "     "<<kernels_[i]._spriteObject.getPosition().y;
		return kernels_[i]._spriteObject.getPosition().y;
	}
}

// getKernelPositionX() functions
// See header for more documentation.
float Display::getKernelPositionX(Corn::Sprite  kernel){
		for(unsigned i = 0; i < kernels_.size(); i++){
	//	std::cout << "     "<<kernels_[i]._spriteObject.getPosition().x;
		return kernels_[i]._spriteObject.getPosition().x;
	}
}

// checkKernelPosition() function
// See header for more documentation.
void Display::checkKernelPosition()
{
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

// kernelPositioning() function
// See header for more documentation.
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
			_x = 0;
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



		
		
	