// Display.hpp
// November 27, 2017
// This is the Display manager class
// Created by:
// 				Jim Samson(jasamson@alaska.edu)

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "../include/InputManager.hpp"
#include <algorithm>
#include "SpriteTextureManager.hpp"
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

	// setText function
	// Sets texts to a text object
	// Preconditions:
	//				None.
	void setText(sf::Text&, const sf::Color&, float x, float y);

	void kernelPositioning(vector<Corn::Sprite> &);

	float getPositionX();

	float getPositionY();
	
	float getKernelPositionX(Corn::Sprite );



public:
	// Class Objects
	sf::RenderWindow window;
	sf::SoundBuffer theGongBuffer_;
	sf::Sound theGong_;
	sf::Text atext;
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
