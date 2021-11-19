//
// Created by Rasmus Pallisgaard on 18/10/2021.
//

#pragma once

#include <string>
#include <vector>

#include "../Assets/DataAsset.h"
#include "../utilities/CsvFiles.h"

namespace fin {
class DataPortfolio {
	std::vector<DataAsset> _assets;
	bool _asset_names_on = true;

	[[nodiscard]] double _variance() const;

 public:
	DataPortfolio() = default;
	~DataPortfolio() = default;

	explicit DataPortfolio(std::vector<DataAsset> stock);

	explicit DataPortfolio(bool asset_names_on);

  explicit DataPortfolio(const fin::CSVFile& csv_file);

	void add_asset(const DataAsset& asset);

	void adjust_weights();

	[[nodiscard]] size_t n_assets() const;

	[[nodiscard]] const std::vector<DataAsset>& assets() const;
	[[nodiscard]] double expected_return() const;
	[[nodiscard]] double variance();
};
}	 // namespace fin