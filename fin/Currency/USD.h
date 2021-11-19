//
// Created by Rasmus Pallisgaard on 19/11/2021.
//

#pragma once
#include "BaseCurrency.h"

namespace fin {
class USD : public BaseCurrency {
private:
  using BaseCurrency::BaseCurrency;

public:
  [[nodiscard]] std::string get_symbol() const override;
  [[nodiscard]] double get_conversion_rate() const override;

  friend USD operator+(USD const& c1, USD const& c2);
};
}


