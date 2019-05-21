#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <string>

#include "Operator.hpp"

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

enum DualInstruction{
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION
};

template< typename T >
class DualOperator : public Operator< T >
{

public:

	DualOperator(const DualInstruction&, const Operator< T >&, const Operator< T >&);

	virtual T compute() const override;
	
	friend std::ostream& operator <<(std::ostream& _o, const DualOperator& _t)
	{
		return _o << "TODO";
	}

private:

	const DualInstruction m_instruction;
	
	const Operator< T >* const m_firstOperand;

	const Operator< T >* const m_secondOperand;

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

template< typename T >
DualOperator< T >::DualOperator(const DualInstruction& _instruction, const Operator< T >& _firsOperand, const Operator< T >& _secondOperand) :
	Operator< T >(),
	m_instruction(_instruction),
	m_firstOperand(&_firsOperand),
	m_secondOperand(&_secondOperand)
{
}

template< typename T >
T DualOperator< T >::compute() const
{
	T result = 0;
	switch(m_instruction)
	{
		case DualInstruction::ADDITION :
			result = m_firstOperand->compute() + m_secondOperand->compute();
			break;
		case DualInstruction::SUBTRACTION :
			result = m_firstOperand->compute() - m_secondOperand->compute();
			break;
		case DualInstruction::MULTIPLICATION :
			result = m_firstOperand->compute() * m_secondOperand->compute();
			break;
		case DualInstruction::DIVISION :
			result = m_firstOperand->compute() / m_secondOperand->compute();
			break;
		default :
			throw "Unknow instruction";
			break;
	}

	return result;
}