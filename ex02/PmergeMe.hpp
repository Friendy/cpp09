#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <string>
# include <iostream>
# include <sstream>
# include <vector>
# include <algorithm>
// # include "PmergeMe.hpp"

typedef std::pair<int, int> int_pair;
// typedef std::vector int_pair;

class PmergeMe {

private:
	std::vector<int> _v;

public:

	// template <typename T>
	// bool comPair(std::pair<T, T> p)
	// {
	// 	p.first > p.second;
	// }
	void print_vect(std::vector<int> &v);
	void sort();


	template <typename T>
	std::vector<std::pair<T, T> > getPairs(std::vector<T> &v, T &tail)
	{
		int stop_ind = v.size() - 2;
		std::vector<std::pair<T, T> > pair_vect; //vector of pairs

		if (v.size() % 2 == 1)
		{
			stop_ind--;
			tail = v[stop_ind + 2];
		}
		for (int i = 0; i <= stop_ind; i += 2)
		{
			std::pair<T, T> pair = std::make_pair(std::max(v[i], v[i + 1]), std::min(v[i], v[i + 1]));
			pair_vect.push_back(pair);
		}
		return (pair_vect);
	}

	template <typename T>
	void unpair(std::vector<std::pair<T, T> > &pair_v, std::vector<T> &chain, std::vector<T> &pend)
	{
		for (typename std::vector<std::pair<T, T> >::iterator it = pair_v.begin(); it != pair_v.end(); ++it)
		{
			chain.push_back((*it).first);
			pend.push_back((*it).second);
		}
	}

	template <typename T>
	int MISort(std::vector<T> &v)
	{
		T tail;
		std::vector<std::pair<T, T> > pair_v;
		std::vector<T> chain;
		std::vector<T> pend;

		if (v.size() <= 1)
			return(0);
		if (v.size() == 2)
		{
			std::sort(v.begin(), v.end());
			return(0);
		}
		else
		{
			pair_v = getPairs(v, tail);//returns a vector of sorted pairs
			// for(i = 0; i < pair_v.size(); i++)
			// {
			// 	if (pair_v[i].first < pair_v[i].second)
			// 	{
			// 		T tmp = pair_v[i].first;
			// 		pair_v[i].first = pair_v[i].second;
			// 		pair_v[i].second = tmp;
			// 	}
			// }
			// MISort(pair_v); //vector is sorted
			// unpair(pair_v, chain, pend);//we get chain and pend
			// //add first element from pend
			// insert(chain, pend); //pend is inserted
			//insert tail
		}
		return(0);
	}

	int operation(int operand1, int operand2, int token);

	PmergeMe(std::string arg);
	PmergeMe();
	PmergeMe(PmergeMe const &original);
	PmergeMe &operator=(PmergeMe const &original);
	~PmergeMe();
};

#endif
