#pragma once

#include "Function.hpp"
#include "Operator.hpp"
#include "ArgumentOperator.hpp"
#include "MonoOperator.hpp"
#include "DualOperator.hpp"

#include <string>

template< typename T >
Function< T >::Function(Operator< T >* _operator) :
	m_operator(_operator)
{
}

template< typename T >
Function< T >::~Function()
{
	delete m_operator;
}

template< typename T >
Function< T >::Function(const Function& _f)
{
	m_operator = Operator< T >::copy(_f.m_operator);
}

template< typename T >
T Function< T >::compute(T _a, T _b, T _c, T _d, T _e, T _f) const
{
	return m_operator->compute(_a, _b, _c, _d, _e, _f);
}

template< typename T >
long long Function< T >::getNumberOfChildOperator() const
{
	return m_operator->getNumberOfChildOperator();
}

template< typename T >
Operator< T >* Function< T >::getOperator() const
{
	return m_operator;
}

template< typename T >
void Function< T >::setOperator(long long _value, Operator< T >* _operator)
{
	if(_value <= 0)
	{
		delete m_operator;
		m_operator = _operator;
	} 
	else
	{
		m_operator->setOperator(_value-1, _operator);
	}
}

template< typename T >
T Function< T >::bench(vector< vector< T > > _table) const
{
	float n = (float)_table.size();
	T sum = 0;
	for(auto row : _table){
		T temp = compute(row[0], row[1], row[2], row[3], row[4], row[5]) - row[6];
		if(std::isnan(temp)){
			//return a hight value 
			return 1000000000000;
		}
		sum += temp*temp;
	}
	return std::sqrt((1/n)*sum);
}
