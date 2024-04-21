/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:52:03 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/21 18:30:27 by mrubina          ###   ########.fr       */
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
	// void unpair(std::vector<std::pair<T, T> > &pair_v, std::vector<T> &chain, std::vector<T> &pend)
	// {
	// 	for (typename std::vector<std::pair<T, T> >::iterator it = pair_v.begin(); it != pair_v.end(); ++it)
	// 	{
	// 		chain.push_back((*it).first);
	// 		pend.push_back((*it).second);
	// 	}
	// }
	//creates pair from 2 ints
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

	std::vector<vpair> PmergeMe::getPairs(std::vector<int> &v, int &tail)
	{
		int stop_ind = v.size() - 2;
		std::vector<vpair> pair_vect; //vector of pairs

		if (v.size() % 2 == 1)
		{
			stop_ind--;
			tail = v[stop_ind + 2];
		}
		for (int i = 0; i <= stop_ind; i += 2)
		{
			vpair pair(std::max(v[i], v[i + 1]), std::min(v[i], v[i + 1]));
			pair_vect.push_back(pair);
		}
		return (pair_vect);
	}

	// std::vector<vpair> PmergeMe::getPairs(std::vector<vpair> &v, vpair &tail)
	// {
	// 	int stop_ind = v.size() - 2;
	// 	std::vector<vpair> pair_vect; //vector of pairs

	// 	if (v.size() % 2 == 1)
	// 	{
	// 		stop_ind--;
	// 		tail = v[stop_ind + 2];
	// 	}
	// 	for (int i = 0; i <= stop_ind; i += 2)
	// 	{
	// 		vpair pair = mergePairs(std::max(v[i], v[i + 1]), std::min(v[i], v[i + 1]));
	// 		pair_vect.push_back(pair);
	// 	}
	// 	return (pair_vect);
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
void PmergeMe::print_vect(std::vector<int> &v)
{
	for(size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i]<< ", ";
	std::cout << v[v.size() - 1] << std::endl;
}

void PmergeMe::sort()
{
	// int tail = 0;
	std::vector<int> chain;
	// std::vector<int> pend;
	// std::vector<std::pair<int, int> > v_p;
	// v_p = getPairs(_v, tail);
	// unpair<int>(v_p, chain, pend);
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
	// chain = MISort<int>(_v);
	print_vect(chain);
	
	// std::vector<int>::iterator start = chain.begin();
	// std::vector<int>::iterator end = chain.end() - 1;
	// std::advance(it, (end - start)/2);
	// std::cout << *it << std::endl;
	// std::cout << v_p[3].first << std::endl;
	// std::cout << v_p.size() << std::endl;
}

int PmergeMe::operation(int operand1, int operand2, int token)
{
	switch(token)
	{
		case ('+') :
			return( operand1 + operand2);
		case ('-') :
			return( operand1 - operand2);
		case ('*') :
			return( operand1 * operand2);
		case ('/') :
			return( operand1 / operand2);
	}
	return(0);
}

// int PmergeMe::runStack(std::string arg)
// {
// 	int operand1;
// 	int	operand2;

// 	for (std::string::iterator it = arg.begin(); it != arg.end(); ++it)
// 	{
// 		if (*it != ' ')
// 		{
// 			if (!isoperator(*it))
// 				_stack.push(*it - '0');
// 			else
// 			{
// 				operand2 = _stack.top();
// 				_stack.pop();
// 				operand1 = _stack.top();
// 				_stack.pop();
// 				operand1 = this->operation(operand1, operand2, *it);
// 				if (it != arg.end())
// 					_stack.push(operand1);
// 			}
// 		}
// 	}
// 	return(operand1);
// }

/*DESTRUCTOR*/
PmergeMe::~PmergeMe(){}
