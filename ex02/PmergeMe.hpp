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
	template <typename T>
	void print_vect(std::vector<T> &v)
	{
		for(size_t i = 0; i < v.size() - 1; i++)
			std::cout << v[i] << " ";
		std::cout << v[v.size() - 1] << std::endl;
	}

	void sort();

	// vpair mergePairs(vpair p1, vpair p2);
	std::vector<VPair> getPairs(std::vector<int> &v, int &tail);
	std::vector<VPair> getPairs(std::vector<VPair> &v, VPair &tail);
	void unpair(std::vector<VPair> &v_of_pairs, std::vector<int> &chain, std::vector<int> &pend);
	void unpair(std::vector<VPair> &v_of_pairs, std::vector<VPair> &chain, std::vector<VPair> &pend);


	template <typename T>
	int binary_insert(std::vector<T> &chain, int ind, T val)
	{
		// int start = 0;
		// int end = chain.size() - 1;
		typename std::vector<T>::iterator start = chain.begin();
		// std::advance(end, ind);
		typename std::vector<T>::iterator end = chain.begin() + ind;
		typename std::vector<T>::iterator it;
		// std::cout << "start " << *start << std::endl;
		// std::cout << "end " << *end << std::endl;
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
		while (start != end && end != start + 1)
		{
			it = start;
			// std::cout << "start " << *start << std::endl;
			// std::cout << "end " << *end << std::endl;
			std::advance(it, (end - start)/2);
			if (val == *it)
			{
				end = it;
				break;
			}
			else if (val < *it)
				end = it;
			else
				start = it;
			// std::cout << "loop" << std::endl;
		}
		// std::cout << *start << std::endl;
		// std::cout << *end << std::endl;
		// 	std::cout << *it << std::endl;
		chain.insert(end, val);
		return(0);
	}

	//offset - index up to which we need to search increases because of insertion
	template <typename T>
	void insert_pend(std::vector<T> &chain, std::vector<T> &pend)
	{
		int group_end = 1;
		int offset = 1;
		int j_ind = 3;
		int last_ind = pend.size() - 1;
		// print_vect(chain);
		// print_vect(pend);
		// std::cout << " chain " << std::endl;
		while (_J_seq[j_ind - 1] <= last_ind + 1) //each loop for each group
		{
			// std::cout << std::min(_J_seq[j_ind], last_ind) << ", jhjh" << last_ind << std::endl;
			for (int i = std::min(_J_seq[j_ind], last_ind); i >= group_end; i--)
			{
				// std::cout << i << " i, " << i + offset << " +off " << pend[i] << std::endl;
				binary_insert(chain, i + offset, pend[i]);
				offset++;
			}
			group_end = _J_seq[j_ind] + 1;
			j_ind++;
		}
	}

	// template <typename T>
	// std::vector<T> MISort(std::vector<T> &v)

	template <typename T>
	std::vector<T> MISort(std::vector<T> &v)
	{
		T tail;
		std::vector<VPair> v_of_pairs;
		std::vector<T> chain;
		std::vector<T> pend;

		if (v.size() <= 1)
			return(v);
		if (v.size() == 2)
		{

			std::sort(v.begin(), v.end());
			// std::cout << "yrtyr" << std::endl;
			return(v);
		}
		else
		{
			v_of_pairs = getPairs(v, tail);//returns a vector of sorted pairs
			// std::cout << tail << std::endl;
			// std::cout << "v size" << v_of_pairs.size() << std::endl;
			// exit(0);
			v_of_pairs = MISort<VPair>(v_of_pairs); //vector is sorted
			// std::cout << "pri" << std::endl;
			// print_vect(v_of_pairs);
			// v_of_pairs[1].print();
			// std::cout << "pend0" << std::endl;
			unpair(v_of_pairs, chain, pend);//we get chain and pend
			// std::cout << "after unpair" << std::endl;
			typename std::vector<T>::iterator it = chain.begin();
			// print_vect(v_of_pairs);
			chain.insert(it, pend[0]);
			// print_vect(chain);
			// print_vect(pend);
			insert_pend<T>(chain, pend); //pend is inserted
			// std::cout << "chain before tail insertion:" << std::endl;
			// print_vect(chain);
			// std::cout << "chain size: " << chain.size() << std::endl;
			if (v.size() % 2 == 1)
			{
				// std::cout << "starting insert for tail " << std::endl;
				binary_insert(chain, chain.size() - 1, tail);
				// std::cout << "tail " << tail << std::endl;
				// std::cout << "chain after tail insertion:" << std::endl;
				// print_vect(chain);
			}

			// std::cout << "chain before tail insertion" << v.size() << "tail " << tail << std::endl;
			// print_vect(chain);
			return(chain);
			//insert tail
		}
	}

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
