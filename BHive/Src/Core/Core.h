#ifndef CORE_H
#define CORE_H

#ifdef BHIVE_WINDOWS
	#ifdef BH_BUILD_DLL
		#define BHIVE_API// _declspec(dllexport)
	#else
		#define BHIVE_API //_declspec(dllimport)
	#endif
#else
	#error Only Supports Windows!
#endif

#endif