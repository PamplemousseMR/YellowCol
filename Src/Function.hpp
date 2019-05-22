#pragma once

#include "Operator.hpp"

#include <string>

template< typename T >
class Function
{

public:

	Function(const Operator< T >* const);

	~Function();

	Function(const Function&);

	Function& operator=(const Function&) = delete;

	Function(Function&&) = delete;

	Function& operator=(Function&&) = delete;
	
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