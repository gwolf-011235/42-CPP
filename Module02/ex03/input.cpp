/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:21:22 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/02 09:35:45 by gwolf            ###   ########.fr       */
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

	// Input validation for a valid float
	while (!isValidFloat(input, value)) {
		std::cout << "Invalid input. Please enter a valid float: ";
		clearAndIgnoreInvalidInput();
		std::cin >> input;
	}
}

int promptInput(void)
{
	float x[4], y[4];
	std::string input;

	for (int i = 0; i < 4; ++i) {
		// Prompt the user to input the x-coordinate
		std::cout << "Enter the x-coordinate for point " << i + 1 << ": ";
		getInputAndStore(x[i]);

		// Prompt the user to input the y-coordinate
		std::cout << "Enter the y-coordinate for point " << i + 1 << ": ";
		getInputAndStore(y[i]);
	}

	// Now, you have the x and y coordinates stored in the arrays x[] and y[].

	for (int i = 0; i < 4; ++i) {
		std::cout << "Point " << i + 1 << ": (" << x[i] << ", " << y[i] << ")\n";
	}

	return 0;
}
