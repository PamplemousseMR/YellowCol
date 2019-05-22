#pragma once

#include <string>

template< typename T >
class Operator
{

public:

	Operator() = default;

	virtual ~Operator() = default;

	Operator(const Operator&) = default;

	Operator& operator=(const Operator&) = delete;

	Operator(Operator&&) = delete;

	Operator& operator=(Operator&&) = delete;

	virtual T compute(T, T, T, T ,T, T) const = 0;

	virtual long long getNumberOfOperator() const = 0;
	
	virtual std::string print() const = 0;

};