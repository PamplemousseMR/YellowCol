#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include "Operator.hpp"

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

enum MONO_INSTRUCTION{
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

	MonoOperator(const MONO_INSTRUCTION&, Operator< T >* const);

	~MonoOperator();

	MonoOperator(const MonoOperator&);

	MonoOperator& operator=(const MonoOperator&) = delete;

	MonoOperator(MonoOperator&&) = delete;

	MonoOperator& operator=(MonoOperator&&) = delete;

	virtual T compute(T, T, T, T ,T, T) const override;
	
	virtual long long getNumberOfOperator() const override;

	virtual std::string print() const override;

private:

	const MONO_INSTRUCTION m_instruction;
	
	const Operator< T >* m_operator;


};