#pragma once

#include "Function.hpp"
#include "Operator.hpp"
#include "ValueOperator.hpp"
#include "MonoOperator.hpp"
#include "DualOperator.hpp"

#include <string>

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
Function< T >::Function(const Function& _f)
{
	{
		const ValueOperator< T >* const test = dynamic_cast<  const ValueOperator< T >* const >(_f.m_operator);
		if(test)
		{
			m_operator = new ValueOperator< T >(*test);
			return;
		}
	}
	{
		const MonoOperator< T >* const test = dynamic_cast<  const MonoOperator< T >* const >(_f.m_operator);
		if(test)
		{
			m_operator = new MonoOperator< T >(*test);
			return;
		}
	}
	{
		const DualOperator< T >* const test = dynamic_cast<  const DualOperator< T >* const >(_f.m_operator);
		if(test)
		{
			m_operator = new DualOperator< T >(*test);
			return;
		}
	}
}

template< typename T >
T Function< T >::compute(T _a, T _b, T _c, T _d, T _e, T _f) const
{
	return m_operator->compute(_a, _b, _c, _d, _e, _f);
}

template< typename T >
long long Function< T >::getNumberOfOperator() const
{
	return m_operator->getNumberOfOperator();
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
	return std::sqrt(1/n*sum);
}
