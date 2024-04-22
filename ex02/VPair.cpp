/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VPair.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:04:03 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/22 09:07:29 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "VPair.hpp"

	/*CONSTRUCTORS*/
	VPair::VPair(){};
	VPair::VPair(int n1, int n2)
	{
		_v.push_back(n1);
		_v.push_back(n2);
	}

	//Assignment operator:
	VPair &VPair::operator=(VPair const &original)
	{
		if (this != &original)
		{
			this->_v = original._v;
		}
		return(*this);
	}

//Copy constructor:
	VPair::VPair(VPair const &original)
	{
		*this = original;
	}

	/*FUNCTIONS*/
	void VPair::merge(VPair p)
	{
		// std::cout << p.size() << std::endl;
		for (size_t i = 0; i <= p.size() - 1; i++)
			_v.push_back(p[i]);
	}

	VPair VPair::max(VPair &p1, VPair &p2)
	{
		if (p1[0] > p2[0])
			return (p1);
		else
			return (p2);
	}

	VPair VPair::min(VPair &p1, VPair &p2) // test std compat!!!
	{
		if (p1[0] < p2[0])
			return (p1);
		else
			return (p2);
	}

	VPair VPair::unpairFirst()
	{
		VPair first;
		// std::cout << this->size()/2 - 1 << std::endl;
		for (int i = 0; i <= this->size()/2 - 1; i++)
			first.push(this->_v[i]);
		// std::cout << "printing first" << std::endl;
		// this->print();
		// first.print();
		return(first);
	}

	VPair VPair::unpairSecond()
	{
		VPair second;
		for (int i = this->size()/2; i <= this->size() - 1; i++)
			second.push(this->_v[i]);
		return(second);
	}

	int &VPair::operator[](u_int const &i)
	{
		if (i > _v.size() - 1)
			throw std::exception();
		return (_v[i]);
	}

	bool VPair::operator==(const VPair& p) const
	{
		return (_v[0] == p._v[0]);
	}

	bool VPair::operator>=(const VPair& p) const
	{
		return (_v[0] >= p._v[0]);
	}

	bool VPair::operator<=(const VPair& p) const
	{
		return (_v[0] <= p._v[0]);
	}

	bool VPair::operator>(const VPair& p) const
	{
		return (_v[0] > p._v[0]);
	}

	bool VPair::operator<(const VPair& p) const
	{
		return (_v[0] < p._v[0]);
	}

	size_t VPair::size()
	{
		return(_v.size());
	}

	void VPair::push(int n)
	{
		_v.push_back(n);
	}
	
	void VPair::print() const
	{
		if (_v.size() != 0)
		{
			for (size_t i = 0; i < _v.size() - 1; i++)
				std::cout << _v[i] << ", ";
			std::cout << _v[_v.size() - 1] << std::endl;
		}
		else
		std::cout << "empty" << std::endl;
	}

	VPair::~VPair(){}
std::ostream & operator << (std::ostream &os, const VPair &p)
{
	p.print();
	return(os);
}