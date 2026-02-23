/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint1.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:07:23 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/23 09:07:24 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT1_HPP
#define BIGINT1_HPP

#include <strring>
#include <iostream>

class bigint {
	private:
		std::string num;
		void clean();
	public:
		bigint(const std::string &s = "0");
		bigint(int n);
		
		bigint operator+(const bigint &other) const;
		bigint& operator+=(const bigint &other);
		bigint& operator++();
		bigint operator++(int);
		
		bigint operator>>(int shift) const;
		bigint operator>>(const bigint &shift) const;
		bigint operator<<(int shift) const;
		bigint operator<<(const bigint &shift);
		bigint& operator>>=(int shift);
		bigint& operator>>=(const bigint &shift);
		bigint& operator<<=(int shift);
		bigint& operator<<=(const bigint &shift);
		
		bool operator>(const bigint &other);
		bool operator<(const bigint &other);
		bool operator==(const bigint &other);
		bool operator!=(const bigint &other);
		bool operator>=(const bigint &other);
		bool operator<=(const bigint &other);
		
		int toInt() const;
		std::string getNum() const;
		
};

std::ostream& operator<<(std::ostream &os, const bigint &b);

#endif
