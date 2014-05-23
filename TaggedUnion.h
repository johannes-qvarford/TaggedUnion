#ifndef TUT_TAGGEDUNION_H
#define TUT_TAGGEDUNION_H

#include "Union.h"

#include <assert.h>

namespace tut {
	
	template<typename... Args>
	struct TaggedUnion
	{
	private:
		Union<Args...> m_union;
		int m_tag;

		static Union<Args...> s_dummy;
		
		template<int I>
		auto get_() -> decltype(Get<I>::get(s_dummy)) {
#ifdef TUT_DEBUG
			if (m_tag == UNINITIALIZED || m_tag != I) {
				assert(0 && "tried to read from union member that wasn't last to be assigned");
			}
#endif
			return Get<I>::get(m_union);
		}

		template<int I, typename V>
		void set_(V&& v) {
			m_tag = I;
			Set<I>::set(m_union, std::forward<V>(v));
		}

	public:

		enum { UNINITIALIZED = -1 };

		enum class FailureMode {
			ASSERT,
			THROW,
		};

		class InvalidMemberReadException {
		};

		TaggedUnion() :
		m_tag(-1) {
		}

		template<int I, typename V>
		TaggedUnion(V&& v) : TaggedUnion() {
			TUT_UNION_ASSERT_BOUNDS(I, Args);
			set(std::forward<V>(v));
		}

		template<typename T, typename V>
		TaggedUnion(V&& v) : TaggedUnion() {
			TUT_UNION_ASSERT_TYPE_IN_UNION(T, Args);
			set_<impl::TypeToIndex<T, Args...>::value>(std::forward<V>(v));
		}

		template<int I, typename V>
		void set(V&& v) {
			TUT_UNION_ASSERT_BOUNDS(I, Args);
			set_<I>(std::forward<V>(v));
		}

		template<int I>
		auto get() -> decltype(this->get_<I>()) {
			TUT_UNION_ASSERT_BOUNDS(I, Args);
			return get_<I>();
		}

		template<typename T>
		auto getFirstOfType() -> T& {
			TUT_UNION_ASSERT_TYPE_IN_UNION(T, Args);
			return get_<impl::TypeToIndex<T, Args...>::value>();
		}

		template<typename T, typename V>
		void setFirstOfType(V&& v) {
			TUT_UNION_ASSERT_TYPE_IN_UNION(T, Args);
			set_<impl::TypeToIndex<T, Args...>::value>(std::forward<V>(v));
		}

		int getTag() {
			return m_tag;
		}
	};
}

#endif

