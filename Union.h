#ifndef TUT_UTILITY_UNION_H
#define TUT_UTILITY_UNION_H

#include "Union_decl.h"
#include "UtilityTemplates.h"

namespace tut {

#define TUT_UNION_ASSERT_BOUNDS(I, Args) static_assert(sizeof...(Args) > I && I >= 0, "index out of bounds for union")
#define TUT_UNION_ASSERT_TYPE_IN_UNION(T, Args) static_assert(::tut::impl::TypeToIndex<T, Args...>::value != -1, "no union member has the provided type")

	template<typename T, typename... Args>
	struct Union<T, Args...>
	{
		union
		{
			T head;
			Union<Args...> tail;
		};
	};

	template<>
	struct Union<>
	{
	};

	template<int I>
	struct Get
	{
		template<typename... Args>
		static auto get(Union<Args...>& u) -> decltype(impl::GetHelper<I, 0, Args...>::get(u)) {
			TUT_UNION_ASSERT_BOUNDS(I, Args);
			return impl::GetHelper<I, 0, Args...>::get(u);
		}
	};

	template<int I>
	struct Set
	{
		template<typename V, typename... Args>
		static void set(Union<Args...>& u, V&& v) {
			TUT_UNION_ASSERT_BOUNDS(I, Args);
			impl::SetHelper<I, 0, V, Args...>::set(u, std::forward<V>(v));
		}
	};

	namespace impl {

		template<int I, int J, typename T, typename... Args>
		struct GetHelper<I, J, T, Args...>
		{
			static auto get(Union<T, Args...>& u) -> decltype(GetHelper<I, J + 1, Args...>::get(u.tail)){
				return GetHelper<I, J + 1, Args...>::get(u.tail);
			}
		};

		template<int I, typename T, typename... Args>
		struct GetHelper<I, I, T, Args...>
		{
			static auto get(Union<T, Args...>& u) -> T& {
				return u.head;
			}
		};

		template<int I, int J, typename V, typename T, typename... Args>
		struct SetHelper<I, J, V, T, Args...>
		{
			static void set(Union<T, Args...>& u, V&& v) {
				SetHelper<I, J + 1, V, Args...>::set(u.tail, std::forward<V>(v));
			}
		};

		template<int I, typename V, typename T, typename... Args>
		struct SetHelper<I, I, V, T, Args...>
		{
			static void set(tut::Union<T, Args...>& u, V&& v) {
				u.head = std::forward<V>(v);
			}
		};
	};

};

#endif