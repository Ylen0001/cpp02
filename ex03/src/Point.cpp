/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:27:03 by ylenoel           #+#    #+#             */
/*   Updated: 2025/02/27 14:57:45 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point()
{
	
}

void Point::operator=(const Point& other)
{
	(void)other;
	return;
}

Fixed Point::get_x(void) const
{
	return(x);
}

Fixed Point::get_y(void) const
{
	return(y);
}

// float Point::crossProduct(Point const A, Point const B, Point const C)
// {
// 	return((B.x.toFloat() - A.x.toFloat()) * (C.y.toFloat() - A.y.toFloat()) - (B.y.toFloat() - A.y.toFloat()) * (C.x.toFloat() - A.x.toFloat()));
// }