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
	if(!heartBeat_.openFromFile("../resources/sounds/bgSound.wav") /*&& !music_.openFromFile("../resources/sounds/"*/)
		std::cout<<"Failed to locate background music" << std::endl;
	else
		heartBeat_.play();
		heartBeat_.setPitch(.8);
		heartBeat_.setLoop(true);
		/*music_.play();
		music_.setLoop(true);
		music_.setPitch(.8);*/
	while(input_mgr_->display_->window.isOpen()) {
		input_mgr_->display_->update();
		input_mgr_->display_->draw();
		input_mgr_->handleInput();
	}
}