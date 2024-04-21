/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:52:03 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/21 22:54:22 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*CONSTRUCTORS*/
PmergeMe::PmergeMe(){}

static std::vector<int> JGen(int n)
{
	std::vector<int> v;
	int cur;

	v.push_back(0);
	v.push_back(1);
	for (int i = 2; i < n; i++)
	{
		cur = v[i - 1] + 2*v[i - 2];
		v.push_back(cur);
	}
	return (v);
}

PmergeMe::PmergeMe(std::string arg)
{
	int num;
	std::string substr;
	std::stringstream ss;
	size_t start = 0;
	size_t end = 0;
	while (end != std::string::npos)
	{
		end = arg.find(' ', start);
		substr = arg.substr(start, end - start);
		ss << substr;
		ss >> num;
		ss.clear();
		//check num later
		_v.push_back(num);
		start = end + 1;
	}
	_J_seq = JGen(17);
}
	// unpairs pairs after sorting
	void PmergeMe::unpair(std::vector<VPair> &v_of_pairs, std::vector<int> &chain, std::vector<int> &pend)
	{
		for (std::vector<VPair>::iterator it = v_of_pairs.begin(); it != v_of_pairs.end(); ++it)
		{
			chain.push_back((*it)[0]);
			pend.push_back((*it)[1]);
			// std::cout << (*it)[0] << ",unp " << (*it)[1]<< std::endl;
		}
	}

	void PmergeMe::unpair(std::vector<VPair> &v_of_pairs, std::vector<VPair> &chain, std::vector<VPair> &pend)
	{
		for (std::vector<VPair>::iterator it = v_of_pairs.begin(); it != v_of_pairs.end(); ++it)
		{
			std::cout << "unpair c "  << (*it) << std::endl;
			(*it).unpairFirst();
			chain.push_back((*it).unpairFirst());
			pend.push_back((*it).unpairSecond());
			// std::cout << (*it)[0] << "rtyryr " << (*it)[1]<< std::endl;
		}
		// pend[0].print();
	}
	// creates pair from 2 ints
	// vpair PmergeMe::createPair(int n1, int n2)
	// {
	// 	vpair pair;
	// 	pair.push_back(n1);
	// 	pair.push_back(n2);
	// 	return (pair);
	// }

	//merges 2 pairs
	// vpair PmergeMe::mergePairs(vpair p1, vpair p2)
	// {
	// 	for (size_t i = 0; i < p2.size() - 1; i++)
	// 		p1.push_back(p2[i]);
	// 	return (p1);
	// }

	std::vector<VPair> PmergeMe::getPairs(std::vector<int> &v, int &tail)
	{
		int stop_ind = v.size() - 2;
		std::vector<VPair> v_of_pairs; //vector of pairs

		if (v.size() % 2 == 1)
		{
			stop_ind--;
			tail = v[stop_ind + 2];
		}
		for (int i = 0; i <= stop_ind; i += 2)
		{
			VPair pair(std::max(v[i], v[i + 1]), std::min(v[i], v[i + 1]));
			v_of_pairs.push_back(pair);
		}
		return (v_of_pairs);
	}

	std::vector<VPair> PmergeMe::getPairs(std::vector<VPair> &v, VPair &tail)
	{
		int stop_ind = v.size() - 2;
		std::vector<VPair> v_of_pairs; //vector of pairs
		if (v.size() % 2 == 1)
		{
			stop_ind--;
			tail = v[stop_ind + 2];
		}
		for (int i = 0; i <= stop_ind; i += 2)
		{
			VPair max_pair = VPair::max(v[i], v[i + 1]);
			max_pair.merge(VPair::min(v[i], v[i + 1]));
			v_of_pairs.push_back(max_pair);
		}
		return (v_of_pairs);
	}

	// int PmergeMe::binary_insert(std::vector<ind> &chain, int ind, T val)
	// {
	// 	// int start = 0;
	// 	// int end = chain.size() - 1;
	// 	typename std::vector<T>::iterator start = chain.begin();
	// 	// std::advance(end, ind);
	// 	typename std::vector<T>::iterator end = chain.begin() + ind;
	// 	typename std::vector<T>::iterator it;
	// 	// std::cout << *start << std::endl;
	// 	// std::cout << *end << std::endl;
	// 	if (val <= *start)
	// 	{
	// 		chain.insert(start, val);
	// 		return(0);
	// 	}
	// 	if (val >= *end)
	// 	{
	// 		chain.push_back(val);
	// 		return(0);
	// 	}
	// 	while(start != end && end != start + 1)
	// 	{
	// 		it = start;
	// 		std::advance(it, (end - start)/2);
	// 		if (val == *it)
	// 			break;
	// 		else if (val < *it)
	// 			end = it;
	// 		else
	// 			start = it;
	// 		// std::cout << "loop" << std::endl;
	// 	}
	// 	chain.insert(end, val);
	// 	return(0);
	// }

	// std::vector<vpair> PmergeMe::getPairs(std::vector<vpair> &v, vpair &tail)
	// {
	// 	int stop_ind = v.size() - 2;
	// 	std::vector<vpair> v_of_pairs; //vector of pairs

	// 	if (v.size() % 2 == 1)
	// 	{
	// 		stop_ind--;
	// 		tail = v[stop_ind + 2];
	// 	}
	// 	for (int i = 0; i <= stop_ind; i += 2)
	// 	{
	// 		vpair pair = mergePairs(std::max(v[i], v[i + 1]), std::min(v[i], v[i + 1]));
	// 		v_of_pairs.push_back(pair);
	// 	}
	// 	return (v_of_pairs);
	// }

//Assignment operator:
PmergeMe &PmergeMe::operator=(PmergeMe const &)
{
	// if (this != &original)
	return(*this);
}

PmergeMe::PmergeMe(PmergeMe const &original)
{
	*this = original;
}

/*FUNCTIONS*/
// void PmergeMe::print_vect(std::vector<int> &v)
// {
// 	for(size_t i = 0; i < v.size() - 1; i++)
// 		std::cout << v[i]<< ", ";
// 	std::cout << v[v.size() - 1] << std::endl;
// }

void PmergeMe::sort()
{
	// int tail = 0;
	std::vector<int> chain;
	// // std::vector<int> pend;
	// std::vector<VPair> v_of_pairs;
	// v_of_pairs = getPairs(_v, tail);
	// unpair<int>(v_of_pairs, chain, pend);
	// print_vect(_v);
	// // print_vect(chain);
	// print_vect(pend);
	// //testing insrtion
	// std::sort(chain.begin(), chain.end());
	// print_vect(chain);
	// std::vector<int>::iterator it = chain.begin();
	// chain.insert(it, pend[0]);
	// // it += 5;
	// print_vect(chain);
	// binary_insert<int>(chain, 3, 2);
	// print_vect(chain);
	// binary_insert<int>(chain, 3, 0);
	// print_vect(chain);
	// binary_insert<int>(chain, 7, 5);
	// print_vect(chain);
	// binary_insert<int>(chain, 7, 6);
	// insert_pend(chain, pend);
	// print_vect(chain);
	// bool t = std::binary_insert(chain.begin(), chain.end(), 7);
	print_vect(_v);
	chain = MISort<int>(_v);
	print_vect(chain);
	
	// std::vector<int>::iterator start = chain.begin();
	// std::vector<int>::iterator end = chain.end() - 1;
	// std::advance(it, (end - start)/2);
	// std::cout << *it << std::endl;
	// std::cout << v_of_pairs[3].first << std::endl;
	// std::cout << v_of_pairs.size() << std::endl;
}


/*DESTRUCTOR*/
PmergeMe::~PmergeMe(){}
