/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VPair.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:04:03 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/22 10:59:00 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIRV_HPP
# define PAIRV_HPP
# include <string>
# include <iostream>
# include <vector>

class VPair{

private:
	std::vector<int> _v;

public:
	/*CONSTRUCTORS*/
	VPair();
	VPair(int n1, int n2);

	//Assignment operator:
	VPair&operator=(VPair const &original);

	//Copy constructor:
	VPair(VPair const &original);

	/*FUNCTIONS*/
	void print() const;
	void merge(VPair p);
	size_t size();
	VPair unpairFirst();
	VPair unpairSecond();
	void push(int n);

	/*OPERATORS*/
	int &operator[](u_int const &i);
	bool operator==(const VPair& p) const;
	bool operator>=(const VPair& p) const;
	bool operator<=(const VPair& p) const;
	bool operator>(const VPair& p) const;
	bool operator<(const VPair& p) const;

	~VPair();
};

std::ostream & operator << (std::ostream &os, const VPair &p);
#endif
