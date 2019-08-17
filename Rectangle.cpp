//
//	Rectangle.cpp
//  A4
//
//  Created by Sadaf Najam on 2019-07-25.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//

#include "Rectangle.h";

using Grid = vector<vector<char>>;		// A vector of vectors of chars

Rectangle::Rectangle(int wi, int he, string sh_name, string sh_decription):Shape(sh_name, sh_decription), w(wi), h(he) {
}
//function to compute box height
int Rectangle::get_h() const {
	return h;
}

//function to compute box width
int Rectangle::get_w() const {
	return w;
}

//function to compute geometric_area
double Rectangle::geometric_area() const {
	return (h * w)*1.0;
}

//function to compute screen_area
int Rectangle::screen_area() const {
	return h * w;
}

//function to compute geometric_perimeter
double Rectangle::geometric_perimeter() const {
	return 2.0 * (h + w);
}

//function to compute screen_preimeter
int Rectangle::screen_perimeter() const {
	return 2 * (h + w) - 4;
}

//draw pure virtual method implemented by derived class
Grid Rectangle::draw(char fChar, char bChar) const {
	Grid ch_grid;
	int he = get_h(), wi = get_w();
	for (int i = 0; i < he; i++) {
		vector<char> ch_row;
		for (int j = 0; j < wi; j++) {
			ch_row.push_back(fChar);
		}
		ch_grid.push_back(ch_row);
	}
	return ch_grid;
}