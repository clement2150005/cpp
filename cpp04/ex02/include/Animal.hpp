/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:59:51 by ccolin            #+#    #+#             */
/*   Updated: 2025/04/09 10:30:05 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <Brain.hpp>

class Animal
{
protected:
	std::string type;
	
public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();
	
	virtual void	makeSound() const;
	std::string		getType() const;
	virtual Brain*	getBrain() const = 0;
	virtual void	setIdea (std::string idea, int index) = 0;
	virtual void	think (int index) const = 0;
};
