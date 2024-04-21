// #include "RPN.hpp"
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include "PmergeMe.hpp"

// template <T>
typedef std::pair<int, int> pair1;
typedef std::pair<pair1, pair1> pair2;

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cerr << "Error";
		return(-1);
	}
// VPair p(1, 4);
// VPair p1(10, 40);
// VPair p3(154, 89);
// p.merge(p1);
// p.merge(p3);
// // p[0];
// std::cout << (p1 < p3) << std::endl;
// p.print();

// PmergeMe pm("1 3 5 9 7 2 6 8 4 0");
// PmergeMe pm("6 3 10 2");
// PmergeMe pm("34 54 97 65 43 75 90 62 75 42 83"); duplicates problem
// PmergeMe pm("34 54 97 65 43 75 90 62 75 42 83 25 13 49 92 12 5");
PmergeMe pm(argv[1]);
pm.sort();
// pm.print_vect();
// std::pair<int, int>p1(2, 234);
// std::pair<int, int>p2(34, 98);
// std::pair<int, int>p3(344, 45);
// std::pair<int, int>p4(23, 67);
// pair2 p5 = std::make_pair(p3, p1);
// pair2 p6 = std::make_pair(p2, p4);
// std::vector<pair2> v;
// v.push_back(p5);
// v.push_back(p6);
// std::cout << (*(v.cbegin())).first.first << std::endl;
// std::sort(v.begin(), v.end());
// std::cout << argv[0] << std::endl;
	
return (0);
}


