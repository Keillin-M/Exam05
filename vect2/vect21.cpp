#include "vect21.hpp"

                 vect2(int x, int y);
                 vect2(const vect2 &other);
                 vect2 &operator=(const vect2 &other);

vect2& operator++();
vect2 operator++(int);
vect2& operator--();
vect2 operator--(int);

vect2 operator+(const vect2 &other) const;
vect2& operator+=(const vect2 &other);

vect2 operator-(const vect2 &other) const;
vect2& operator-=(const vect2 &other);

vect2 operator*(const vect2 &other) const;
vect2& operator*=(const vect2 &other);

vect2 operator-(const vect2 &other) const;

bool operator==(const vect2 &other) const;
bool operator!=(const vect2 &other) const;

int operator[](int index);
int &operator[](int index) const;

};

vect2 operator*(int scalar, const vect2 &other);

std::ostream &operator<<(std::ostream &s, const vect2 &v);