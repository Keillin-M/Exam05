/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:43:45 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/20 14:43:47 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
	private:
		std::string num;
		void clean();
	public:
		bigint(const string &s = "0");
		bigint(int n);

		bool operator>(const bigint &other) const;
		bool operator>=(const bigint &other) const;
		bool operator<(const bigint &other) const;
		bool operator<=(const bigint &other) const;
		bool operator==(const bigint &other) const;
		bool operator!=(const bigint &other) const;

		bigint operator+(const bigint &other) const;
		bigint &operator+=(const bigint &other);
		bigint &operator++();
		bigint operator++(int);

		bigint operator>>(int shift) const;
		bigint operator>>(const bigint &shift) const;
		bigint operator<<(int shift) const;
		bigint operator<<(const bigint &shift) const;
		bigint &operator>>=(int shift);
		bigint &operator>>=(const bigint &shift);
		bigint &operator<<=(int shift);
		bigint &operator<<=(const bigint &shift);

		int to_int() const;
		const std::string &get_num() const { return num; }
};

std::ostream &operator<<(std::ostream &os, const bigint &b);

#endif
