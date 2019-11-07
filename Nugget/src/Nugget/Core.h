#pragma once

#ifdef NE_PLATFORM_WINDOWS
	#ifdef NE_BUILD_DLL
		#define NUGGET_API __declspec(dllexport)
	#else
		#define NUGGET_API __declspec(dllimport)
	#endif
#else
	#error Nugget only supports Windows for now...
#endif

#define BIT(x) (1 << x)