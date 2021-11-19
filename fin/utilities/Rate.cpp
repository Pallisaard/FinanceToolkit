//
// Created by Rasmus Pallisgaard on 18/11/2021.
//

#include "Rate.h"
#include <iostream>
#include <iomanip>

Rate::Rate(double val) : _val(val) {}

double Rate::to_decimal() const { return _val / 100.0; }

double Rate::percentage() const { return _val; }

std::ostream& operator<<(std::ostream& os, Rate& rt) {
  auto c = std::cout.precision();
  os << rt.percentage() << "%";
  return os;
}

std::ostream& operator<<(std::ostream& os, Rate&& rt) {
  os << rt.percentage() << "%";
  return os;
}