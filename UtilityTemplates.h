#ifndef TUT_UTILITY_TEMPLATES_H
#define TUT_UTILITY_TEMPLATES_H

#include "UtilityTemplates_decl.h"

namespace tut {
	namespace impl {

		template<class T, class... Args>
		struct TypeToIndex
		{
			enum{ value = TypeToIndexHelper<0, T, Args...>::value };
		};

		template<int I, class T, class U, class... Args>
		struct TypeToIndexHelper<I, T, U, Args...>
		{
			enum{ value = TypeToIndexHelper<I + 1, T, Args...>::value };
		};

		template<int I, class T, class... Args>
		struct TypeToIndexHelper<I, T, T, Args...>
		{
			enum{ value = I };
		};

		template<int I, class T>
		struct TypeToIndexHelper<I, T>
		{
			enum{ value = -1 };
		};

		template<class T, class... Args>
		struct IndexOfType
		{
			enum{ value = IndexOfTypeHelper<0, T, Args...>::value };
		};

		template<int I, class T, class U, class... Args>
		struct IndexOfTypeHelper<I, T, U, Args...>
		{
			enum{ value = TypeToIndexHelper<I + 1, T, Args...>::value };
		};

		template<int I, class T, class... Args>
		struct IndexOfTypeHelper<I, T, T, Args...>
		{
			enum{ value = I };
		};

		template<int I, class T>
		struct IndexOfTypeHelper<I, T>
		{
			enum{ value = -1 };
		};

	};
};

#endif