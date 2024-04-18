#ifndef RPN_HPP
# define RPN_HPP
# include <string>
# include <iostream>
# include <stack>

class RPN {

private:
	std::stack<int> _stack;

public:
	int runStack(std::string arg);
	int operation(int operand1, int operand2, int token);

	RPN();
	RPN(RPN const &original);
	RPN &operator=(RPN const &original);
	~RPN();
};

#endif
