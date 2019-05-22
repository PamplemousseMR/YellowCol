#pragma once

#include "Operator.hpp"

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

	DualOperator(const DUAL_INSTRUCTION&, Operator< T >*, Operator< T >*);

	~DualOperator();

	DualOperator(const DualOperator&);

	DualOperator& operator=(const DualOperator&) = delete;

	DualOperator(DualOperator&&) = delete;

	DualOperator& operator=(DualOperator&&) = delete;

	virtual T compute(T, T, T, T ,T, T) const override;
	
	virtual long long getNumberOfChildOperator() const override;

	virtual int getNumberOfOperator() const override;

	virtual Operator< T >* operator[](long long);

	virtual std::string print() const override;

private:

	const DUAL_INSTRUCTION m_instruction;
	
	Operator< T >* m_firstOperand;

	Operator< T >* m_secondOperand;

};