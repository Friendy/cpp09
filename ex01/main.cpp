#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cerr << "Error";
		return(-1);
	}
	RPN rpn;
	std::cout << rpn.runStack(argv[1]) << std::endl;
	return (0);
}


