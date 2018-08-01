#pragma once

template <class T1, class T2>
struct Pair {
	Pair() = default;

	template <class U1, class U2>
	Pair(U1 && fst, U2 && snd);

	Pair(Pair && other) = default;
	Pair(Pair const & other) = default;

	Pair & operator = (Pair && other) = default;
	Pair & operator = (Pair const & other) = default;

	T1 fst;
	T2 snd;
};

template<class T1, class T2>
template<class U1, class U2>
inline Pair<T1, T2>::Pair(U1 && fst, U2 && snd)
	: fst(std::forward<U1>(fst))
	, snd(std::forward<U2>(snd))
{}

template <class T1, class T2>
bool operator < (Pair<T1, T2> const & left, Pair<T1, T2> const & right) noexcept {
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
