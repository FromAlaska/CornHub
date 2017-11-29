// InputManager.hpp
// November 27, 2017
// This class is the input manager class. It checks for any input from the user.
// Created by:
// 				Jim Samson(jasamson@alaska.edu)

#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Display.hpp"
#include <memory>
using std::shared_ptr;
using std::make_unique;

class Display;

// Class Input
// This handles the input from the user.
// Invariants:
//			None.

class Input {
public:
	// Input() constructor
	// This is the constructor to set values to the variables.
	// Preconditions:
	//				None.
	Input();

	// ~Input() destructor
	// This destructs the objects if something catches on fire.
	// Preconditions:
	//				None.
	~Input() = default;

	// mouseOverObject() function
	// Checks if the mouse is over an object that can be manipulated.
	// Preconditions:
	//				None.
	void mouseOverObject();

	// bool clickOnSprite() function
	// This takes an object if the object can be clicked on.
	// Preconditions:
	//				None.
	bool clickOnSprite(sf::Sprite, int, int);

	// handleInput() function
	// This handles the input of the window.
	// Preconditions:
	//				None.
	void handleInput();

	// Class objects
	shared_ptr<Display> display_;
};

#endif // INPUTMANAGER_HPP