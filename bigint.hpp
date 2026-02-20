#pragma once
#include <string>
#include <iostream>

class bigint
{
private:
	std::string num;
	void clean();

public:
	bigint(const std::string &s = "0");
	bigint(int n);

	bigint operator+(const bigint &other) const;
	bigint &operator+=(const bigint &other);
	bigint &operator++();
	bigint operator++(int);

	bigint operator<<(int shift) const;
	bigint operator<<(const bigint &shift) const;
	bigint operator>>(int shift) const;
        bigint operator>>(const bigint &shift) const;
	bigint &operator<<=(int shift);
	bigint &operator<<=(const bigint &shift);
	bigint &operator>>=(int shift);
        bigint &operator>>=(const bigint &shift);

	bool operator<(const bigint &other) const;
	bool operator>(const bigint &other) const;
	bool operator==(const bigint &other) const;
	bool operator!=(const bigint &other) const;
	bool operator<=(const bigint &other) const;
	bool operator>=(const bigint &other) const;

	int to_int() const;
	const std::string &get_num() const { return num; }
};

std::ostream &operator<<(std::ostream &os, const bigint &b);
