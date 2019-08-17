//
//	RightTriangle.cpp
//  A4
//
//  Created by Sadaf Najam on 2019-07-25.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//

#include "RightTriangle.h";

using Grid = vector<vector<char>>;		// A vector of vectors of chars

RightTriangle::RightTriangle(int bs, string sh_name, string sh_decription) :Traingle(sh_name, sh_decription), b(bs){
}

//function to compute box height
int RightTriangle::get_h() const {
	return get_w();
}

//function to compute box width
int RightTriangle::get_w() const {
	return b;
}

//function to compute geometric_area
double RightTriangle::geometric_area() const {
	int h = get_h();
	return h * b / 2.0;
}

//function to compute screen_area
int RightTriangle::screen_area() const {
	int h = get_h();
	return h * (h + 1) / 2;
}

//function to compute geometric_perimeter
int RightTriangle::screen_perimeter() const {
	int h = get_h();
	return 3 * (h - 1);
}

//function to compute screen_preimeter
double RightTriangle::geometric_perimeter() const {
	int h = get_h();
	return ((2 + sqrt(2)) * h) * 1.0;
}

//draw pure virtual method implemented by derived class
Grid RightTriangle::draw(char fChar, char bChar) const {
	Grid ch_grid;
	int h = get_h(), w = get_w();
	for (int i = 0; i < h; i++) {
		vector<char> ch_row;
		for (int j = 0; j < w; j++) {
			if (j > i)
				ch_row.push_back(bChar);
			else 
				ch_row.push_back(fChar);
		}
		ch_grid.push_back(ch_row);
	}
	return ch_grid;
}