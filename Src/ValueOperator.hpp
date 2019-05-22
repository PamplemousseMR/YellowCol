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

	~ValueOperator();

	ValueOperator(const ValueOperator&) = default;

	ValueOperator& operator=(const ValueOperator&) = delete;

	ValueOperator(ValueOperator&&) = delete;

	ValueOperator& operator=(ValueOperator&&) = delete;

	virtual T compute(T, T, T, T ,T, T) const override;
	
	virtual long long getNumberOfChildOperator() const override;

	virtual int getNumberOfOperator() const override;

	virtual Operator< T >* operator[](long long) override;

	virtual void setOperator(long long, Operator< T >*);

	virtual std::string print() const override;

private:

	ARGUMENT m_arg;

};