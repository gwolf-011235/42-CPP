/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:50:50 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/07 20:04:44y gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE!! *" << std::endl;
		return 0;
	}
	std::string input;
	for (int count = 1; count < argc; ++count)
		input += argv[count];
	for (size_t i = 0; input[i]; ++i)
		input.at(i) = toupper(input.at(i));
	std::cout << input << std::endl;
	return 0;
}
