//
// Created by Rasmus Pallisgaard on 16/11/2021.
//

#pragma once

#include <cmath>
#include <ostream>

#include "ConvertibleCurrency.h"

namespace fin {

class BaseCurrency {
private:
  double _val{};
  std::string _symbol = "";

public:
  BaseCurrency();

  explicit BaseCurrency(double val);

  explicit BaseCurrency(int val);

  explicit BaseCurrency(uint val);

  [[nodiscard]] bool is_whole() const;

  [[nodiscard]] double val() const;

  [[nodiscard]] virtual std::string get_symbol() const {
    return _symbol;
  }

  [[nodiscard]] virtual double get_conversion_rate() const {
    return 1.0;
  }

  [[nodiscard]] BaseCurrency to_base() const;

  explicit operator int() const;

  explicit operator uint() const;

  explicit operator double() const;

  friend BaseCurrency operator+(BaseCurrency const& c1, BaseCurrency const& c2);

  friend BaseCurrency operator/(BaseCurrency const& c1, double const& c2);

  friend BaseCurrency operator/(double const& c1, BaseCurrency const& c2);

  friend BaseCurrency operator/(BaseCurrency const& c1, BaseCurrency const& c2);

  friend BaseCurrency operator*(BaseCurrency const& c1, double const& c2);

  friend BaseCurrency operator*(double const& c1, BaseCurrency const& c2);

  friend BaseCurrency operator*(BaseCurrency const& c1, BaseCurrency const& c2);

  friend std::ostream& operator<<(std::ostream& os, const BaseCurrency& cr);

  template<typename T>
  T convert_to() {
    static_assert(std::is_base_of<BaseCurrency, T>::value, "Type must have BaseCurrency as parent class.");
    return T(_val * get_conversion_rate() / T().get_conversion_rate());
  }
};

}
