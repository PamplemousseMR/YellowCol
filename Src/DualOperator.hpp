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
	DIVISION,
	MINIMUM,
	MAXIMUM
};

template< typename T >
class DualOperator : public Operator< T >
{

public:

	DualOperator(const DualInstruction&, const Operator< T >&, const Operator< T >&);

	virtual T compute(T, T, T, T ,T, T) const override;
	
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
T DualOperator< T >::compute(T _a, T _b, T _c, T _d, T _e, T _f) const
{
	T result = 0;
	switch(m_instruction)
	{
		case DualInstruction::ADDITION :
			result = m_firstOperand->compute(_a, _b, _c, _d, _e, _f) + m_secondOperand->compute(_a, _b, _c, _d, _e, _f);
			break;
		case DualInstruction::SUBTRACTION :
			result = m_firstOperand->compute(_a, _b, _c, _d, _e, _f) - m_secondOperand->compute(_a, _b, _c, _d, _e, _f);
			break;
		case DualInstruction::MULTIPLICATION :
			result = m_firstOperand->compute(_a, _b, _c, _d, _e, _f) * m_secondOperand->compute(_a, _b, _c, _d, _e, _f);
			break;
		case DualInstruction::DIVISION :
			result = m_firstOperand->compute(_a, _b, _c, _d, _e, _f) / m_secondOperand->compute(_a, _b, _c, _d, _e, _f);
			break;
		case DualInstruction::MINIMUM :
			result = std::min(m_firstOperand->compute(_a, _b, _c, _d, _e, _f), m_secondOperand->compute(_a, _b, _c, _d, _e, _f));
			break;
		case DualInstruction::MAXIMUM :
			result = std::max(m_firstOperand->compute(_a, _b, _c, _d, _e, _f), m_secondOperand->compute(_a, _b, _c, _d, _e, _f));
			break;
		default :
			throw "Unknow instruction";
			break;
	}

	return result;
}