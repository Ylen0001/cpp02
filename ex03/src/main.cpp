/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:06:13 by ylenoel           #+#    #+#             */
/*   Updated: 2025/02/27 14:59:28 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"
#include <iostream>	

int main(void)
{
	Point A(0, 0);
	Point B(5, 0);
	Point C(2.5, 5);
	Point P1(2.5, 2);
	Point P2(6,6);

	if(A.bsp(A, B, C, P1))
		std::cout << "P1 is inside the triangle!" << std::endl;
	else
	 	std::cout << "P1 is outside the triangle!" << std::endl;

	if(A.bsp(A, B, C, P2))
		std::cout << "P1 is inside the triangle!" << std::endl;
	else
	 	std::cout << "P1 is outside the triangle!" << std::endl;

	return (0);
}