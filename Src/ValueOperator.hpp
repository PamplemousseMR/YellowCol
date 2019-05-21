#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <string>

#include "Operator.hpp"

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

enum ARGUMENT
{
	A,
	B,
	C,
	D,
	E,
	F
};

template< typename T >
class ValueOperator : public Operator< T >
{

public:

	ValueOperator(const ARGUMENT&);

	virtual T compute(T, T, T, T ,T, T) const override;
	
	friend std::ostream& operator <<(std::ostream& _o, const ValueOperator& _t)
	{
		return _o << "TODO";
	}

private:

	const ARGUMENT m_arg;

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

template< typename T >
ValueOperator< T >::ValueOperator(const ARGUMENT& _arg) :
	Operator< T >(),
	m_arg(_arg)
{
}

template< typename T >
T ValueOperator< T >::compute(T _a, T _b, T _c, T _d, T _e, T _f) const
{
	T result = 0;
	switch(m_arg)
	{
		case A:
			result = _a;
			break;
		case B:
			result = _b;
			break;
		case C:
			result = _c;
			break;
		case D:
			result = _d;
			break;
		case E:
			result = _e;
			break;
		case F:
			result = _f;
			break;
	}
	return result;
}