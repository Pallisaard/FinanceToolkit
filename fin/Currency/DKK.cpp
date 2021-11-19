//
// Created by Rasmus Pallisgaard on 19/11/2021.
//

#include "DKK.h"

std::string fin::DKK::get_symbol() const {
  return "DKK";
}

double fin::DKK::get_conversion_rate() const {
  return 1 / 6.31;
}

fin::DKK fin::operator+(const fin::DKK& c1, const fin::DKK& c2) {
  return DKK(c1.val() + c2.val());
}
