//
// Created by Rasmus Pallisgaard on 18/11/2021.
//

#pragma once

#include <memory>
#include <utility>
#include <vector>
#include <type_traits>
#include <numeric>
#include <iostream>

#include "../Assets/BaseAsset.h"
#include "../utilities/Rate.h"

using std::vector;
using std::unique_ptr;
using std::make_unique;

namespace fin {
class Portfolio {
private:
  vector<unique_ptr<BaseAsset>> _assets;
  vector<int> _position_sizes;
  vector<vector<Rate>> _covariances;

  [[nodiscard]] double _pos_wht(int i) const {
    return double(_position_sizes[i]) / double(n_assets());
  }

  void _init_covariances(int i);

public:
  Portfolio() = default;

  Portfolio(vector<unique_ptr<BaseAsset>> assets, vector<int> weights);

  explicit Portfolio(vector<unique_ptr<BaseAsset>> assets);

  [[nodiscard]] unique_ptr<BaseAsset> &get_asset(int id);

  [[nodiscard]] size_t n_assets() const;

  [[nodiscard]] vector<int> position_sizes() const;

  [[nodiscard]] vector<vector<Rate>> covariances() const {
    return _covariances;
  }

  template<typename T>
  void add_asset(T &asset, int amount) {
    _assets.push_back(make_unique<T>(asset));
    _position_sizes.push_back(amount);
    _init_covariances(int(n_assets()));
  }

  [[nodiscard]] Rate expected_return() const;

  [[nodiscard]] Rate volatility();
};
}
