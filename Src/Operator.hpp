#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <string>

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

template< typename T >
class Operator
{

public:

	Operator() = default;

	virtual ~Operator();

	Operator(const Operator&) = delete;

	Operator& operator=(const Operator&) = delete;

	Operator(Operator&&) = default;

	Operator& operator=(Operator&&) = default;

	virtual T compute(T, T, T, T ,T, T) const;

	virtual long long getNumberOfOperator() const;
	
	virtual std::string print() const ;

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

template< typename T >
T Operator< T >::compute(T, T, T, T ,T, T) const
{
	throw "'T Operator::compute() const' need to be override";
	return T();
}

template< typename T >
Operator< T >::~Operator()
{
}

template< typename T >
std::string Operator< T >::print() const
{
	throw "'std::string Operator::print() const' need to be override";
	return "";
}

template< typename T >
long long Operator< T >::getNumberOfOperator() const
{
	throw "'long long Operator::getNumberOfOperator() const' need to be override";
	return 0;
}