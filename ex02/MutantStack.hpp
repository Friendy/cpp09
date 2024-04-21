#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <iterator>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>{

typedef typename std::deque<T>::iterator deq_iterator;
typedef typename std::deque<T>::reverse_iterator deq_r_iterator;
typedef typename std::deque<T>::const_iterator deq_c_iterator;
typedef typename std::deque<T>::const_reverse_iterator deq_cr_iterator;

public:

	/*CONSTRUCTORS*/
	MutantStack<T>(){};

	//Assignment operator:
	MutantStack<T> &operator=(MutantStack const &original)
	{
		std::stack<T>::operator=(original);
		return(*this);
	}

	MutantStack<T>(MutantStack const &original)
	{
		*this = original;
	}

	/*Iterators*/
	class iterator : public deq_iterator
	{
		public:
			iterator() : deq_iterator(){}
			iterator &operator=(iterator const &original)
			{
				deq_iterator::operator=(original);
				return(*this);
			}
			iterator(iterator const &original): deq_iterator(original){}
			iterator(deq_iterator const& original) : deq_iterator(original){}
			~iterator(){}
	};

	class reverse_iterator : public deq_r_iterator
	{
		public:
			reverse_iterator() : deq_r_iterator(){}
			reverse_iterator &operator=(reverse_iterator const &original)
			{
				deq_r_iterator::operator=(original);
				return(*this);
			}
			reverse_iterator(reverse_iterator const &original): deq_r_iterator(original){}
			reverse_iterator(const deq_r_iterator& iter) : deq_r_iterator(iter){}
			~reverse_iterator(){}
	};

	class const_iterator : public deq_c_iterator
	{
		public:
			const_iterator() : deq_c_iterator(){}
			const_iterator &operator=(const_iterator const &original)
			{
				deq_c_iterator::operator=(original);
				return(*this);
			}
			const_iterator(const_iterator const &original): deq_c_iterator(original){}
			const_iterator(const deq_c_iterator& iter) : deq_c_iterator(iter){}
			~const_iterator(){}
	};

	class const_reverse_iterator : public deq_cr_iterator
	{
		public:
			const_reverse_iterator() : deq_cr_iterator(){}
			const_reverse_iterator &operator=(const_reverse_iterator const &original)
			{
				deq_cr_iterator::operator=(original);
				return(*this);
			}
			const_reverse_iterator(const_reverse_iterator const &original): deq_cr_iterator(original){}
			const_reverse_iterator(const deq_cr_iterator& iter) : deq_cr_iterator(iter){}
			~const_reverse_iterator(){}
	};

	MutantStack<T>::iterator begin(){return(this->c.begin());}
	MutantStack<T>::reverse_iterator rbegin(){return(this->c.rbegin());}
	MutantStack<T>::const_iterator cbegin(){return(this->c.cbegin());}
	MutantStack<T>::const_reverse_iterator crbegin(){return(this->c.crbegin());}

	MutantStack<T>::iterator end(){return(this->c.end());}
	MutantStack<T>::reverse_iterator rend(){return(this->c.rend());}
	MutantStack<T>::const_iterator cend(){return(this->c.cend());}
	MutantStack<T>::const_reverse_iterator crend(){return(this->c.crend());}

	/*DESTRUCTOR*/
	~MutantStack(){};
};

template <typename T>
void print_stack(MutantStack<T> &mstack)
{
	typename MutantStack<T>::iterator it = mstack.begin();
	typename MutantStack<T>::iterator ite = mstack.end();
	while (it != ite - 1)
	{
		std::cout << *it << ", ";
		++it;
	}
	std::cout << *mstack.crbegin() << std::endl;
}

#endif
