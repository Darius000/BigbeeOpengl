#ifndef OBJECT_H
#define OBJECT_H

#include "Core.h"

namespace BHive
{
	class BHIVE_API Object
	{
	public:
		Object();
		//Object(const Object& other);
		~Object();

	private:
		String displayName;

		bool destroyed;

	public:

		String GetDisplayName();
		String GetClassDisplayName();
		void SetDisplayName(const String& string);
		void Destroy();
		bool IsDestroyed();
		virtual void DestroyOptions();
	};

	template <class T> 
	struct ErasePredicateShared
	{
		ErasePredicateShared(const T& inPointer)
			:Pointer(inPointer)
		{
			
		}

		const T& Pointer;

		bool operator()(const std::shared_ptr<T>& SharedPointer) const {
			return SharedPointer.get() == &Pointer;
		}
	};

	template <class T>
	struct ErasePredicateUnique
	{
		ErasePredicateUnique(const T& inPointer)
			:Pointer(inPointer)
		{

		}

		const T& Pointer;

		bool operator()(const std::unique_ptr<T>& UniquePointer) const {
			return UniquePointer.get() == &Pointer;
		}
	};
}
#endif // OBJECT_H
