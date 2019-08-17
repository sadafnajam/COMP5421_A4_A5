//
//	AcuteTriangle.cpp
//  A4
//
//  Created by Sadaf Najam on 2019-07-25.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//

#include "AcuteTriangle.h";
using Grid = vector<vector<char>>;		// A vector of vectors of chars


AcuteTriangle::AcuteTriangle(int hb, string sh_name, string sh_decription) :Traingle(sh_name, sh_decription), b(hb) {
	if (hb % 2 == 0)
		b = (hb + 1);
	else
		b = hb;
}

//function to compute box height
int AcuteTriangle::get_h() const {
	return (b + 1) / 2;
}

//function to compute box width
int AcuteTriangle::get_w() const {
	return b;
}

//function to compute geometric_area
double AcuteTriangle::geometric_area() const {
	int h = get_h();
	return (h * b) / 2.0;
}

//function to compute screen_area
int AcuteTriangle::screen_area() const {
	int h = get_h();
	return pow(h, 2);
}

//function to compute geometric_perimeter
double AcuteTriangle::geometric_perimeter() const {
	return b + 2 * sqrt(0.25 * pow(b, 2) + screen_area());
}

//function to compute screen_preimeter
int AcuteTriangle::screen_perimeter() const {
	int h = get_h();
	return 4 * (h - 1);
}

//draw pure virtual method implemented by derived class
Grid AcuteTriangle::draw(char fChar, char bChar) const {
	Grid ch_grid;
	int h = get_h(), w = get_w();
	for (int i = 0; i < h; i++) {
		vector<char> ch_row;
		for (int j = 0; j < w; j++) {
			if (j < h - 1 - i || j > h - 1 + i)
				ch_row.push_back(bChar);
			else
				ch_row.push_back(fChar);
		}
		ch_grid.push_back(ch_row);
	}
	return ch_grid;
}