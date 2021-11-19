//
// Created by Rasmus Pallisgaard on 19/11/2021.
//

#pragma once

#include "BaseCurrency.h"

namespace fin {
class DKK : public BaseCurrency {
private:
  using BaseCurrency::BaseCurrency;

public:


  [[nodiscard]] std::string get_symbol() const override;

  [[nodiscard]] double get_conversion_rate() const override;

  friend DKK operator+(DKK const& c1, DKK const& c2);
};

}


