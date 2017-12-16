// Display.hpp
// November 27, 2017
// This is the Display manager class
// Created by:
// 				Jim Samson(jasamson@alaska.edu)

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "../include/InputManager.hpp"
#include "SpriteTextureManager.hpp"

#include <algorithm>
#include <SFML/Graphics.hpp>
#include <vector>
using std::vector;
#include<time.h>

// Class Display
// This is the main class that handles the window
// Invariants:
// 				None.
class Display {
public:
	// Display() constructor
	// This creates a window from SFML
	// Preconditions:
	//				None.
	Display();

	// ~Display() destructor
	// This destructs the window class if anything bad happens.
	// Preconditions:
	//				None.
	~Display() = default;

	// draw() function
	// This draws objects to the screen.
	// Preconditions:
	//				None.
	void draw();

	// clockTime function
	// Returns a current time and date of the computer
	// Preconditions:
	//				None.
	time_t clockTime();

	// draw() function
	// This draws Corn Sprite objects to the screen.
	// Preconditions:
	//				None.
	void draw(const Corn::Sprite &);

	// draw() function
	// This draws a vector of Corn Sprite objects to the screen.
	// Preconditions:
	//				None.
	void draw(const vector<Corn::Sprite> &);

	// draw() text function
	// Draws a text object to the screen
	// Preconditions:
	//				None.
	void draw(sf::Text &);

	// update() function
	// Updates the objects that are on the screen.
	// Preconditions:
	//				None.
	void update();

	// loadTexture() function
	// Loads textures to the sprites
	// Preconditions:
	//				None.
	void loadTexture(vector<Corn::Sprite> &, string &&);

	// setTexture() function
	// Sets the texture to a sprite
	// Preconditions:
	//				None.
	void setTexture(); 

	// setText() function
	// Sets texts to a text object
	// Preconditions:
	//				None.
	void setText(sf::Text&, const sf::Color&, float x, float y);

	// kernelPositioning() function
	// ???
	// Preconditions:
	//				None.
	void kernelPositioning(vector<Corn::Sprite> &);

	// getPosition() function
	// Returns the position of an object.
	// Preconditions:
	//				None.
	float getPositionX();

	// getPosition() function
	// Returns the position of an object.
	// Preconditions:
	//				None.
	float getPositionY();
	
	// getKernelPosition() function
	// Returns the position of the kernel.
	// Preconditions:
	//				None.
	float getKernelPositionX(Corn::Sprite );

	// checkTime() function
	// Starts the time and returns the time
	// Preconditions:
	//				None.
	void checkTime();

	// checkKernel() function
	// Checks the position of the kernel.
	// Preconditions:
	//				None.
	void checkKernelPosition();

	// krazyPositioning
	// THIS IS THE 301 PART OF THIS PROJECT. WE USE BITSHIFTING TO MOVE THE Y-AXIS OF THE KERNEL POSITIONING.
	// Preconditions:
	//				None.
	void krazyPositioning(std::vector<Corn::Sprite> &v);

public:
	// Class Objects
	sf::RenderWindow window;
	sf::SoundBuffer theGongBuffer_;
	sf::Sound theGong_;
	time_t _systemClock;
	
	sf::Text atext;
	sf::Text hardModeText;
	sf::Font font;
	
	Corn::Sprite man_;
	vector<Corn::Sprite> kernels_;
	Corn::Sprite cornCob_;
	bool isPressedSpace = false;
	bool isRotating = false;

	//bool isPressed;
};

#define WINDOW_WIDTH 1280	
#define WINDOW_HEIGHT 720

#endif // DISPLAY_HPP
