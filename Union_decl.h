#ifndef TUT_UTILITY_UNION_DECL_H
#define TUT_UTILITY_UNION_DECL_H

namespace tut {
	namespace impl {
		template<int I, int J, typename... Args>
		struct GetHelper;

		template<int I, int J, typename V, typename... Args>
		struct SetHelper;
	};

	template<typename... Args>
	struct Union;

	template<int I>
	struct Get;

	template<int I>
	struct Set;

	class InvalidMemoryReadException;
};

#endif