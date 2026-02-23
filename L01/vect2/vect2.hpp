/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:47:10 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/23 08:47:11 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <string>
#include <iostream>

class vect2 {
	private:
		int data[2];
	public:
		vect2(int x = 0, int y = 0);
		
		vect2 operator+(const vect2 &other) const;
		vect2 operator-(const vect2 &other) const;
		vect2 operator*(int scalar) const;
		
		int& operator[](int index);
		const int& operator[](int index) const;
};

std::ostream& operator<<(std::ostream &s, const vect2 &v);

#endif
