//
//	Rectangle.h
//  A4
//
//  Created by Sadaf Najam on 2019-07-25.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h";

//Class Rectangle inherited from shape

class Rectangle : public Shape{
private:
	int h,w;	//Storage allocation for variable

public:
	using Grid = vector<vector<char>>;		// A vector of vectors of chars

	Rectangle(int, int, string = "Four-sided", string="Four right angles");		//Parameterized ctor

	virtual ~Rectangle() = default;		//Default virtual destructor

	virtual int get_h() const override;		//Intended override get_h()

	virtual int get_w() const override;		//Intended override get_w()

	virtual double geometric_area() const override;		//Intended override geometric_area()

	virtual int screen_area() const override;		//Function to compute screen area, intended override

	virtual double geometric_perimeter() const override;		//Function to compute geometric perimeter, intended override

	virtual int screen_perimeter() const override;		//Function to compute screen perimeter, intended override

	virtual Grid draw(char = '*', char = ' ') const override;		//Draw memeber funtion as a pure virtual member function
};
#endif