/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:01:09 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/13 10:25:05 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "../include/Intern.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Big Boss", 1);

    std::cout << "--- Test 1 : Robotomy Request ---" << std::endl;
    try
    {
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n--- Test 2 : Presidential Pardon ---" << std::endl;
    try
    {
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (ppf)
        {
            std::cout << *ppf << std::endl;
            boss.signForm(*ppf);
            boss.executeForm(*ppf);
            delete ppf;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n--- Test 3 : Shrubbery Creation ---" << std::endl;
    try
    {
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Home");
        if (scf)
        {
            std::cout << *scf << std::endl;
            boss.signForm(*scf);
            boss.executeForm(*scf);
            delete scf;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n--- Test 4 : Unknown Form ---" << std::endl;
    try
    {
        AForm* unknown = someRandomIntern.makeForm("nonexisting form", "Carl");
        if (unknown)
            delete unknown;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}