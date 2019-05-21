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
class ValueOperator : public Operator< T >
{

public:

	ValueOperator(const T&);

	virtual T compute() const override;
	
	friend std::ostream& operator <<(std::ostream& _o, const ValueOperator& _t)
	{
		return _o << "TODO";
	}

private:

	const T m_value;

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

template< typename T >
ValueOperator< T >::ValueOperator(const T& _value) :
	Operator< T >(),
	m_value(_value)
{
}

template< typename T >
T ValueOperator< T >::compute() const
{
	return m_value;
}