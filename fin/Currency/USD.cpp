//
// Created by Rasmus Pallisgaard on 19/11/2021.
//

#include "USD.h"

double fin::USD::get_conversion_rate() const {
  return 1.0;
}

std::string fin::USD::get_symbol() const {
  return "USD";
}

fin::USD fin::operator+(const fin::USD& c1, const fin::USD& c2) {
  return USD(c1.val() + c2.val());
}
