//
// Created by Rasmus Pallisgaard on 16/11/2021.
//

#pragma once

#include <string>

#include "../Currency/BaseCurrency.h"
#include "../utilities/Rate.h"

using std::string;

namespace fin {
class BaseAsset {
public:
  [[nodiscard]] virtual Rate expected_return() const = 0;

  [[nodiscard]] virtual Rate volatility() const = 0;

  [[nodiscard]] virtual string ticker() const = 0;

  BaseAsset() = default;

  BaseAsset(BaseAsset const &) = delete;

  virtual ~BaseAsset() = default;
};
}

