//
// Created by Rasmus Pallisgaard on 22/10/2021.
//

#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace fin {
class CSVFile {
	std::vector<std::string> _columns;
	std::vector<std::vector<double>> _data;

 public:
	CSVFile() = default;
	explicit CSVFile(std::vector<std::vector<double>> data);
	CSVFile(std::vector<std::vector<double>> data, std::vector<std::string> columns);

	~CSVFile() = default;

	[[nodiscard]] const std::vector<std::string>& columns() const;
	[[nodiscard]] const std::vector<std::vector<double>>& data() const;

	friend std::ostream& operator<<(std::ostream& os, const CSVFile& csv_file);
};

CSVFile read_csv(const std::string& filename, bool&& has_columns = true);
}	 // namespace fin