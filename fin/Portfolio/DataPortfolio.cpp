//
// Created by Rasmus Pallisgaard on 18/10/2021.
//

#include "../Assets/DataAsset.h"
#include "DataPortfolio.h"

fin::DataPortfolio::DataPortfolio(std::vector<DataAsset> stock)
  : _assets(std::move(stock))
{
  for (auto&& asset: _assets) {
    if (asset.name().empty()) {
      _asset_names_on = true;
      break;
    }
  }

  if (_asset_names_on) {
    std::sort(_assets.begin(), _assets.end(), [](const DataAsset& as1, const DataAsset& as2)
    {
      return as1.name().compare(as2.name()) < 0;
    });
    auto adj = std::adjacent_find(_assets.begin(), _assets.end(), [](const DataAsset& as1, const DataAsset& as2)
    {
      return as1.name() == as2.name();
    });

    assert(adj == _assets.end());
  }
}

fin::DataPortfolio::DataPortfolio(bool asset_names_on)
  : _asset_names_on(asset_names_on)
{

}

const std::vector<fin::DataAsset>& fin::DataPortfolio::assets() const
{
  return _assets;
}

void fin::DataPortfolio::add_asset(const fin::DataAsset& asset)
{
  if (_asset_names_on)
    assert(!asset.name().empty());

  _assets.push_back(asset);
}
double fin::DataPortfolio::expected_return() const
{
  return std::accumulate(_assets.begin(), _assets.end(), 0.0, [](const double& sum, const DataAsset& as)
  {
    return sum + double(as.amount()) * as.expected_return();
  });
}

double fin::DataPortfolio::_variance() const
{
  double acum_var = 0.0;

  for (auto&& asset: assets())
    acum_var += std::pow(asset.amount(), 2) * asset.variance();

  for (size_t i = 0; i < n_assets(); ++i) {
    for (size_t j = 0; j < n_assets(); ++j) {
      if (i != j)
        acum_var += double(assets()[i].amount()) * double(assets()[j].amount()) * assets()[i].covariance(assets()[j]);
    }
  }

  return acum_var;
}

double fin::DataPortfolio::variance()
{
  adjust_weights();

  return _variance();
}

size_t fin::DataPortfolio::n_assets() const
{
  return assets().size();
}

void fin::DataPortfolio::adjust_weights()
{
  uint64_t weight_sum = std::accumulate(assets().begin(), assets().end(), 0, [](const uint64_t& acum, const DataAsset& asset)
  {
    return acum + asset.amount();
  });

  for (DataAsset& asset: _assets)
    asset.set_amount(asset.amount() / weight_sum);
}

fin::DataPortfolio::DataPortfolio(const fin::CSVFile& csv_file) : _assets({})
{
  size_t length = csv_file.data().size();

  for (size_t i = 0; i < length; i++) {
    auto asset = fin::DataAsset(csv_file.data()[i], csv_file.columns()[i]);
    _assets.push_back(asset);
  }
}
