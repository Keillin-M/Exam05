#include "bigint.hpp"

void bigint::clean()
{
	while (num.size() > 1 && num[0] == '0')
		num.erase(0, 1);
}

bigint::bigint(const std::string &s) : num(s) { clean(); }
bigint::bigint(int n) : num(std::to_string(n)) {}

bigint bigint::operator+(const bigint &other) const
{
	std::string a = num, b = other.num;
	std::string result = "";
	int carry = 0, i = a.size() - 1, j = b.size() - 1;

	while (i >= 0 || j >= 0 || carry)
	{
		int sum = carry;

		if (i >= 0)
			sum += a[i--] - '0';
		if (j >= 0)
			sum += b[j--] - '0';
		result = char(sum % 10 + '0') + result;
		carry = sum / 10;
	}
	return bigint(result);
}

bigint &bigint::operator+=(const bigint &other)
{
	*this = *this + other;
	return *this;
}

bigint &bigint::operator++()
{
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint temp = *this;
	++(*this);
	return temp;
}

bigint bigint::operator<<(int shift) const
{
	if (num == "0")
		return bigint("0");
	return bigint(num + std::string(shift, '0'));
}

bigint bigint::operator<<(const bigint &shift) const
{
	return *this << shift.to_int();
}

bigint bigint::operator>>(int shift) const
{
	if (shift >= (int)num.size())
		return bigint("0");
	std::string result = num.substr(0, num.size() - shift);
	if (result.empty())
		return bigint("0");
	else
		return bigint(result);
}

bigint bigint::operator>>(const bigint &shift) const
{
        return *this >> shift.to_int();
}

bigint &bigint::operator<<=(int shift)
{
	*this = *this << shift;
	return *this;
}

bigint &bigint::operator<<=(const bigint &shift)
{
        *this = *this << shift;
        return *this;
}

bigint &bigint::operator>>=(int shift)
{
        *this = *this >> shift;
        return *this;
}

bigint &bigint::operator>>=(const bigint &shift)
{
        *this = *this >> shift;
        return *this;
}

bool bigint::operator<(const bigint &other) const
{
	if (num.size() != other.num.size())
		return num.size() < other.num.size();
	return num < other.num;
}

bool bigint::operator>(const bigint &other) const
{
	return other < *this;
}

bool bigint::operator==(const bigint &other) const
{
	return num == other.num;
}

bool bigint::operator!=(const bigint &other) const
{
	return !(*this == other);
}

bool bigint::operator<=(const bigint &other) const
{
	return *this < other || *this == other;
}

bool bigint::operator>=(const bigint &other) const
{
        return *this > other || *this == other;
}

int bigint::to_int() const
{
	int result = 0;
	for (size_t i = 0; i < num.size(); i++)
		result = result * 10 + (num[i] - '0');
	return result;
}

std::ostream &operator<<(std::ostream &os, const bigint &b)
{
	return os << b.get_num();
}
