//
// Created by Rasmus Pallisgaard on 19/11/2021.
//

#pragma once

#include <string>

namespace fin {
class ConvertibleCurrency {
private:

public:
  [[nodiscard]] virtual std::string get_symbol() const = 0;
  [[nodiscard]] virtual double get_conversion_rate() const = 0;

};
}


