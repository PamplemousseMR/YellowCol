#pragma once

#include "MonoOperator.hpp"
#include "DualOperator.hpp"

#include <string>
#include <functional>

template< typename T >
MonoOperator< T >::MonoOperator(const MONO_INSTRUCTION& _instruction, Operator< T >* const _operand) :
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
		const ValueOperator< T >* const test = dynamic_cast<  const ValueOperator< T >* const >(_f.m_operator);
		if(test)
		{
			m_operator = new ValueOperator< T >(*test);
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
			throw "Unknow instruction";
			break;
	}

	return result;
}

template< typename T >
long long MonoOperator< T >::getNumberOfOperator() const
{
	return m_operator->getNumberOfOperator() + 1;
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
			throw "Unknow instruction";
			break;
	}
	return before + m_operator->print() + after ;
}