#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <string>

#include "Operator.hpp"

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

class Function
{

public:

	Function(const Operator< float >&);

	Function(const Function&) = default;

	Function& operator=(const Function&) = delete;

	Function(Function&&) = default;

	Function& operator=(Function&&) = default;
	
	float compute(float, float, float, float ,float, float) const;

	friend std::ostream& operator <<(std::ostream& _o, const Function& _t)
	{
		return _o << _t.m_operator->print();
	}

private:

	const Operator< float >* m_operator;	

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

Function::Function(const Operator< float >& _operator) :
	m_operator(&_operator)
{
}

float Function::compute(float _a, float _b, float _c, float _d, float _e, float _f) const
{
	return m_operator->compute(_a, _b, _c, _d, _e, _f);
}