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
class ArgumentOperator : public Operator< T >
{

public:

	ArgumentOperator(const ARGUMENT&);

	ArgumentOperator(const ArgumentOperator&) = default;

	ArgumentOperator& operator=(const ArgumentOperator&) = delete;

	ArgumentOperator(ArgumentOperator&&) = delete;

	ArgumentOperator& operator=(ArgumentOperator&&) = delete;

	virtual T compute(T, T, T, T ,T, T) const override;
	
	virtual long long getNumberOfChildOperator() const override;

	virtual int getNumberOfOperator() const override;

	virtual Operator< T >* operator[](long long) override;

	virtual void setOperator(long long, Operator< T >*);
	
	virtual void mutate(int);

	virtual std::string print() const override;

private:

	ARGUMENT m_arg;

};