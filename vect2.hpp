#pragma once
#include <iostream>

class vect2
{
private:
	int data[2];

public:
	vect2(int x = 0, int y = 0);

	vect2 operator+(const vect2 &other) const;
	vect2 operator-(const vect2 &other) const;
	vect2 operator*(int scalar) const;

	int &operator[](int index);
	const int &operator[](int index) const;
};

std::ostream &operator<<(std::ostream &os, const vect2 &v);
