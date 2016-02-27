#include "wsTrace.hpp"
#include <iostream>
#include <stdarg.h>

void trace(size_t n, ...)
{
	return;
	va_list p;
	va_start(p, n);
	for (size_t i = 0; i < n; i++)
	{
		std::cout << va_arg(p, const char*);
	}
	va_end(p);
	std::cout << std::endl;
}