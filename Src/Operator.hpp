#pragma once

#include <string>

template< typename T >
class Operator
{

public:

	static Operator< T >* copy(const Operator< T >*);

	Operator() = default;

	virtual ~Operator() = default;

	Operator(const Operator&) = default;

	Operator& operator=(const Operator&) = delete;

	Operator(Operator&&) = delete;

	Operator& operator=(Operator&&) = delete;

	virtual T compute(T, T, T, T ,T, T) const = 0;

	virtual long long getNumberOfChildOperator() const = 0;
	
	virtual int getNumberOfOperator() const = 0;

	virtual Operator< T >* operator[](long long) = 0;

	virtual void setOperator(long long, Operator< T >*) = 0;
	
	virtual void mutate(int) = 0;

	virtual std::string print() const = 0;

};