//
//	Shape.h
//  A4
//
//  Created by Sadaf Najam on 2019-07-25.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//

#ifndef SHAPE_H
#define SHAPE_H

#include <string>;
#include<iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using std::string;
using std::ostream;
using std::vector;
using std::ostringstream;
using std::setprecision;
using std::fixed;
using std::endl;

//Base class shape

class Shape {
private:
	//Variables for storage allocation
	static int m_size;	
	int m_Identity;
	string m_Name;
	string m_Description;

public:
	Shape(string, string);		//Ctor that accepts nitial value of shape's name and descripton

	virtual ~Shape() = default;		//Default virtual destructor

	int get_identity() const;		//Integer identity number, distinct from rest of shape objects

	string get_name() const;		//getter for name

	string get_description() const;	//getter for description

	void set_name(string);			//setter for name	

	void set_description(string);	//setter for description

	string toString() const;		//method to generate and return string representation of shape object

	virtual int get_h() const = 0;	//pure virtial uncion

	virtual int get_w() const = 0;	//pure virtual function

	virtual double geometric_area() const = 0;	//method to compute object's geometric area

	virtual int screen_area() const = 0;		//method to compute object's screen area

	virtual double geometric_perimeter() const = 0;		//method to compute object's geometric perimeter

	virtual int screen_perimeter() const = 0;		//method to compute object's screen perimeter

	friend ostream& operator<<(ostream&, const Shape&);		//Polymorphism

	using Grid = vector<vector<char>>;		// A vector of vectors of chars

	virtual Grid draw(char = '*', char = ' ') const = 0;	//Draw memeber funtion as a pure virtual member function
};
#endif