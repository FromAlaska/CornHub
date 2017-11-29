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
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <memory>
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;

#define myproject_VERSION_MAJOR 0
#define myproject_VERSION_MAJOR 1

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

private:
	unique_ptr<Input> input_mgr_;
};

#endif // APPLICATIONLOOP_HPP