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

	Operator(const Operator&) = default;

	Operator& operator=(const Operator&) = delete;

	Operator(Operator&&) = default;

	Operator& operator=(Operator&&) = default;

	virtual T compute(T, T, T, T ,T, T) const;

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