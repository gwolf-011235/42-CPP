/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:48:53 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/17 18:39:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

// Function to replace all occurrences of 'search' with 'replace' in 'str'
std::string custom_replace(const std::string& str, const std::string& search, const std::string& replace)
{
	std::string result;

	size_t startPos = 0; // Start position for searching 'search'
	size_t foundPos;     // Position where 'search' was found

	while ((foundPos = str.find(search, startPos)) != std::string::npos) {
		// Append characters from 'startPos' to 'foundPos'
		result.append(str, startPos, foundPos - startPos);
		// Append the 'replace' string
		result.append(replace);
		// Update 'startPos' to the position after the 'search' string
		startPos = foundPos + search.length();
	}

	// Append characters after the last occurrence of 'search'
	result.append(str, startPos);

	return result;
}

void stream_replace(std::istream& in, std::ostream& out, std::string const& search, std::string const& replace)
{
	std::string line;
	while (std::getline(in, line)) {
		if (!in.eof())
			line += '\n';
		line = custom_replace(line, search, replace);
		out << line;
	}
}

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "usage: " << argv[0] << " filename s1_search s2_replace\n";
		return -1;
	}

	const std::string infile(argv[1]);
	std::ifstream in(infile.c_str());
	if (!in.is_open()) {
		std::cerr << "Failed to open infile" << infile << std::endl;
		return -1;
	}
	const std::string outfile(infile + ".replace");
	std::ofstream out(outfile.c_str(), std::ios::trunc);
	if (!out.is_open()) {
		std::cerr << "Failed to open outfile" << infile << std::endl;
		return -1;
	}

	stream_replace(in, out, argv[2], argv[3]);
}

