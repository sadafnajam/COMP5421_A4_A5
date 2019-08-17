//
//	Rhombus.cpp
//  A4
//
//  Created by Sadaf Najam on 2019-07-25.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//

#include "Rhombus.h";

using Grid = vector<vector<char>>;		// A vector of vectors of chars

Rhombus::Rhombus(int b, string sh_name, string sh_decription) :Shape(sh_name, sh_decription){
	if (b % 2 == 0)
		d = b + 1;
	else
		d = b;
}

//function to compute box height
int Rhombus::get_h() const {
	return d;
}

//function to compute box width
int Rhombus::get_w() const {
	return d;
}

//function to compute geometric_area
double Rhombus::geometric_area() const {
	return pow(d,2)/ 2.0;
}

//function to compute screen_area
int Rhombus::screen_area() const {
	int n = d / 2;
	return 2 * n * (n + 1) + 1;
}

//function to compute geometric_perimeter
double Rhombus::geometric_perimeter() const {
	return 2.0 * sqrt(2) * d;
}

//function to compute screen_preimeter
int Rhombus::screen_perimeter() const {
	return 2 * (d - 1);
}

//draw pure virtual method implemented by derived class
Grid Rhombus::draw(char fChar, char bChar) const {
	Grid ch_grid;
	int h = get_h(), w = get_w();
	for (int i = 0; i < h; i++) {
		vector<char> ch_row;
		for (int j = 0; j < w; j++) {
			int ac = (i <= h / 2) ? i : (h - i - 1);
			if (j < h / 2 - ac || j > h / 2 + ac)
				ch_row.push_back(bChar);
			else
				ch_row.push_back(fChar);
		}
		ch_grid.push_back(ch_row);
	}
	return ch_grid;
}