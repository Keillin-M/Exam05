/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint1.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:09:56 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/22 21:56:53 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT1_HPP
#define BIGINT1_HPP

#include <string>
#include <iostream>

class bigint {
	private:
		std::string num;
		void clean();
	public:
		bigint(const std::string &s = "0");
		bigint(int num);

		bigint operator+(const bigint &other) const;
		bigint& operator+=(const bigint &other);
		bigint& operator++();
		bigint operator++(int);

		bigint operator>>(int shift) const;
		bigint operator>>(const bigint &shift) const;
		bigint operator<<(int shift) const;
		bigint operator<<(const bigint &shift) const;
		bigint operator>>=(int shift);
		bigint operator>>=(const bigint &shift);
		bigint operator<<=(int shift);
		bigint operator<<=(const bigint &shift);

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
