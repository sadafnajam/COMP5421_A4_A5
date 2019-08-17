//
//	Shape.h
//  A4
//
//  Created by Sadaf Najam on 2019-07-25.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//

#include "Shape.h";

int Shape::m_size = 0;

//Ctor implementation
Shape::Shape(string sh_name, string sh_decription):m_Name(sh_name) , m_Description(sh_decription){
	m_Identity = (++m_size);
}

//getter implementation of identity
int Shape::get_identity() const{
	return this->m_Identity;
}

//getter implementation of name
string Shape::get_name() const {
	return this->m_Name;
}

//getter implementation of description
string Shape::get_description() const{
	return this->m_Description;
}

//Setter implementation of name
void Shape::set_name(string sh_name) {
	this->m_Name = sh_name;
}

//Setter implementation of description
void Shape::set_description(string sh_decription) {
	this->m_Description = sh_decription;
}

//impleentation to generate and return string representation of shape object
string Shape::toString() const {
	ostringstream osstream;
	osstream << std::setprecision(2) << fixed;
	osstream << "Shape Information" << endl;
	osstream << "-----------------" << endl;
	osstream << "id:            " << get_identity() << endl;
	osstream << "Shape name:    " << get_name() << endl;
	osstream << "Description:   " << get_description() << endl;
	osstream << "B. box width:  " << get_w() << endl;
	osstream << "B. box height: " << get_h() << endl;
	osstream << "Scr area:      " << screen_area() << endl;
	osstream << "Geo area:      " << geometric_area() << endl;
	osstream << "Scr perimeter: " << screen_perimeter() << endl;
	osstream << "Geo perimeter: " << geometric_perimeter() << endl;
	osstream << "Static type:   " << typeid(this).name() << endl;
	osstream << "Dynamic type:  " << typeid(*this).name() << endl;
	return osstream.str();
}

//Implememntation of operator overloading for polymorphic behaviour
ostream& operator<<(ostream& sout, const Shape& shape) {
	sout << shape.toString();
	return sout;
}