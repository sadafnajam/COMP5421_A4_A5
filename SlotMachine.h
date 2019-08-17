//
//	Slotmachine.h
//  A4
//
//  Created by Sadaf Najam on 2019-07-25.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//

#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <stdexcept>
#include <iostream>
#include <regex>
#include <random>
#include <array>
#include <string>
#include "Shape.h";
#include "Rectangle.h";
#include "Rhombus.h";
#include "Traingle.h";
#include "AcuteTriangle.h";
#include "RightTriangle.h";
#include<memory>

using std::cout;
using std::getline;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::uniform_int_distribution;
using std::array;
using std::unique_ptr;
using std::regex_match;
using std::regex;
using std::getline;


class SlotMachine {
private:
	int slot_tokens = 10;		//Storage allocation for tokens

	int user_bet;		//Storage allocation of bets

	array<unique_ptr<Shape>, 3> reel{};			//Array of unique pointers

	void make_shapes();		//method for make_shape 

	void make_shape(int k);	//parameterized method for make_shape

	void display();		//function for display

	bool isValidNumber(string str);		//function for checking valid number 

public:
	SlotMachine() = default;		//Default ctor

	SlotMachine(const SlotMachine&) = delete;		//copy ctor

	SlotMachine(SlotMachine&&) = delete;			//move ctor

	SlotMachine& operator=(const SlotMachine) = delete;		//copy assignment

	SlotMachine& operator=(SlotMachine&&) = delete;			//move assignment

	virtual ~SlotMachine() = default;		//destructor

	void run();		//run algorithm
};
#endif