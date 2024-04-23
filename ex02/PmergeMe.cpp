/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:52:03 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/23 13:57:51 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*CONSTRUCTORS*/
PmergeMe::PmergeMe(){}

//loads number sequence
PmergeMe::PmergeMe(int argc, char *argv[])
{
	long num;
	std::stringstream ss;
	int i = 1;
	while (i < argc)
	{
		if (*argv[i] == '\0')
		{
			std::cerr << "Error\n";
			exit(-1);
		}
		ss << argv[i];
		ss >> num;
		ss.clear();
		std::string str(argv[i]);
		checkNumber(num, str);
		_v.push_back(static_cast<int>(num));
		_d.push_back(static_cast<int>(num));
		i++;
	}
	_J_seq = JGen(20);
}

//Assignment operator:
PmergeMe &PmergeMe::operator=(PmergeMe const &original)
{
	if (this != &original)
	{
		_v = original._v;
		_J_seq = original._J_seq;
		_d = original._d;
	}
	return(*this);
}

PmergeMe::PmergeMe(PmergeMe const &original)
{
	*this = original;
}

/*FUNCTIONS*/
void PmergeMe::timediff(struct timeval after, struct timeval before)
{
	time_t s_diff = after.tv_sec - before.tv_sec;
	suseconds_t us_diff = s_diff * 1000000 + after.tv_usec - before.tv_usec;
	double total_diff = static_cast<double>(us_diff) / 1000000;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << total_diff << " us\n";
}

void PmergeMe::sort()
{
	struct timeval before;
	struct timeval after;
	std::vector<int> v;
	std::deque<int> d;
	gettimeofday(&before, NULL);
	v = MISort<int>(_v);
	gettimeofday(&after, NULL);
	std::cout << "Before: ";
	print_vect(_v);
	std::cout << "After: ";
	print_vect(v);
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector: ";
	timediff(after, before);
	gettimeofday(&before, NULL);
	d = MISort<int>(_d);
	gettimeofday(&after, NULL);
	// std::cout << "Before: ";
	// print_vect(_d);
	// std::cout << "After: ";
	// print_vect(d);
	std::cout << "Time to process a range of " << d.size() << " elements with std::deque: ";
	timediff(after, before);
}

//generates Jacobthal's sequence
std::vector<int> PmergeMe::JGen(int n)
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

static bool is_digit(int c)
{
	if (c >= 48 && c <= 57)
		return(true);
	return (false);
}

void PmergeMe::checkNumber(long num, std::string substr)
{
	std::string::iterator it;
	it = std::find_if_not(substr.begin(), substr.end(), is_digit);
	if (num < 0 || num > INT_MAX || it != substr.end())
	{
		std::cerr << "Error\n";
		exit(-1);
	}
}

//vector related functions
//unpairs pairs of its
void PmergeMe::unpair(std::vector<VPair> &v_of_pairs, std::vector<int> &chain, std::vector<int> &pend)
{
	for (std::vector<VPair>::iterator it = v_of_pairs.begin(); it != v_of_pairs.end(); ++it)
	{
		chain.push_back((*it)[0]);
		pend.push_back((*it)[1]);
	}
}

//unpairs pairs of VPairs
void PmergeMe::unpair(std::vector<VPair> &v_of_pairs, std::vector<VPair> &chain, std::vector<VPair> &pend)
{
	for (std::vector<VPair>::iterator it = v_of_pairs.begin(); it != v_of_pairs.end(); ++it)
	{
		chain.push_back((*it).unpairFirst());
		pend.push_back((*it).unpairSecond());
	}
}

//breaks vector of ints into pairs
std::vector<VPair> PmergeMe::getPairs(std::vector<int> &v, int &tail)
{
	int stop_ind = v.size() - 2;
	std::vector<VPair> v_of_pairs;

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

//breaks vector of VPairs into pairs
std::vector<VPair> PmergeMe::getPairs(std::vector<VPair> &v, VPair &tail)
{
	int stop_ind = v.size() - 2;
	std::vector<VPair> v_of_pairs;

	if (v.size() % 2 == 1)
	{
		stop_ind--;
		tail = v[stop_ind + 2];
	}
	for (int i = 0; i <= stop_ind; i += 2)
	{
		VPair max_pair = std::max(v[i], v[i + 1]);
		max_pair.merge(std::min(v[i], v[i + 1]));
		v_of_pairs.push_back(max_pair);
	}
	return (v_of_pairs);
}

//deque related functions
//unpairs pairs of its
void PmergeMe::unpair(std::deque<VPair> &v_of_pairs, std::deque<int> &chain, std::deque<int> &pend)
{
	for (std::deque<VPair>::iterator it = v_of_pairs.begin(); it != v_of_pairs.end(); ++it)
	{
		chain.push_back((*it)[0]);
		pend.push_back((*it)[1]);
	}
}

//unpairs pairs of VPairs
void PmergeMe::unpair(std::deque<VPair> &v_of_pairs, std::deque<VPair> &chain, std::deque<VPair> &pend)
{
	for (std::deque<VPair>::iterator it = v_of_pairs.begin(); it != v_of_pairs.end(); ++it)
	{
		chain.push_back((*it).unpairFirst());
		pend.push_back((*it).unpairSecond());
	}
}

//breaks deque of ints into pairs
std::deque<VPair> PmergeMe::getPairs(std::deque<int> &v, int &tail)
{
	int stop_ind = v.size() - 2;
	std::deque<VPair> v_of_pairs;

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

//breaks deque of VPairs into pairs
std::deque<VPair> PmergeMe::getPairs(std::deque<VPair> &v, VPair &tail)
{
	int stop_ind = v.size() - 2;
	std::deque<VPair> v_of_pairs;

	if (v.size() % 2 == 1)
	{
		stop_ind--;
		tail = v[stop_ind + 2];
	}
	for (int i = 0; i <= stop_ind; i += 2)
	{
		VPair max_pair = std::max(v[i], v[i + 1]);
		max_pair.merge(std::min(v[i], v[i + 1]));
		v_of_pairs.push_back(max_pair);
	}
	return (v_of_pairs);
}

/*DESTRUCTOR*/
PmergeMe::~PmergeMe(){}
