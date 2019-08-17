//
//	Slotmachine.cpp
//  A4
//
//  Created by Sadaf Najam on 2019-07-25.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//

#include "SlotMachine.h";

using Grid = vector<vector<char>>;		// A vector of vectors of chars

//Implementation for checking valid number
bool SlotMachine::isValidNumber(string str)
{
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;

	return true;
}

//Implementation of run algorithm
void SlotMachine::run()
{
	string str;
	cout << "Welcome to 3-Reel Lucky Slot Machine Game!" << endl;
	cout << "Each reel will randomly display one of four shapes, each in 25 sizes." << endl;
	cout << "To win 3 x bet Get 2 similar shapes AND 2 shapes with equal Scr Areas." << endl;
	cout << "To win 2 x bet Get 3 similar shapes" << endl;
	cout << "To win 1 x bet Get (Middle) Scr Area > (Left + Right) Scr Areas" << endl;
	cout << "To win or lose nothing Get same Left and Right shapes" << endl;
	cout << "Otherwise, you lose your bet." << endl;
	cout << "You start with 10 free slot tokens!" << endl;
	cout << endl;
	while (slot_tokens != 0 && user_bet != 0) {
			cout << "How much would you like to bet (enter 0 to quit)? ";
			getline(cin, str);
			regex rgx("\\d+");
			if (regex_match(str, rgx)) {
				user_bet = stoi(str);
				if (user_bet > 0 && user_bet <= slot_tokens) {
					make_shapes();
					display();
				}
				else if (user_bet >= slot_tokens) {
					cout << "You can't bet more than " << slot_tokens << ", try again!" << endl;
				}
			}
			else if (str[0] == '-' && isValidNumber(str.substr(1, str.length()))) {
				cout << "No negative bets, try gain!" << endl;
			}
	};
	cout << "Thank you for playing, come back soon!" << endl;
	cout << "Be sure you cash in your remaing " << slot_tokens << " tokens at the bar!" << endl;
	cout << "Game Over." << endl;
	cin.ignore();
	cin.get();
}

//implementation of make_shape
void SlotMachine::make_shapes() {
	for (int k = 0; k< reel.size(); k++) {
		make_shape(k);
	}
}

void SlotMachine::make_shape(int k) {
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> distribution_shape_range(0, 3);
	uniform_int_distribution<int> distribution_size_range(1, 25);
	auto  n = distribution_shape_range(rng);
	auto  w = distribution_size_range(rng);
	if (n == 0)
		reel[k].reset(new Rhombus(w));
	else if (n == 1)
		reel[k].reset(new AcuteTriangle(w));
	else if (n == 2)
		reel[k].reset(new RightTriangle(w));
	else {
		int h = distribution_size_range(rng);
		reel[k].reset(new Rectangle(w, h));
	}
}

//Implememntation of display function
void SlotMachine::display() {
	int payout = -1;
	if ((reel[0]->get_name() == reel[1]->get_name() && reel[0]->screen_area() == reel[1]->screen_area())
		|| (reel[0]->get_name() == reel[2]->get_name() && reel[0]->screen_area() == reel[2]->screen_area())
		|| (reel[1]->get_name() == reel[2]->get_name() && reel[1]->screen_area() == reel[2]->screen_area())) {
		payout = 3;
	}
	else if (reel[0]->get_name() == reel[1]->get_name() && reel[0]->get_name() == reel[2]->get_name()) {
		payout = 2;
	}
	else if (reel[1]->screen_area() > (reel[0]->screen_area() + reel[2]->screen_area())) {
		payout = 1;
	}
	else if (reel[0]->get_name() == reel[2]->get_name()) {
		payout = 0;
	}
	array<Grid, 3> three_bboxes;
	three_bboxes[0] = reel[0]->draw();
	three_bboxes[1] = reel[1]->draw();
	three_bboxes[2] = reel[2]->draw();
	array<int, 3> borderRows;
	for (int i = 0; i < three_bboxes.size(); i++) {
		borderRows[i] = reel[i]->get_w();
	}
	array<int, 3> borderColumns;
	int max_h = 0;
	for (int i = 0; i < three_bboxes.size(); i++) {
		if (max_h < reel[i]->get_h()) {
			max_h = reel[i]->get_h();
		}
		borderColumns[i] = reel[i]->get_h();
	}
	for (auto br : borderRows) {
		cout << "+-";
		int rsize = 0;
		while (rsize < br) {
			cout << '-';
			rsize++;
		}
		cout << "-";
	}
	cout << "+"<<endl;
	for (int row = 0; row < max_h; row++) {
		for (int col = 0; col < three_bboxes.size(); col++) {
			cout << "| ";
				for (int hw = 0; hw < borderRows[col]; hw++) {
					if (borderColumns[col] > row)
						cout << three_bboxes[col][row][hw];
					else
						cout << " ";
				}
			cout << " ";
		}
		cout << "|" << endl;
	}
	for (auto br : borderRows) {
		cout << "+-";
		int rsize = 0;
		while (rsize < br) {
			cout << '-';
			rsize++;
		}
		cout << "-";
	}
	cout << "+" << endl;

	for (int i = 0; i < reel.size(); i++) {
		cout << "(" << reel[i]->get_name() << ", " << reel[i]->get_w() << ", " << reel[i]->get_h() << ") ";
	}
	cout<< endl;
	slot_tokens += (payout * user_bet);
	if (payout == 3) {
		cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Area" << endl;
		cout << "Congratulations! you win 3 times your bet: " << (payout * user_bet) << endl;
	}
	else if (payout == 2) {
		cout << "Three similar shapes" << endl;
		cout << "Congratulations! you win 2 times your bet: " << (payout * user_bet) << endl;
	}
	else if (payout == 1) {
		cout << "Middle > Left + Right, in screen Area" << endl;
		cout << "Congratulations! you win your bet: " << (payout * user_bet) << endl;
	}
	else if (payout == 0) {
		cout << "Lucky this time!" << endl;
		cout << "You don't win, you don't lose, your are safe!" << endl;
	}
	else{
		cout << "Oh No!" << endl;
		cout << "You lose your bet"<<endl;
	}
	cout << "You now have " << slot_tokens << " tokens" << endl;
}