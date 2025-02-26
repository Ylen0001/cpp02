/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:03:00 by ylenoel           #+#    #+#             */
/*   Updated: 2025/02/26 13:32:25 by ylenoel          ###   ########.fr       */
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
	
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float 	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif