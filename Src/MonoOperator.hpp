#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <string>
#include <functional>

#include "Operator.hpp"

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

enum MonoInstruction{
	SQUARE_ROOT,
	LOG,
	ABSOLUTE,
	NEGATION,
	INVERSION
};

template< typename T >
class MonoOperator : public Operator< T >
{

public:

	MonoOperator(const MonoInstruction&, const Operator< T >&);

	virtual T compute() const override;
	
	friend std::ostream& operator <<(std::ostream& _o, const MonoOperator& _t)
	{
		return _o << "TODO";
	}

private:

	const MonoInstruction m_instruction;
	
	const Operator< T >* const m_operand;


};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */

template< typename T >
MonoOperator< T >::MonoOperator(const MonoInstruction& _instruction, const Operator< T >& _operand) :
	Operator< T >(),
	m_instruction(_instruction),
	m_operand(&_operand)
{
}

template< typename T >
T MonoOperator< T >::compute() const
{
	T result = 0;
	switch(m_instruction)
	{
		case MonoInstruction::SQUARE_ROOT :
			result = std::sqrt(m_operand->compute());
			break;
		case MonoInstruction::LOG :
			result = std::log(m_operand->compute());
			break;
		case MonoInstruction::ABSOLUTE :
			result = std::abs(m_operand->compute());
			break;
		case MonoInstruction::NEGATION :
			result = - m_operand->compute();
			break;
		case MonoInstruction::INVERSION :
			result = 1 / m_operand->compute();
			break;
		default :
			throw "Unknow instruction";
			break;
	}

	return result;
}