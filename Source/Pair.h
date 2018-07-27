#pragma once

template <class T1, class T2>
struct Pair {
	Pair() = default;
	Pair(T1 const & fst, T2 const & snd);
	
	T1 fst;
	T2 snd;
};

template <class T1, class T2>
Pair<T1, T2>::Pair(T1 const & fst, T2 const & snd) 
	: fst(fst)
	, snd(snd)
{}

template <class T1, class T2>
bool operator < (Pair<T1, T2> const & left, Pair<T1, T2> const & right) noexcept {
	if (left.fst != right.fst)
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
