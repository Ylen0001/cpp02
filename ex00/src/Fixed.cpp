/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:02:40 by ylenoel           #+#    #+#             */
/*   Updated: 2025/02/24 15:14:20 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/colors.hpp"
#include <iostream>

/* Constructeur */

Fixed::Fixed(void)
{
	this->value = 0;
	std::cout << C_LAVENDER_PURPLE "Default Constructor called!" C_RESET << std::endl;
}

/* Constructeur de copie */

Fixed::Fixed(const Fixed& other)
{
	std::cout << C_PLUM "Copy Constructor called!" C_RESET << std::endl;
	value = other.getRawBits();
}

/* Destructeur */

Fixed::~Fixed(void)
{
	std::cout << C_DUSTY_RED "Destructor called!" C_RESET << std::endl;
}

/* Surcharge d'opérateur */

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << C_PASTEL_PURPLE "Copy assignement operator called!" C_RESET << std::endl;
	if(this != &other)
		this->value = other.getRawBits();
	return *this;
}

/* Fonctions membres de Fixed */

int Fixed::getRawBits(void) const
{
	std::cout << C_PASTEL_BLUE "getRawBits member function called!" C_RESET << std::endl;
	return(this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << C_STEEL_BLUE "setRawBits member function called" C_RESET << std::endl;
	this->value = raw;
}

