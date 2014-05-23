#ifndef TUT_UTILITY_TEMPLATES_DECL_H
#define TUT_UTILITY_TEMPLATES_DECL_H

namespace tut {
	namespace impl {
		template<class T, class... Args>
		struct TypeToIndex;

		template<int I, class T, class... Args>
		struct TypeToIndexHelper;

		template<class T, class... Args>
		struct IndexOfType;

		template<int I, class T, class... Args>
		struct IndexOfTypeHelper;
	};
};

#endif