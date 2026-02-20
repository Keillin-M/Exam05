#include "vect2.hpp"

vect2::vect2(int x, int y)
{
	data[0] = x;
	data[1] = y;
}

vect2 vect2::operator+(const vect2 &other) const
{
	return vect2(data[0] + other.data[0], data[1] + other.data[1]);
}

vect2 vect2::operator-(const vect2 &other) const
{
        return vect2(data[0] - other.data[0], data[1] - other.data[1]);
}

vect2 vect2::operator*(int scalar) const
{
        return vect2(data[0] * scalar, data[1] * scalar);
}

int &vect2::operator[](int index)
{
	return data[index];
}

const int &vect2::operator[](int index) const
{
        return data[index];
}

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
	return os << "{" << v[0] << ", " << v[1] << "}";
}
