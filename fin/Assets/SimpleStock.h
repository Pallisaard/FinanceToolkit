//
// Created by Rasmus Pallisgaard on 16/11/2021.
//

#pragma once

#include <utility>
#include <vector>
#include <string>

#include "BaseAsset.h"

namespace fin {
class SimpleStock : public BaseAsset {
private:
  Rate _expected_return{};
  Rate _volatility{};
  std::string _ticker;

public:
  SimpleStock() = default;

  SimpleStock(Rate expected_return, Rate volatility, std::string ticker);

  SimpleStock(const SimpleStock& s) {
    _expected_return = s.expected_return();
    _volatility = s.volatility();
    _ticker = s.ticker();
  }

  [[nodiscard]] Rate expected_return() const override;

  [[nodiscard]] Rate volatility() const override;

  [[nodiscard]] std::string ticker() const override;
};

}
