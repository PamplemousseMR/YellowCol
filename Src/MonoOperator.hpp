#pragma once

#include "Operator.hpp"

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

	MonoOperator(const MONO_INSTRUCTION&, Operator< T >*);

	~MonoOperator();

	MonoOperator(const MonoOperator&);

	MonoOperator& operator=(const MonoOperator&) = delete;

	MonoOperator(MonoOperator&&) = delete;

	MonoOperator& operator=(MonoOperator&&) = delete;

	virtual T compute(T, T, T, T ,T, T) const override;
	
	virtual long long getNumberOfChildOperator() const override;

	virtual int getNumberOfOperator() const override;

	virtual Operator< T >* operator[](long long) override;

	virtual std::string print() const override;

private:

	const MONO_INSTRUCTION m_instruction;
	
	Operator< T >* m_operator;


};