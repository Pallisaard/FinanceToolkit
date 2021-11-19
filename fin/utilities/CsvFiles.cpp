//
// Created by Rasmus Pallisgaard on 22/10/2021.
//

#include "CsvFiles.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
const std::vector<std::string>& fin::CSVFile::columns() const
{
	return _columns;
}

const std::vector<std::vector<double>>& fin::CSVFile::data() const
{
	return _data;
}

fin::CSVFile::CSVFile(std::vector<std::vector<double>> data)
		: _data(std::move(data))
{
}

fin::CSVFile::CSVFile(std::vector<std::vector<double>> data, std::vector<std::string> columns)
		: _data(std::move(data)), _columns(std::move(columns))
{
}
std::ostream& fin::operator<<(std::ostream& os, const fin::CSVFile& csv_file)
{
	for (auto&& c : csv_file.columns()) {
		os << c << "  | ";
	}
	os << std::endl;

	for (size_t i = 0; i < csv_file.data().size(); i++) {
		for (size_t j = 0; j < csv_file.data()[0].size(); j++) {
			os << csv_file.data()[i][j] << " | ";
		}
		os << std::endl;
	}

	return os;
}

fin::CSVFile fin::read_csv(const std::string& filename, bool&& has_columns)
{
	std::ifstream myFile(filename);
	std::vector<std::string> columns;
	std::vector<std::vector<double>> data;

	if (!myFile.good() || myFile.peek() == EOF) {
		std::cout << "file no" << std::endl;
		std::cout << myFile.good() << std::endl;
		std::cout << myFile.peek() << std::endl;
		std::cout << EOF << std::endl;
		return {};
	}

	std::string line;

	if (has_columns) {
		if (getline(myFile, line, '\n')) {
			std::istringstream iss(line);
			std::string col;
			while (getline(iss, col, ',')) {
				columns.push_back(col);
				data.emplace_back();
			}
		}
	}

	while (getline(myFile, line, '\n')) {
		size_t i = 0;
		std::istringstream iss(line);
		std::string val;
		while (getline(iss, val, ',')) {
			data[i].push_back(std::stof(val));
			i++;
		}
	}

	return {data, columns};
}
