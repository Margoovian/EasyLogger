#include <epch.h>
#include "EasyParser.h"

namespace EasyLogger {

	

	const char* EasyParser::ParseText(const char* text) const
	{
		return text;
	}

	std::vector<DelimiterPosition> EasyParser::GetDelimiterPositions(const char* text)
	{
		return std::vector<DelimiterPosition>();
	}

	const char* EasyParser::ColourText(const char* text, DelimiterPosition& position)
	{
		return text;
	}

}