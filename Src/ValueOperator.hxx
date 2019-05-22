#pragma once

#include "ValueOperator.hpp"

#include <string>

template< typename T >
ValueOperator< T >::ValueOperator(const ARGUMENT& _arg) :
	Operator< T >(),
	m_arg(_arg)
{
}

template< typename T >
ValueOperator< T >::~ValueOperator()
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
			throw std::invalid_argument("Unknow instruction");
			break;
	}
	return result;
}

template< typename T >
long long ValueOperator< T >::getNumberOfChildOperator() const
{
	return 1;
}

template< typename T >
int ValueOperator< T >::getNumberOfOperator() const
{
	return 0;
}

template< typename T >
Operator< T >* ValueOperator< T >::operator[](long long _value)
{
	if(_value <= 0)
	{
		return this;
	}
	else
	{
		throw std::invalid_argument("Unknow index");
	}
}

template< typename T >
void ValueOperator< T >::setOperator(long long, Operator< T >* _operator)
{
	const ValueOperator< T >* const test = dynamic_cast<  const ValueOperator< T >* const >(_operator);
	if(test)
	{
		m_arg = test->m_arg;
		return;
	}
	throw std::invalid_argument("Can't change this operator");
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
			throw std::invalid_argument("Unknow instruction");
			break;
	}
	
	return value ;
}