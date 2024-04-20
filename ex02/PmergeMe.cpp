#include "PmergeMe.hpp"

/*CONSTRUCTORS*/
PmergeMe::PmergeMe(){}
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
}

//Assignment operator:
PmergeMe &PmergeMe::operator=(PmergeMe const &original)
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
	for(int i = 0; i < v.size() - 1; i++)
		std::cout << v[i]<< ", ";
	std::cout << v[v.size() - 1] << std::endl;
}

void PmergeMe::sort()
{
	int tail = 0;
	std::vector<int> chain;
	std::vector<int> pend;
	std::vector<std::pair<int, int> > v_p;
	v_p = getPairs(_v, tail);
	unpair<int>(v_p, chain, pend);
	print_vect(_v);
	print_vect(chain);
	print_vect(pend);
	// MISort(_v);
	std::cout << v_p[0].first << std::endl;
	std::cout << v_p[3].first << std::endl;
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
