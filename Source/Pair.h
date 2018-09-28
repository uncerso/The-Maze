#pragma once
#include <string>

template <class T1, class T2>
struct Pair {
	Pair() = default;

	template <class U1, class U2>
	constexpr Pair(U1 && fst, U2 && snd);

	constexpr Pair(Pair && other) = default;
	constexpr Pair(Pair const & other) = default;

	constexpr Pair & operator = (Pair && other) = default;
	constexpr Pair & operator = (Pair const & other) = default;

	T1 fst;
	T2 snd;
};

template<class T1, class T2>
template<class U1, class U2>
inline constexpr Pair<T1, T2>::Pair(U1 && fst, U2 && snd)
	: fst(std::forward<U1>(fst))
	, snd(std::forward<U2>(snd))
{}

template <class T1, class T2>
constexpr bool operator < (Pair<T1, T2> const & left, Pair<T1, T2> const & right) noexcept {
	if (left.fst == right.fst)
		return left.snd < right.snd;
	return left.fst < right.fst;
}

template <class T2>
bool operator < (Pair<std::string, T2> const & left, Pair<std::string, T2> const & right) noexcept {
	auto cmp = left.fst.compare(right.fst);
	if (cmp == 0)
		return left.snd < right.snd;
	return cmp < 0;
}
