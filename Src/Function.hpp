#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <string>

#include "Operator.hpp"

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

template< typename T >
class Function
{

public:

	Function(const Operator< T >* const);

	~Function();

	Function(const Function&) = default;

	Function& operator=(const Function&) = delete;

	Function(Function&&) = default;

	Function& operator=(Function&&) = default;
	
	T compute(T, T, T, T ,T, T) const;

	friend std::ostream& operator <<(std::ostream& _o, const Function& _t)
	{
		return _o << _t.m_operator->print();
	}

private:

	const Operator< T >* m_operator;	

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

template< typename T >
Function< T >::Function(const Operator< T >* const _operator) :
	m_operator(_operator)
{
}

template< typename T >
Function< T >::~Function()
{
	delete m_operator;
}

template< typename T >
T Function< T >::compute(T _a, T _b, T _c, T _d, T _e, T _f) const
{
	return m_operator->compute(_a, _b, _c, _d, _e, _f);
}