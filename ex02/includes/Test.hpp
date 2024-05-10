./c	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:50:57 by yichan            #+#    #+#             */
/*   Updated: 2024/05/10 21:43:27 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include <iostream>
#include <string>

// change this to your program name, if want to test leaks
# define PROGRAM_NAME "a.out"

// Output test title
# define TEST_TITLE(x) std::cout << GREEN << x << RESET << std::endl;

// Output small test title
# define TEST_TITLE_S(x) std::cout << WHITE << x << ":" << RESET << std::endl;

// Output test description
# define TEST_DESC(x) std::cout << WHITE << "DESCRIPTION:\n" << WHITE << x << RESET << std::endl;

// Output test description continuation
# define TEST_DESC_CONT(x) std::cout << WHITE << x << RESET << std::endl;

// Test leaks
# define TEST_LEAKS(num) { \
    TEST_NL(); \
    std::cout << RED << "Leaks check for TEST "<< num << ":" << RESET << std::endl; \
    std::string command = std::string("leaks -q ") + std::string(PROGRAM_NAME); \
    system(command.c_str()); \
}

// Await user input to continue to next test
# define TEST_AWAIT() { \
    std::cout << WHITE << "Press [ENTER] to continue..." << RESET << std::endl; \
    std::cin.get(); \
}

#define TEST_CONCLUDE(x) { \
    std::cout <<  BLUE << "[CONCLUSION]\n" << RESET << GBLUE << x << RESET << std::endl; \
}

#define TEST_CONCLUDE_CONT(x) { \
    std::cout << BLUE << x << RESET << std::endl; \
}

# define TEST_NL() std::cout << std::endl;

# define TEST_HR() std::cout << WHITE << "\n==================================\n" << RESET << std::endl;

#endif