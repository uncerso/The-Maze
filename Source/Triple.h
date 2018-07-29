#pragma once

template <class T1, class T2, class T3>
struct Triple {
	Triple() = default;
	Triple(T1 const & fst, T2 const & snd, T3 const & trd);

	T1 fst;
	T2 snd;
	T3 trd;
};

template <class T1, class T2, class T3>
Triple<T1, T2, T3>::Triple(T1 const & fst, T2 const & snd, T3 const & trd)
	: fst(fst)
	, snd(snd)
	, trd(trd)
{}

template <class T1, class T2, class T3>
bool operator < (Triple<T1, T2, T3> const & left, Triple<T1, T2, T3> const & right) noexcept {
	if (left.fst == right.fst) {
		if (left.snd == right.snd)
			return left.trd < right.trd;
		return left.snd < right.snd;
	}
	return left.fst < right.fst;
}
