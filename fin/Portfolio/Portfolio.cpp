//
// Created by Rasmus Pallisgaard on 18/11/2021.
//

#include "Portfolio.h"

fin::Portfolio::Portfolio(vector<unique_ptr<BaseAsset>> assets, vector<int> weights)
    : _assets(std::move(assets)), _position_sizes(std::move(weights)) {
  assert(_position_sizes.size() == _assets.size());
  _init_covariances(int(n_assets()));
}

fin::Portfolio::Portfolio(vector<unique_ptr<BaseAsset>> assets)
    : _assets(std::move(assets)) {
  _position_sizes = vector<int>(assets.size(), 1);
  _init_covariances(int(n_assets()));
}

unique_ptr<fin::BaseAsset> &fin::Portfolio::get_asset(int id) {
  return _assets[id];
}

vector<int> fin::Portfolio::position_sizes() const {
  return _position_sizes;
}

size_t fin::Portfolio::n_assets() const {
  return _assets.size();
}

Rate fin::Portfolio::expected_return() const {
  double sum = 0.0;
  for (size_t i = 0; i < _assets.size(); i++) {
    sum += _assets[i]->expected_return().percentage() * _pos_wht(int(i));
  }
  return Rate(sum);
}

void fin::Portfolio::_init_covariances(int i) {
  _covariances = vector<vector<Rate>>(i, vector<Rate>(i, Rate(0.0)));
  for (size_t k = 0; k < _covariances.size(); k++)
    _covariances[k][k] = Rate(pow(_assets[k]->volatility().percentage(), 2));
}

Rate fin::Portfolio::volatility() {
  double acum_var = 0.0;

  if (covariances().size() == n_assets())
    _init_covariances(int(n_assets()));

  for (size_t i = 0; i < _assets.size(); i++)
    acum_var += _pos_wht(int(i)) * _pos_wht(int(i)) * pow(_assets[i]->volatility().percentage(), 2);

  for (size_t i = 0; i < n_assets(); ++i) {
    for (size_t j = 0; j < n_assets(); ++j) {
      if (i != j)
        acum_var += _pos_wht(int(i)) * _pos_wht(int(j)) * _covariances[i][j].percentage();
    }
  }
  return Rate(acum_var);
}

