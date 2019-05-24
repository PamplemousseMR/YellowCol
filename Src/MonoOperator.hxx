#pragma once

#include "MonoOperator.hpp"
#include "DualOperator.hpp"
#include "ValueOperator.hpp"

#include <string>
#include <functional>

template< typename T >
MonoOperator< T >::MonoOperator(const MONO_INSTRUCTION& _instruction, Operator< T >* _operand) :
	Operator< T >(),
	m_instruction(_instruction),
	m_operator(_operand)
{
}

template< typename T >
MonoOperator< T >::~MonoOperator()
{
	delete m_operator;
}

template< typename T >
MonoOperator< T >::MonoOperator(const MonoOperator& _f) :
	m_instruction(_f.m_instruction)
{
	{
		const ArgumentOperator< T >* const test = dynamic_cast<  const ArgumentOperator< T >* const >(_f.m_operator);
		if(test)
		{
			m_operator = new ArgumentOperator< T >(*test);
			return;
		}
	}
	{
		const MonoOperator< T >* const test = dynamic_cast<  const MonoOperator< T >* const >(_f.m_operator);
		if(test)
		{
			m_operator = new MonoOperator< T >(*test);
			return;
		}
	}
	{
		const DualOperator< T >* const test = dynamic_cast<  const DualOperator< T >* const >(_f.m_operator);
		if(test)
		{
			m_operator = new DualOperator< T >(*test);
			return;
		}
	}
	{
		const ValueOperator< T >* const test = dynamic_cast<  const ValueOperator< T >* const >(_f.m_operator);
		if(test)
		{
			m_operator = new ValueOperator< T >(*test);
			return;
		}
	}

	if(m_operator == nullptr)
	{
		throw std::invalid_argument("Unknow operator");
	}
}

template< typename T >
T MonoOperator< T >::compute(T _a, T _b, T _c, T _d, T _e, T _f) const
{
	T result = 0;
	switch(m_instruction)
	{
		case MONO_INSTRUCTION::SQUARE_ROOT :
			result = std::sqrt(m_operator->compute(_a, _b, _c, _d, _e, _f));
			break;
		case MONO_INSTRUCTION::LOG :
			result = std::log(m_operator->compute(_a, _b, _c, _d, _e, _f));
			break;
		case MONO_INSTRUCTION::ABSOLUTE :
			result = std::abs(m_operator->compute(_a, _b, _c, _d, _e, _f));
			break;
		case MONO_INSTRUCTION::NEGATION :
			result = - m_operator->compute(_a, _b, _c, _d, _e, _f);
			break;
		case MONO_INSTRUCTION::INVERSION :
			result = 1 / m_operator->compute(_a, _b, _c, _d, _e, _f);
			break;
		default :
			throw std::invalid_argument("Unknow instruction");
			break;
	}

	return result;
}

template< typename T >
long long MonoOperator< T >::getNumberOfChildOperator() const
{
	return m_operator->getNumberOfChildOperator() + 1;
}

template< typename T >
int MonoOperator< T >::getNumberOfOperator() const
{
	return 1;
}

template< typename T >
Operator< T >* MonoOperator< T >::operator[](long long _value)
{
	if(_value <= 0)
	{
		return this;
	}
	else
	{
		return (*m_operator)[_value-1];
	}
}

template< typename T >
void MonoOperator< T >::setOperator(long long _value, Operator< T >* _operator)
{
	if(_value <= 0)
	{
		delete m_operator;
		m_operator = _operator;
	} 
	else
	{
		m_operator->setOperator(_value-1, _operator);
	}
}

template< typename T >
std::string MonoOperator< T >::print() const
{
	
	std::string before = "";
	std::string after = ""; 
	switch(m_instruction)
	{
		case MONO_INSTRUCTION::SQUARE_ROOT :
			before = "sqrt(";
			after = ")";
			break;
		case MONO_INSTRUCTION::LOG :
			before = "log(";
			after = ")";
			break;
		case MONO_INSTRUCTION::ABSOLUTE :
			before = "abs(";
			after = ")";
			break;
		case MONO_INSTRUCTION::NEGATION :
			before = "neg(";
			after = ")";
			break;
		case MONO_INSTRUCTION::INVERSION :
			before = "inv(";
			after = ")";
			break;
		default :
			throw std::invalid_argument("Unknow instruction");
			break;
	}
	return before + m_operator->print() + after ;
}

template< typename T >
void MonoOperator< T >::mutate(int _rand)
{
	int rand = globalRandomGenerator->random(0, 10001);
	if(rand < _rand)
	{
		m_instruction = static_cast< MONO_INSTRUCTION >(globalRandomGenerator->random(0, 5));
	}
	m_operator->mutate(_rand);
}