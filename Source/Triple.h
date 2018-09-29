#pragma once

template <class T1, class T2, class T3>
struct Triple {
	Triple() = default;
	constexpr Triple(T1 const & fst, T2 const & snd, T3 const & trd);

	constexpr Triple(Triple && other) = default;
	constexpr Triple(Triple const & other) = default;

	constexpr Triple & operator = (Triple && other) = default;
	constexpr Triple & operator = (Triple const & other) = default;

	T1 fst;
	T2 snd;
	T3 trd;
};

template <class T1, class T2, class T3>
constexpr Triple<T1, T2, T3>::Triple(T1 const & fst, T2 const & snd, T3 const & trd)
	: fst(fst)
	, snd(snd)
	, trd(trd)
{}

template <class T1, class T2, class T3>
constexpr bool operator < (Triple<T1, T2, T3> const & left, Triple<T1, T2, T3> const & right) noexcept {
	if (left.fst == right.fst) {
		if (left.snd == right.snd)
			return left.trd < right.trd;
		return left.snd < right.snd;
	}
	return left.fst < right.fst;
}
