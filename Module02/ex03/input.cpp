/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:21:22 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/02 11:57:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <string>
#include <sstream>

bool isValidFloat(const std::string& input, float& value)
{
	std::stringstream ss(input);

	// Attempt to extract a float from the stringstream
	if (!(ss >> value)) {
		return false; // Failed to extract a float
	}

	// Check if there are any remaining characters in the stringstream
	char remaining;
	if (ss >> remaining) {
		return false; // There are remaining characters, so it's not a valid float
	}

	// Input is a valid float
	return true;
}

void clearAndIgnoreInvalidInput() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void	getInputAndStore(float& value)
{
	std::string input;
	std::cin >> input;

	while (!isValidFloat(input, value)) {
		std::cout << "Invalid input. Please enter a valid float: ";
		clearAndIgnoreInvalidInput();
		std::cin >> input;
	}
}

void	promptInput(float x[4], float y[4])
{
	std::string input;

	for (int i = 0; i < 4; ++i) {
		std::cout << "Enter the x-coordinate for point " << i + 1 << ": ";
		getInputAndStore(x[i]);

		std::cout << "Enter the y-coordinate for point " << i + 1 << ": ";
		getInputAndStore(y[i]);
	}

	for (int i = 0; i < 4; ++i) {
		std::cout << "Point " << i + 1 << ": (" << x[i] << ", " << y[i] << ")\n";
	}
}
