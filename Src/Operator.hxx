#pragma once

#include "Operator.hpp"

#include "ArgumentOperator.hpp"
#include "MonoOperator.hpp"
#include "DualOperator.hpp"
#include "ValueOperator.hpp"

template< typename T >
Operator< T >* Operator< T >::copy(const Operator< T >* _op)
{
  	{
		const ArgumentOperator< T >* const test = dynamic_cast<  const ArgumentOperator< T >* const >(_op);
		if(test)
		{
			return new ArgumentOperator< T >(*test);
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
	{
		const ValueOperator< T >* const test = dynamic_cast<  const ValueOperator< T >* const >(_op);
		if(test)
		{
			return new ValueOperator< T >(*test);
		}
	}
	throw std::invalid_argument("Unknow operator");
	return nullptr;
}