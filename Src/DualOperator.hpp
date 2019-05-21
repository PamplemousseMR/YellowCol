#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <string>

#include "Operator.hpp"

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

enum DUAL_INSTRUCTION{
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

	DualOperator(const DUAL_INSTRUCTION&, const Operator< T >*, const Operator< T >* const);

	~DualOperator();

	virtual T compute(T, T, T, T ,T, T) const override;
	
	virtual std::string print() const override;

private:

	const DUAL_INSTRUCTION m_instruction;
	
	const Operator< T >* const m_firstOperand;

	const Operator< T >* const m_secondOperand;

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

template< typename T >
DualOperator< T >::DualOperator(const DUAL_INSTRUCTION& _instruction, const Operator< T >* const _firsOperand, const Operator< T >* const _secondOperand) :
	Operator< T >(),
	m_instruction(_instruction),
	m_firstOperand(_firsOperand),
	m_secondOperand(_secondOperand)
{
}

template< typename T >
DualOperator< T >::~DualOperator()
{
	delete m_firstOperand;
	delete m_secondOperand;
}

template< typename T >
T DualOperator< T >::compute(T _a, T _b, T _c, T _d, T _e, T _f) const
{
	T result = 0;
	switch(m_instruction)
	{
		case DUAL_INSTRUCTION::ADDITION :
			result = m_firstOperand->compute(_a, _b, _c, _d, _e, _f) + m_secondOperand->compute(_a, _b, _c, _d, _e, _f);
			break;
		case DUAL_INSTRUCTION::SUBTRACTION :
			result = m_firstOperand->compute(_a, _b, _c, _d, _e, _f) - m_secondOperand->compute(_a, _b, _c, _d, _e, _f);
			break;
		case DUAL_INSTRUCTION::MULTIPLICATION :
			result = m_firstOperand->compute(_a, _b, _c, _d, _e, _f) * m_secondOperand->compute(_a, _b, _c, _d, _e, _f);
			break;
		case DUAL_INSTRUCTION::DIVISION :
			result = m_firstOperand->compute(_a, _b, _c, _d, _e, _f) / m_secondOperand->compute(_a, _b, _c, _d, _e, _f);
			break;
		case DUAL_INSTRUCTION::MINIMUM :
			result = std::min(m_firstOperand->compute(_a, _b, _c, _d, _e, _f), m_secondOperand->compute(_a, _b, _c, _d, _e, _f));
			break;
		case DUAL_INSTRUCTION::MAXIMUM :
			result = std::max(m_firstOperand->compute(_a, _b, _c, _d, _e, _f), m_secondOperand->compute(_a, _b, _c, _d, _e, _f));
			break;
		default :
			throw "Unknow instruction";
			break;
	}

	return result;
}

template< typename T >
std::string DualOperator< T >::print() const
{
	std::string before = "";
	std::string between = "";
	std::string after = ""; 
	
	switch(m_instruction)
	{
		case DUAL_INSTRUCTION::ADDITION :
			before = "";
			between = "+";
			after = "";
			break;
		case DUAL_INSTRUCTION::SUBTRACTION :
			before = "";
			between = "-";
			after = "";
			break;
		case DUAL_INSTRUCTION::MULTIPLICATION :
			before = "";
			between = "*";
			after = "";
			break;
		case DUAL_INSTRUCTION::DIVISION :
			before = "";
			between = "/";
			after = "";
			break;
		case DUAL_INSTRUCTION::MINIMUM :
			before = "min(";
			between = ",";
			after = ")";
			break;
		case DUAL_INSTRUCTION::MAXIMUM :
			before = "max(";
			between = ",";
			after = ")";
			break;
		default :
			throw "Unknow instruction";
			break;
	}
	
	return before + m_firstOperand->print() + between + m_secondOperand->print() + after ;
}