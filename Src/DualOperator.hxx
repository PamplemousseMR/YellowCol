#include <string>

#include "DualOperator.hpp"
#include "MonoOperator.hpp"

template< typename T >
DualOperator< T >::DualOperator(const DUAL_INSTRUCTION& _instruction, const Operator< T >* const _firsOperand, const Operator< T >* const _secondOperand) :
	Operator< T >(),
	m_instruction(_instruction),
	m_firstOperand(_firsOperand),
	m_secondOperand(_secondOperand)
{
}

template< typename T >
DualOperator< T >::~DualOperator()
{
	delete m_firstOperand;
	delete m_secondOperand;
}

template< typename T >
DualOperator< T >::DualOperator(const DualOperator& _f) :
	m_instruction(_f.m_instruction)
{
	{
		const ValueOperator< T >* const test = dynamic_cast<  const ValueOperator< T >* const >(_f.m_firstOperand);
		if(test)
		{
			m_firstOperand = new ValueOperator< T >(*test);
		}
	}
	{
		const MonoOperator< T >* const test = dynamic_cast<  const MonoOperator< T >* const >(_f.m_firstOperand);
		if(test)
		{
			m_firstOperand = new MonoOperator< T >(*test);
		}
	}
	{
		const DualOperator< T >* const test = dynamic_cast<  const DualOperator< T >* const >(_f.m_firstOperand);
		if(test)
		{
			m_firstOperand = new DualOperator< T >(*test);
		}
	}

	{
		const ValueOperator< T >* const test = dynamic_cast<  const ValueOperator< T >* const >(_f.m_secondOperand);
		if(test)
		{
			m_secondOperand = new ValueOperator< T >(*test);
			return;
		}
	}
	{
		const MonoOperator< T >* const test = dynamic_cast<  const MonoOperator< T >* const >(_f.m_secondOperand);
		if(test)
		{
			m_secondOperand = new MonoOperator< T >(*test);
			return;
		}
	}
	{
		const DualOperator< T >* const test = dynamic_cast<  const DualOperator< T >* const >(_f.m_secondOperand);
		if(test)
		{
			m_secondOperand = new DualOperator< T >(*test);
			return;
		}
	}
}

template< typename T >
T DualOperator< T >::compute(T _a, T _b, T _c, T _d, T _e, T _f) const
{
	T result = 0;
	switch(m_instruction)
	{
		case DUAL_INSTRUCTION::ADDITION :
			result = m_firstOperand->compute(_a, _b, _c, _d, _e, _f) + m_secondOperand->compute(_a, _b, _c, _d, _e, _f);
			break;
		case DUAL_INSTRUCTION::SUBTRACTION :
			result = m_firstOperand->compute(_a, _b, _c, _d, _e, _f) - m_secondOperand->compute(_a, _b, _c, _d, _e, _f);
			break;
		case DUAL_INSTRUCTION::MULTIPLICATION :
			result = m_firstOperand->compute(_a, _b, _c, _d, _e, _f) * m_secondOperand->compute(_a, _b, _c, _d, _e, _f);
			break;
		case DUAL_INSTRUCTION::DIVISION :
			result = m_firstOperand->compute(_a, _b, _c, _d, _e, _f) / m_secondOperand->compute(_a, _b, _c, _d, _e, _f);
			break;
		case DUAL_INSTRUCTION::MINIMUM :
			result = std::min(m_firstOperand->compute(_a, _b, _c, _d, _e, _f), m_secondOperand->compute(_a, _b, _c, _d, _e, _f));
			break;
		case DUAL_INSTRUCTION::MAXIMUM :
			result = std::max(m_firstOperand->compute(_a, _b, _c, _d, _e, _f), m_secondOperand->compute(_a, _b, _c, _d, _e, _f));
			break;
		default :
			throw "Unknow instruction";
			break;
	}

	return result;
}

template< typename T >
long long DualOperator< T >::getNumberOfOperator() const
{
	return m_firstOperand->getNumberOfOperator() + m_secondOperand->getNumberOfOperator() + 1;;
}

template< typename T >
std::string DualOperator< T >::print() const
{
	std::string before = "";
	std::string between = "";
	std::string after = ""; 
	
	switch(m_instruction)
	{
		case DUAL_INSTRUCTION::ADDITION :
			before = "";
			between = "+";
			after = "";
			break;
		case DUAL_INSTRUCTION::SUBTRACTION :
			before = "";
			between = "-";
			after = "";
			break;
		case DUAL_INSTRUCTION::MULTIPLICATION :
			before = "";
			between = "*";
			after = "";
			break;
		case DUAL_INSTRUCTION::DIVISION :
			before = "";
			between = "/";
			after = "";
			break;
		case DUAL_INSTRUCTION::MINIMUM :
			before = "min(";
			between = ",";
			after = ")";
			break;
		case DUAL_INSTRUCTION::MAXIMUM :
			before = "max(";
			between = ",";
			after = ")";
			break;
		default :
			throw "Unknow instruction";
			break;
	}
	
	return before + m_firstOperand->print() + between + m_secondOperand->print() + after ;
}