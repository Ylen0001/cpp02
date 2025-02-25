/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:02:40 by ylenoel           #+#    #+#             */
/*   Updated: 2025/02/25 17:45:38 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/colors.hpp"
#include <iostream>
#include <cmath>

/* Constructeur */

Fixed::Fixed()
{
	this->value = 0;
	std::cout << C_LAVENDER_PURPLE "Default Constructor called!" C_RESET << std::endl;
}

Fixed::Fixed(const int value) // Constructeur int -> fixe
{
	this->value = roundf(value * (1 << nb_Bits)); // Converti en fixe
	/* On aurait pu aussi faire value * 256, mais << est plus rapide */
	std::cout << C_LAVENDER_PURPLE "Int Constructor called!" C_RESET << std::endl;
}

Fixed::Fixed(const float value) // Constructeur float -> fixe
{
	this->value = (int)roundf(value * (1 << nb_Bits)); // Arrondi avec roundf
	std::cout << C_LAVENDER_PURPLE "Float Constructor called!" C_RESET << std::endl;
}

/* Constructeur de copie */

Fixed::Fixed(const Fixed& other)
{
	std::cout << C_PLUM "Copy Constructor called!" C_RESET << std::endl;
	value = other.value;
}

/* Destructeur */

Fixed::~Fixed(void)
{
	std::cout << C_DUSTY_RED "Destructor called!" C_RESET << std::endl;
}

/* Surcharge d'opérateur = pour handle la copie d'objet comportant
des valeurs allouées sur la heap*/

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << C_PASTEL_PURPLE "Copy assignement operator called!" C_RESET << std::endl;
	if(this != &other)
		this->value = other.getRawBits();
	return *this;
}

/* Surcharge d'opérateur << pour afficher l'objet */

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

/* Fonctions membres de Fixed */

int Fixed::getRawBits(void) const
{
	// std::cout << C_PASTEL_BLUE "getRawBits member function called!" C_RESET << std::endl;
	return(this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << C_STEEL_BLUE "setRawBits member function called" C_RESET << std::endl;
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return((float)this->value / (1 << nb_Bits));
}

int Fixed::toInt(void) const
{
	return((int)(this->value >> nb_Bits));
}

/* Surcharge d'opérateur arythmétiques */

Fixed& Fixed::operator+(const Fixed& other) const
{
	Fixed ret(this->value + other.value);
	return ret;
}

Fixed& Fixed::operator-(const Fixed&other) const
{
	Fixed ret(this->value - other.value);
	return ret;
}

Fixed& Fixed::