/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:25:31 by ylenoel           #+#    #+#             */
/*   Updated: 2025/02/27 14:59:03 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include "../includes/Fixed.hpp"

bool Point::bsp(Point A, Point B, Point C, Point P)
{
    float cross1 = A.crossProduct(A, B, C);
    float cross2 = A.crossProduct(B, C, P);
    float cross3 = A.crossProduct(C, A, P);
    return((cross1 >= 0 && cross2 >= 0 && cross3 >= 0) || (cross1 <= 0 && cross2 <= 0 && cross3 <= 0));
}

float Point::crossProduct(Point const A, Point const B, Point const C)
{
	return((B.x.toFloat() - A.x.toFloat()) * (C.y.toFloat() - A.y.toFloat()) - (B.y.toFloat() - A.y.toFloat()) * (C.x.toFloat() - A.x.toFloat()));
}