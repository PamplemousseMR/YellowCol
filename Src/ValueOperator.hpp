#pragma once

#include "Operator.hpp"

enum ARGUMENT
{
	A,
	B,
	C,
	D,
	E,
	F
};

template< typename T >
class ValueOperator : public Operator< T >
{

public:

	ValueOperator(const ARGUMENT&);

	ValueOperator(const ValueOperator&) = default;

	ValueOperator& operator=(const ValueOperator&) = delete;

	ValueOperator(ValueOperator&&) = delete;

	ValueOperator& operator=(ValueOperator&&) = delete;

	virtual T compute(T, T, T, T ,T, T) const override;
	
	virtual long long getNumberOfChildOperator() const override;

	virtual int getNumberOfOperator() const override;

	virtual Operator< T >* operator[](long long) override;

	virtual std::string print() const override;

private:

	const ARGUMENT m_arg;

};