//
//	RightTriangle.h
//  A4
//
//  Created by Sadaf Najam on 2019-07-25.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H
#include "Traingle.h";

//Class triangle inherited from shape

class RightTriangle : public Traingle {
private:
	int b;		//Storage allocation for variable

public:
	using Grid = vector<vector<char>>;		// A vector of vectors of chars

	RightTriangle(int, string = "Right triangle", string = "One right and two acute angles");		//Parameterized ctor

	virtual ~RightTriangle() = default;		//Default virtual destructor

	virtual int get_h() const override;		//Intended override get_h()

	virtual int get_w() const override;		//Intended override get_w()

	virtual double geometric_area() const override;		//Intended override geometric_area()

	virtual int screen_area() const override;		//Function to compute screen area, intended override

	virtual double geometric_perimeter() const override;		//Function to compute geometric perimeter, intended override

	virtual int screen_perimeter() const override;		//Function to compute screen perimeter, intended override

	virtual Grid draw(char = '*', char = ' ') const override;		//Draw memeber funtion as a pure virtual member function
};
#endif