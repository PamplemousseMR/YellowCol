#pragma once

#include "Operator.hpp"

template< typename T >
class ValueOperator : public Operator< T >
{

public:

	ValueOperator(const T&);

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

	T m_value;

};