// ApplicationLoop.cpp
// November 27, 2017
// This is the Application Loop source file
// Created by:
// 				Jim Samson(jasamson@alaska.edu)

#include "../include/ApplicationLoop.hpp"

// AppLoop() constructor
// See header for more documentation.
AppLoop::AppLoop() {
	input_mgr_ = make_unique<Input>();
}

// windowLoop() function
// See header for more documentation.
void AppLoop::windowLoop() {
	while(input_mgr_->display_->window.isOpen()) {
		input_mgr_->display_->update();
		input_mgr_->display_->draw();
		input_mgr_->handleInput();
	}
}