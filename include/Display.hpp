// Display.hpp
// November 27, 2017
// This is the Display manager class
// Created by:
// 				Jim Samson(jasamson@alaska.edu)

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <SFML/Graphics.hpp>

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

	// update() function
	// Updates the objects that are on the screen.
	// Preconditions:
	//				None.
	void update();

	// loadTexture() function
	// Loads textures to the sprites
	// Preconditions:
	//				None.
	void loadTexture();

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

	// Class Objects
	sf::RenderWindow window;
};

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#endif // DISPLAY_HPP
