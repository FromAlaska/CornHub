// timer.hpp
// 26. April 2017
// Created by:
// 		Bryan Burkhardt (bmburkhardt@alaska.edu)
// 		Alexander Eckert (aeckert@alaska.edu)
// 		Jeremiah Jacobson (jjacobson2@alaska.edu)
// 		Jarye Murphy (jmurphy11@alaska.edu)
// 		Cameron Showalter (cjshowalter@alaska.edu)
//
// Source file for timer

#ifndef TIMER_HPP
#define TIMER_HPP


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>

class Timer {
	/****** Timer Variables ******/
	// Current Time Elapsed Stuff
	std::stringstream currentTimerStreamSeconds;
	std::stringstream currentTimerStreamMinutes;
	std::stringstream currentTimerStreamHours;
	sf::Time currentTimer;
	float currentTimeSeconds;
	float currentTimeMinutes;
	float currentTimeHours;

	// Total Time Stuff
	std::stringstream totalTimerStreamSeconds;
	std::stringstream totalTimerStreamMinutes;
	std::stringstream totalTimerStreamHours;
	sf::Time totalTimer;
	float totalTimeSeconds;
	float totalTimeMinutes;
	float totalTimeHours;

	// Onscreen Timer Display Stuff
	std::string currentSec;
	std::string currentMin;
	std::string currentHour;
	std::string totalSec;
	std::string totalMin;
	std::string totalHour;

public:
	Timer() = default;

	/****** Timer Functions ******/
	void updateTimer();
	std::string selectDisplayTimer();
	void displayTimer();
	int convertToMinutes(int seconds);
	int convertToHours(int seconds);
};


#endif //TIMER_HPP
