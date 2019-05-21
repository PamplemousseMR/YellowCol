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

	ValueOperator(const ValueOperator&) = default;

	ValueOperator& operator=(const ValueOperator&) = delete;

	ValueOperator(ValueOperator&&) = delete;

	ValueOperator& operator=(ValueOperator&&) = delete;

	virtual T compute(T, T, T, T ,T, T) const override;
	
	virtual long long getNumberOfOperator() const override;

	virtual std::string print() const override;

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
		default:
			throw "Unknow instruction";
			break;
	}
	return result;
}

template< typename T >
long long ValueOperator< T >::getNumberOfOperator() const
{
	return 1;
}

template< typename T >
std::string ValueOperator< T >::print() const
{
	std::string value = "";
	switch(m_arg)
	{
		case A:
			value = "A";
			break;
		case B:
			value = "B";
			break;
		case C:
			value = "C";
			break;
		case D:
			value = "D";
			break;
		case E:
			value = "E";
			break;
		case F:
			value = "F";
			break;
		default:
			throw "Unknow instruction";
			break;
	}
	
	return value ;
}