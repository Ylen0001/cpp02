/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:03:00 by ylenoel           #+#    #+#             */
/*   Updated: 2025/02/26 15:21:52 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	
	private :
	
	int value;
	static const int nb_Bits = 8;
	
	public :

	Fixed();
	Fixed(const int value);
	Fixed(const float value); 
	~Fixed();
	Fixed(const Fixed& other); // Constructeur de copie
	Fixed& 	operator=(const Fixed& other); // Opérateur d'affectation surchargée
	
	/* Surcharge d'opérateurs arythmétiques */
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed 	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	/* Surcharge d'opérateur pré incrémentation */ 
	Fixed&	operator++();
	Fixed&	operator--();
	/* Surcharge d'opérateur pré incrémentation */
	/* On utilise un int anonyme pour les différencier */ 
	Fixed	operator++(int);
	Fixed	operator--(int);

	/* Surcharge d'opérateur de comparaison */

	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	
	static Fixed&		min(Fixed& a, Fixed& b);
	const static Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	const static Fixed&	max(const Fixed& a, const Fixed& b);

	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float 	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif