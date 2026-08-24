/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:05:05 by mbirou            #+#    #+#             */
/*   Updated: 2026/07/08 20:48:04 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_HPP
# define DEFINES_HPP

# define CLEAR	"\033[2J\033[H"

# define RESET	"\033[0m"
# define CLR	"\033[0m"
# define BOLD	"\033[1m"
# define UNDL	"\033[4m"
# define DUNDL	"\033[21m"
# define ITAL	"\033[3m"
# define STRK	"\033[9m"

# define BLK	"\033[0;30m"
# define RED	"\033[0;31m"
# define GRN	"\033[0;32m"
# define YLW	"\033[0;33m"
# define BLU	"\033[0;34m"
# define PRP	"\033[0;35m"
# define CYN	"\033[0;36m"
# define WHT	"\033[0;37m"
# define ORG RGB(255, 92, 0)

# define RGB(r, g, b) "\033[0;38;2;" #r ";" #g ";" #b "m"
# define DSTR RGB(200, 200, 0)

# define AND <<
# define PRINT std::cout AND
# define PRERR std::cerr AND
# define ENDL AND std::endl
# define CENDL AND CLR ENDL
# define TAB "\t" AND
# define NEWL PRINT "" ENDL;
# define SAND AND "; " AND
# define SANDN(name) AND "; " #name ":" AND


#endif