/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:18:35 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/22 16:46:47 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2(int x, int y) {
	data[0] = x;
	data[1] = y;
}

vect2 vect2::operator+(const vect2 &other) const {
	return vect2(data[0] + other.data[0], data[1] + other.data[1]);
}

vect2 vect2::operator-(const vect2 &other) const {
	return vect2(data[0] - other.data[0], data[1] - other.data[1]);
}

vect2 vect2::operator*(int scalar) const {
	return vect2(data[0] * scalar, data[1] * scalar);
}

int& vect2::operator[](int index) {
	return data[index];
}
const int& vect2::operator[](int index) const {
	return data[index];
}

std::ostream& operator<<(std::ostream &s, const vect2 &v) {
	return s << "{" << v[0] << ", " << v[1] << "}" << std::endl;
}


