/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:51:27 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/23 12:51:24 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <sstream>
# include <algorithm>
# include <deque>
# include "VPair.hpp"
# include <sys/time.h>
# include <iomanip>

class PmergeMe {

private:
	std::vector<int> _v;
	std::deque<int> _d;
	std::vector<int> _J_seq;

public:
	//functions
	void sort();
	//for vector sort
	std::vector<VPair> getPairs(std::vector<int> &v, int &tail);
	std::vector<VPair> getPairs(std::vector<VPair> &v, VPair &tail);
	void unpair(std::vector<VPair> &v_of_pairs, std::vector<int> &chain, std::vector<int> &pend);
	void unpair(std::vector<VPair> &v_of_pairs, std::vector<VPair> &chain, std::vector<VPair> &pend);
	//for deque sort
	std::deque<VPair> getPairs(std::deque<int> &v, int &tail);
	std::deque<VPair> getPairs(std::deque<VPair> &v, VPair &tail);
	void unpair(std::deque<VPair> &v_of_pairs, std::deque<int> &chain, std::deque<int> &pend);
	void unpair(std::deque<VPair> &v_of_pairs, std::deque<VPair> &chain, std::deque<VPair> &pend);

	std::vector<int> JGen(int n);
	void checkNumber(long num, std::string substr);
	void timediff(struct timeval after, struct timeval before);

	//template functions
	//templates for vectors
	/*
	recursive insert-sort
	1. base cases
	2. break the vector into pairs
	3. sort those pairs recursively with this function
	4. unpair the pairs
	5. insert first element of the pend into the main chain
	6. insert tail
	 */
	//vectors
	template <typename T>
	std::vector<T> MISort(std::vector<T> &v)
	{
		T tail;
		std::vector<VPair> v_of_pairs;
		std::vector<T> chain;
		std::vector<T> pend;
		size_t size = v.size();

		if (size <= 1)
			return(v);
		if (size == 2)
		{
			std::sort(v.begin(), v.end());
			return(v);
		}
		else
		{
			v_of_pairs = getPairs(v, tail);
			v_of_pairs = MISort<VPair>(v_of_pairs);
			unpair(v_of_pairs, chain, pend);
			typename std::vector<T>::iterator it = chain.begin();
			chain.insert(it, pend[0]);
			insert_pend<T>(chain, pend);
			if (size % 2 == 1)
				binary_insert(chain, chain.size() - 1, tail);
			return(chain);
		}
	}

	/*
		inserts the pend into the chain using Jacobsthal sequence and binary insert
		offset - index up to which we need to search increases because of insertion
	 */
	template <typename T>
	void insert_pend(std::vector<T> &chain, std::vector<T> &pend)
	{
		int group_end = 1;
		int offset = 1;
		int j_ind = 3;
		int last_ind = pend.size() - 1;
		while (_J_seq[j_ind - 1] <= last_ind + 1)
		{
			for (int i = std::min(_J_seq[j_ind], last_ind); i >= group_end; i--)
			{
				binary_insert(chain, i + offset, pend[i]);
				offset++;
			}
			group_end = _J_seq[j_ind] + 1;
			j_ind++;
		}
	}

	template <typename T>
	int binary_insert(std::vector<T> &chain, int ind, T val)
	{
		typename std::vector<T>::iterator start = chain.begin();
		typename std::vector<T>::iterator end = chain.begin() + ind;
		typename std::vector<T>::iterator it;
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
		}
		chain.insert(end, val);
		return(0);
	}

	template <typename T>
	void print_vect(std::vector<T> &v)
	{
		for(size_t i = 0; i < v.size() - 1; i++)
			std::cout << v[i] << " ";
		std::cout << v[v.size() - 1] << std::endl;
	}

//deque templates
template <typename T>
	std::deque<T> MISort(std::deque<T> &v)
	{
		T tail;
		std::deque<VPair> v_of_pairs;
		std::deque<T> chain;
		std::deque<T> pend;
		size_t size = v.size();

		if (size <= 1)
			return(v);
		if (size == 2)
		{
			std::sort(v.begin(), v.end());
			return(v);
		}
		else
		{
			v_of_pairs = getPairs(v, tail);
			v_of_pairs = MISort<VPair>(v_of_pairs);
			unpair(v_of_pairs, chain, pend);
			typename std::deque<T>::iterator it = chain.begin();
			chain.insert(it, pend[0]);
			insert_pend<T>(chain, pend);
			if (size % 2 == 1)
				binary_insert(chain, chain.size() - 1, tail);
			return(chain);
		}
	}

	/*
		inserts the pend into the chain using Jacobsthal sequence and binary insert
		offset - index up to which we need to search increases because of insertion
	 */
	template <typename T>
	void insert_pend(std::deque<T> &chain, std::deque<T> &pend)
	{
		int group_end = 1;
		int offset = 1;
		int j_ind = 3;
		int last_ind = pend.size() - 1;
		while (_J_seq[j_ind - 1] <= last_ind + 1)
		{
			for (int i = std::min(_J_seq[j_ind], last_ind); i >= group_end; i--)
			{
				binary_insert(chain, i + offset, pend[i]);
				offset++;
			}
			group_end = _J_seq[j_ind] + 1;
			j_ind++;
		}
	}

	template <typename T>
	int binary_insert(std::deque<T> &chain, int ind, T val)
	{
		typename std::deque<T>::iterator start = chain.begin();
		typename std::deque<T>::iterator end = chain.begin() + ind;
		typename std::deque<T>::iterator it;
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
		}
		chain.insert(end, val);
		return(0);
	}

	template <typename T>
	void print_vect(std::deque<T> &v)
	{
		for(size_t i = 0; i < v.size() - 1; i++)
			std::cout << v[i] << " ";
		std::cout << v[v.size() - 1] << std::endl;
	}

	PmergeMe(int argc, char *argv[]);
	PmergeMe();
	PmergeMe(PmergeMe const &original);
	PmergeMe &operator=(PmergeMe const &original);
	~PmergeMe();
};

#endif
