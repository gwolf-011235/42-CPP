/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:48:53 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/26 14:10:57 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string custom_replace(const std::string& str, const std::string& search, const std::string& replace)
{
	std::string result;

	size_t startPos = 0;
	size_t foundPos;

	while ((foundPos = str.find(search, startPos)) != std::string::npos) {
		result.append(str, startPos, foundPos - startPos);
		result.append(replace);
		startPos = foundPos + search.length();
	}
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
		std::cerr << "Failed to open infile " << infile << std::endl;
		return -1;
	}
	const std::string outfile(infile + ".replace");
	std::ofstream out(outfile.c_str(), std::ios::trunc);
	if (!out.is_open()) {
		std::cerr << "Failed to open outfile " << outfile << std::endl;
		return -1;
	}

	stream_replace(in, out, argv[2], argv[3]);
}

