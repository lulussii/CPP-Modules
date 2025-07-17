/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:29:26 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/17 09:51:18 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"
#include <iostream>

int main( void ) 
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point p(5, 4);

    std::cout << "Test avec le point p de coordonnées : " << p.getX() << "," << p.getY() << std::endl;
    if (bsp(a, b, c, p))
        std::cout << "✅ Dans le triangle" << std::endl;
    else
        std::cout << "❌ En dehors du triangle" << std::endl;
    return 0;
}
