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