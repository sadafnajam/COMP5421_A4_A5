//
//	Rhombus.h
//  A4
//
//  Created by Sadaf Najam on 2019-07-25.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//

#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "Shape.h";

//Class Rectangle inherited from shape

class Rhombus : public Shape {
private:
	int d;		//Storage allocation for variable

public:
	using Grid = vector<vector<char>>;		// A vector of vectors of chars

	Rhombus(int, string = "Diamond", string = "A parallelogram with equal sides");		//Parameterized ctor

	virtual ~Rhombus() = default;		//Default virtual destructor

	virtual int get_h() const override;		//Intended override get_h()

	virtual int get_w() const override;		//Intended override get_w()

	virtual double geometric_area() const override;		//Intended override geometric_area()

	virtual int screen_area() const override;		//Function to compute screen area, intended override

	virtual double geometric_perimeter() const override;		//Function to compute geometric perimeter, intended override

	virtual int screen_perimeter() const override;		//Function to compute screen perimeter, intended override

	virtual Grid draw(char = '*', char = ' ') const override;		//Draw memeber funtion as a pure virtual member function	
};
#endif