/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:03:00 by ylenoel           #+#    #+#             */
/*   Updated: 2025/02/24 14:19:48 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{
	
	private :
	
	int value;
	static const int nb_Bits = 8;
	
	public :

	Fixed();
	~Fixed();
	Fixed(const Fixed& other); // Constructeur de copie
	Fixed& operator=(const Fixed& other); // Opérateur d'affectation surchargée
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif