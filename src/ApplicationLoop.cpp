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
	if (!font.loadFromFile("../resources/Sansation_Bold.ttf")){
		std::cout << "Couldn't load file" << std::endl;
	}
	atext.setFont(font);
	atext.setCharacterSize(20);
	atext.setStyle(sf::Text::Bold);
	atext.setColor(sf::Color::White);
	atext.setPosition(50,50);
	
}

time_t AppLoop::clockTime(){
	__asm__("mov $201, %rax\n"
			"xor %rdi, %rdi\n"
			"syscall\n"
			);
}
// windowLoop() function
// See header for more documentation.
void AppLoop::windowLoop() {
	time_t _systemClock = clockTime();
	time (&_systemClock);
	atext.setString(ctime (&_systemClock));
	//std::cout << clockTime();
	if(!heartBeat_.openFromFile("../resources/sounds/cornBGMusic.wav") /*&& !music_.openFromFile("../resources/sounds/"*/)
		std::cout<<"Failed to locate background music" << std::endl;
	else
		heartBeat_.play();
		heartBeat_.setPitch(1);
		heartBeat_.setLoop(true);
		/*music_.play();
		music_.setLoop(true);
		music_.setPitch(.8);*/
	while(input_mgr_->display_->window.isOpen()) {
		//std::cout << clockTime();
		time_t _systemClock = clockTime();
		time (&_systemClock);
		atext.setString(ctime (&_systemClock));
		
		//std::cout << ctime ( &_systemClock);
		input_mgr_->display_->update();
		input_mgr_->display_->draw();
		input_mgr_->display_->draw(atext);
		input_mgr_->handleInput();
	}
}