#pragma once

#include "Operator.hpp"

#include "ValueOperator.hpp"
#include "MonoOperator.hpp"
#include "DualOperator.hpp"


template< typename T >
Operator< T >* Operator< T >::copy(const Operator< T >* _op)
{
  	{
		const ValueOperator< T >* const test = dynamic_cast<  const ValueOperator< T >* const >(_op);
		if(test)
		{
			return new ValueOperator< T >(*test);
		}
	}
	{
		const MonoOperator< T >* const test = dynamic_cast<  const MonoOperator< T >* const >(_op);
		if(test)
		{
			return new MonoOperator< T >(*test);
		}
	}
	{
		const DualOperator< T >* const test = dynamic_cast<  const DualOperator< T >* const >(_op);
		if(test)
		{
			return new DualOperator< T >(*test);
		}
	}
	throw std::invalid_argument("Unknow operator");
	return nullptr;
}