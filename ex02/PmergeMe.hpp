#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <string>
# include <iostream>
# include <sstream>
# include <vector>
# include <array>
# include <algorithm>
# include "VPair.hpp"
// # include "PmergeMe.hpp"

// typedef std::pair<int, int> int_pair;
typedef std::vector<int> vpair;
// typedef std::vector int_pair;

class PmergeMe {

private:
	std::vector<int> _v;
	std::vector<int> _J_seq;

public:

	// template <typename T>
	// bool comPair(std::pair<T, T> p)
	// {
	// 	p.first > p.second;
	// }
	void print_vect(std::vector<int> &v);
	void sort();

	// vpair mergePairs(vpair p1, vpair p2);
	std::vector<vpair> getPairs(std::vector<int> &v, int &tail);



	template <typename T>
	int binary_insert(std::vector<T> &chain, int ind, T val)
	{
		// int start = 0;
		// int end = chain.size() - 1;
		typename std::vector<T>::iterator start = chain.begin();
		// std::advance(end, ind);
		typename std::vector<T>::iterator end = chain.begin() + ind;
		typename std::vector<T>::iterator it;
		// std::cout << *start << std::endl;
		// std::cout << *end << std::endl;
		if (val <= *start)
		{
			chain.insert(start, val);
			return(0);
		}
		if (val >= *end)
		{
			chain.push_back(val);
			return(0);
		}
		while(start != end && end != start + 1)
		{
			it = start;
			std::advance(it, (end - start)/2);
			if (val == *it)
				break;
			else if (val < *it)
				end = it;
			else
				start = it;
			// std::cout << "loop" << std::endl;
		}
		chain.insert(end, val);
		return(0);
	}

	//offset - index up to which we need to search increases because of insertion
	template <typename T>
	void insert_pend(std::vector<T> &chain, std::vector<T> &pend)
	{
		int group_end = 2;
		int offset = 0;
		int j_ind = 3;
		int last_ind = pend.size() - 1;
		while (_J_seq[j_ind - 1] <= last_ind + 1) //each loop for each group
		{
			// std::cout << _J_seq[j_ind] << ", " << last_ind << std::endl;
			for (int i = std::min(_J_seq[j_ind], last_ind); i >= group_end; i--)
			{
				// std::cout << i << " i, " << pend[i] << std::endl;
				binary_insert(chain, i + offset, pend[i]);
				offset++;
			}
			group_end = _J_seq[j_ind] + 1;
			j_ind++;
		}
	}

	// template <typename T>
	// std::vector<T> MISort(std::vector<T> &v)

	// template <typename T>
	// std::vector<T> MISort(std::vector<T> &v)
	// {
	// 	T tail;
	// 	std::vector<std::pair<T, T> > pair_v;
	// 	std::vector<T> chain;
	// 	std::vector<T> pend;

	// 	if (v.size() <= 1)
	// 		return(v);
	// 	if (v.size() == 2)
	// 	{
	// 		std::sort(v.begin(), v.end());
	// 		return(v);
	// 	}
	// 	else
	// 	{
	// 		pair_v = getPairs(v, tail);//returns a vector of sorted pairs
	// 		// std::cout << tail << std::endl;
	// 		// std::cout << pair_v.size() << std::endl;
	// 		// exit(0);
	// 		pair_v = MISort<std::pair<T, T> >(pair_v); //vector is sorted
	// 		unpair(pair_v, chain, pend);//we get chain and pend
	// 		typename std::vector<T>::iterator it = chain.begin();
	// 		chain.insert(it, pend[0]);
	// 		insert_pend<T>(chain, pend); //pend is inserted
	// 		if (v.size() % 2 == 1)
	// 			binary_insert(chain, chain.size() - 1, tail);
	// 		return(chain);
	// 		//insert tail
	// 	}
	// }
	// std::vector<int> MISort(std::vector<int> &v)
	// {
	// 	int tail;
	// 	std::vector<std::pair<T, T> > pair_v;
	// 	std::vector<T> chain;
	// 	std::vector<T> pend;

	// 	if (v.size() <= 1)
	// 		return(v);
	// 	if (v.size() == 2)
	// 	{
	// 		std::sort(v.begin(), v.end());
	// 		return(v);
	// 	}
	// 	else
	// 	{
	// 		pair_v = getPairs(v, tail);//returns a vector of sorted pairs
	// 		// std::cout << tail << std::endl;
	// 		// std::cout << pair_v.size() << std::endl;
	// 		// exit(0);
	// 		pair_v = MISort<std::pair<T, T> >(pair_v); //vector is sorted
	// 		unpair(pair_v, chain, pend);//we get chain and pend
	// 		typename std::vector<T>::iterator it = chain.begin();
	// 		chain.insert(it, pend[0]);
	// 		insert_pend<T>(chain, pend); //pend is inserted
	// 		if (v.size() % 2 == 1)
	// 			binary_insert(chain, chain.size() - 1, tail);
	// 		return(chain);
	// 		//insert tail
	// 	}
	// }

	//insertion using Jacobthal order
	// template <typename T>
	// void insert(std::vector<T> &chain, std::vector<T> &chain)
	// {

	// }

	int operation(int operand1, int operand2, int token);

	PmergeMe(std::string arg);
	PmergeMe();
	PmergeMe(PmergeMe const &original);
	PmergeMe &operator=(PmergeMe const &original);
	~PmergeMe();
};

#endif
