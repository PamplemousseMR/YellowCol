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
	
	T bench(vector< vector< T > >) const;

	long long getNumberOfOperator() const;

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
