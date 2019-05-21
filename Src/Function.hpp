#pragma once

/* ---------------------------------------------------------------------------------
										Include
--------------------------------------------------------------------------------- */

#include <string>

/* ---------------------------------------------------------------------------------
										Declaration
--------------------------------------------------------------------------------- */

class Function
{

public:

	Function(const Function&) = default;

	Function& operator=(const Function&) = delete;

	Function(Function&&) = default;

	Function& operator=(Function&&) = default;
	
	friend std::ostream& operator <<(std::ostream& _o, const Function& _t)
	{
		return _o << "TODO";
	}

};

/* ---------------------------------------------------------------------------------
										Definition
--------------------------------------------------------------------------------- */