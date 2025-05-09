/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:16:48 by ccolin            #+#    #+#             */
/*   Updated: 2025/04/08 14:14:13 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("1");
	ClapTrap b("2");

	a.attack("2");
	b.takeDamage(0); // simulate 1's attack

	b.attack("1");
	a.takeDamage(0); // simulate 2's attack

	a.beRepaired(5);
	b.beRepaired(3);

	for (int i = 0; i < 11; i++)
		a.attack("2");

	b.takeDamage(100); // kill 2
	b.attack("1"); // should fail
	b.beRepaired(10);  // should fail
	b.takeDamage(5);   // should print "is already dead"

	return 0;
}
