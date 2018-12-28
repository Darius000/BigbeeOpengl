#ifndef VARRAY_H
#define VARRAY_H

#include "Core/Core.h"

namespace BHive
{
	template<class T>
	class BHIVE_API VArray
	{
	public:
		VArray();
		~VArray();

		char* m_Buffer;
		unsigned int m_Size;

		/*VArray<T> operator=(const VArray<T>& array);
		T operator[](int index);*/
	};

	template<class T>
	inline VArray<T>::VArray()
	{
	}

	template<class T>
	inline VArray<T>::~VArray()
	{
	}
}

#endif // VARRAY_H
