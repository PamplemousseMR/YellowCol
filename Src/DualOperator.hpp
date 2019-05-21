#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

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

	DualOperator(const DualOperator&);

	DualOperator& operator=(const DualOperator&) = delete;

	DualOperator(DualOperator&&) = delete;

	DualOperator& operator=(DualOperator&&) = delete;

	virtual T compute(T, T, T, T ,T, T) const override;
	
	virtual long long getNumberOfOperator() const override;

	virtual std::string print() const override;

private:

	const DUAL_INSTRUCTION m_instruction;
	
	const Operator< T >* m_firstOperand;

	const Operator< T >* m_secondOperand;

};