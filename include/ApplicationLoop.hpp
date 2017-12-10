// ApplicationLoop.hpp
// November 27, 2017
// This is the window manager class
// Created by:
// 			Jim Samson (jasamson@alaska.edu)

#ifndef APPLICATIONLOOP_HPP
#define APPLICATIONLOOP_HPP

#include "InputManager.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstddef>
#include <iostream>
#include <time.h>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <memory>
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;

// Class AppLoop
// This creates a loop that will make a window in a while loop.
// Invariants:
//				None.
class AppLoop {

public:

	// AppLoop Constructor
	// Creates a unique ptr of to initiate a loop
	// Preconditions:
	// 				None.
	AppLoop();
	
	// AppLoop Destructor
	// Destroys data if the unique ptr decides to crash
	// Preconditions:
	// 				None.
	~AppLoop() = default;

	// windowLoop() function
	// Creates a loop to check for any input from the application
	// Preconditions:
	// 				None.
	void windowLoop();

	time_t clockTime();

private:
	unique_ptr<Input> input_mgr_;
	sf::Music music_;
	sf::Music heartBeat_;
	sf::Text atext;
	sf::Font font;
};

#endif // APPLICATIONLOOP_HPP