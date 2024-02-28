#pragma once
#include <memory>

#ifdef RA_ENABLE_ASSERTS
	#define RA_ASSERT(x, ...) { if(!x) { AX_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RA_ASSERT(x, ...) 
#endif

#define RA_BIT(x) (1 << x)