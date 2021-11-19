//
// Created by Rasmus Pallisgaard on 18/11/2021.
//

#pragma once

#include <iostream>


class Rate {
private:
  double _val;
public:
  Rate() = default;

  explicit Rate(double val);

  [[nodiscard]] double percentage() const;

  [[nodiscard]] double to_decimal() const;

  friend std::ostream& operator<<(std::ostream& os, Rate& rt);

  friend std::ostream& operator<<(std::ostream& os, Rate&& rt);

  explicit operator double() const { return _val; };
};


