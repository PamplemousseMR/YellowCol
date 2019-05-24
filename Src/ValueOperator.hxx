#pragma once

#include "ValueOperator.hpp"

#include <string>

template< typename T >
ValueOperator< T >::ValueOperator(const T& _value) :
	Operator< T >(),
	m_value(_value)
{
}

template< typename T >
T ValueOperator< T >::compute(T _a, T _b, T _c, T _d, T _e, T _f) const
{
	return m_value;
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
		m_value = test->m_value;
		return;
	}
	throw std::invalid_argument("Can't change this operator");
}

template< typename T >
std::string ValueOperator< T >::print() const
{
	std::ostringstream ss;
	ss << m_value;
	return ss.str();
}