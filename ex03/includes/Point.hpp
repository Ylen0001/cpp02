/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:27:21 by ylenoel           #+#    #+#             */
/*   Updated: 2025/02/26 17:40:00 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "../includes/Fixed.hpp"

class Point{
	
	private:
	
	const Fixed x;
	const Fixed y;
	
	public:
	
	Point();
	Point(const float x, const float y);
	~Point();
	Point& operator=(const Point& other);
	
	/* Les deux getter renvoient une copie et non une référence parce que sinon
	cela violerait le const de x et y. On ne peut pas renvoyer une référence
	modifiable vers une data const, on pourrait renvoyer une référence constante
	en notant const Fixed&, mais ce n'est pas si utile puisque Fixed est un petit objet */
	
	Fixed get_x(void) const;
	Fixed get_y(void) const;
	
};

#endif