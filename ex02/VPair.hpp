/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VPair.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubina <mrubina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:04:03 by mrubina           #+#    #+#             */
/*   Updated: 2024/04/21 19:18:30 by mrubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIRV_HPP
# define PAIRV_HPP
# include <string>
# include <iostream>
# include <sstream>
# include <vector>
# include <array>
# include <algorithm>

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
	static VPair max(VPair p1, VPair p2);
	static VPair min(VPair p1, VPair p2);
	void print();
	void merge(VPair p);
	size_t size();

	/*OPERATORS*/
	int &operator[](u_int const &i);
	bool operator==(const VPair& p) const;
	bool operator>=(const VPair& p) const;
	bool operator<=(const VPair& p) const;
	bool operator>(const VPair& p) const;
	bool operator<(const VPair& p) const;

	~VPair();

};
#endif
