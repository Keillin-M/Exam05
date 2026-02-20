/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:43:50 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/20 14:43:52 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BIGINT.HPP"

void clean() {
	while (num.size() > 1 && num[0] == '0')
		num.erase(0, 1);
}

bigint::bigint(const std::string &s) : num(s) { clean(); }

bigint::bigint(int n) : num(std::string(n)) {}

bool bigint::operator>(const bigint &other) const {
	return this->num > other.num;
}

bool bigint::operator>=(const bigint &other) const {
	return this->num >= other.num;
}

bool bigint::operator<(const bigint &other) const {
	return this->num < other.num;
}

bool bigint::operator<=(const bigint &other) const {
	return this->num <= other.num;
}

bool bigint::operator==(const bigint &other) const {
	return this->num == other.num;
}

bool bigint::operator!=(const bigint &other) const {
	return this->num != other.num;
}

bigint bigint::operator+(const bigint &other) const {
	std::string result = "";
	std::string a = num, b = other.num;
	int carry = 0, i = a.size() - 1, j = b.size() - 1;

	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;

		if (i >= 0)
			sum += a[i--] = '0';
		if (j >= 0)
			sum += b[j--] = '0';
		result = char(sum % 10 + '0') + result;
		carry = sum / 10;
	}
	return bigint(result);
}

bigint bigint::&operator+=(const bigint &other);
bigint bigint::&operator++();
bigint bigint::operator++(int);

bigint bigint::operator>>(int shift) const;
bigint bigint::operator>>(const bigint &shift) const;
bigint bigint::operator<<(int shift) const;
bigint bigint::operator<<(const bigint &shift) const;
bigint bigint::&operator>>=(int shift);
bigint bigint::&operator>>=(const bigint &shift);
bigint bigint::&operator<<=(int shift);
bigint bigint::&operator<<=(const bigint &shift);

int bigint::to_int() const;

const std::string bigint::&get_num() const { return num; }

std::ostream &operator<<(std::ostream &os, const bigint &b);
