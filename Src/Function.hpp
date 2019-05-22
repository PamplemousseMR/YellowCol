#pragma once

#include "Operator.hpp"

#include <string>

template< typename T >
class Function
{

public:

	Function(Operator< T >*);

	~Function();

	Function(const Function&);

	Function& operator=(const Function&) = delete;

	Function(Function&&) = delete;

	Function& operator=(Function&&) = delete;
	
	T compute(T, T, T, T ,T, T) const;
	
	T bench(vector< vector< T > >) const;

	long long getNumberOfChildOperator() const;

	Operator< T >* getOperator() const;

	void setOperator(long long, Operator< T >*);

	friend std::ostream& operator <<(std::ostream& _o, const Function& _t)
	{
		return _o << _t.m_operator->print();
	}

private:

	Operator< T >* m_operator;	

};