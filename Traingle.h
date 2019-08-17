#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h";
class Traingle : public Shape {
private:
public:
	using Grid = vector<vector<char>>;
	Traingle(string, string);
	virtual ~Traingle() = default;
	virtual int get_h() const = 0;
	virtual int get_w() const = 0;
	virtual double geometric_area() const = 0;
	virtual int screen_area() const = 0;
	virtual double geometric_perimeter() const = 0;
	virtual int screen_perimeter() const = 0;
	virtual Grid draw(char = '*', char = ' ') const = 0;
};
#endif