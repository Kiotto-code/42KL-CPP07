/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:53:00 by yichan            #+#    #+#             */
/*   Updated: 2024/05/08 00:59:32 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP

# define GREEN	"\x1B[0;92m"
# define YELLOW	"\x1B[0;93m"
# define BLUE	"\x1B[0;94m"
# define PINK	"\x1B[0;95m"
# define CYAN	"\x1B[0;96m"
# define WHITE	"\x1B[38;5;15m"
# define GREY	"\x1B[38;5;8m"
# define ORANGE	"\x1B[38;5;202m"
# define RED	"\x1B[38;5;160m"
# define RESET	"\033[0m"

# define MAGENTA	"\x1B[0;35m"   // Sets the text color to magenta.
# define LIGHT_RED	"\x1B[1;31m"   // Sets the text color to light red.
# define LIGHT_GREEN	"\x1B[1;32m"   // Sets the text color to light green.
# define LIGHT_YELLOW	"\x1B[1;33m"   // Sets the text color to light yellow.
# define LIGHT_BLUE	"\x1B[1;34m"   // Sets the text color to light blue.
# define LIGHT_MAGENTA	"\x1B[1;35m"   // Sets the text color to light magenta.
# define LIGHT_CYAN	"\x1B[1;36m"   // Sets the text color to light cyan.
# define LIGHT_WHITE	"\x1B[1;37m"   // Sets the text color to light white.
# define LIGHT_GREY	"\x1B[0;37m"   // Sets the text color to light grey.
# define DARK_GREY	"\x1B[1;30m"   // Sets the text color to dark grey.

# define GOLD "\x1B[1;33m"   // Sets the text color to a bright yellow (light yellow) with bold attribute.
# define cterm() std::cin.get(); std::cout << "\e[1;1H\e[2J";

#endif
