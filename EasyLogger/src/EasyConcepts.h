#pragma once

#include <ostream>

template<typename T>
concept Streamable = requires(std::ostream & os, T a)
{
	os << a;
};

template<class T>
concept Parsable = Streamable<T>;