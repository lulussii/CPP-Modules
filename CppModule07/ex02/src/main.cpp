/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:32:35 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/18 14:26:13 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    {
        std::cout << "---- TEST N.1 ---- " << std::endl;
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }
        
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;//
    }
    {
        std::cout << "\n---- TEST N.2 ---- " << std::endl;
        Array<std::string> words(2);
        words[0] = "hello";
        words[1] = "world";
        std::cout << "String : " << words[0] << " " << words[1] << std::endl;

        Array<std::string> copy = words;
        copy[0] = "bye";
        std::cout << "Original : " << words[0] << " " << words[1] << std::endl;
        std::cout << "Copy : " << copy[0] << " " << copy[1] << std::endl;
        
        try {
            std::cout << words[2] << std::endl;
        }
        catch ( std::exception &e)
        {
            std::cout << "Error caught: " << e.what() << std::endl;
        }
    }

}
