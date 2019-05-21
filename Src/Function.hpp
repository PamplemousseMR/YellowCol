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
	
	float compute() const;

	friend std::ostream& operator <<(std::ostream& _o, const Function& _t)
	{
		return _o << "TODO";
	}

private:

	Operator< float > m_operator;	

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

Function::Function(const Operator< float >& _operator) :
	m_operator(_operator)
{
}

float Function::compute() const
{
	return m_operator.compute();
}