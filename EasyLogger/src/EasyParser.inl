#include "EasyParser.h"

namespace EasyLogger {

	template<Parsable ...Vars>
	inline const char* EasyParser::ParseText(const char* text, Vars && ...vars) const
	{
		return nullptr;
	}

	template<Parsable T>
	inline const char* EasyParser::InsertVar(T& var, DelimiterPosition& position)
	{
		return nullptr;
	}

	template<Parsable T>
	inline const char* EasyParser::ColourVariable(T& var, DelimiterPosition& position)
	{
		return var;
	}

}