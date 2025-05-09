/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:16:46 by ccolin            #+#    #+#             */
/*   Updated: 2025/04/08 14:01:55 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Unknown ClapTrap's default constructor called" << std::endl;
    name = "Unknown";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << name << "'s constructor called" << std::endl;
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << other.name << "'s copy constructor called" << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << name << "'s destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
	if (isDead())
		return ;
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name
			<< " does not have enough energy to attack "
			<< target << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	if (isDead())
		return ;
	hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount<< " points of damage!" << std::endl;
	if (hitPoints <= 0)
	{
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " has died!" << std::endl;
	}
}

void    ClapTrap::beRepaired(unsigned int amount)
{
	if (isDead())
		return ;
	if (energyPoints <= 0)
		return ;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repairs itself, gaining " << amount << " hit points!" << std::endl;
	energyPoints--;
}

bool	ClapTrap::isDead(void)
{
	if (hitPoints > 0)
		return (false);
	std::cout << name << " is dead" << std::endl;
	return (true);
}
