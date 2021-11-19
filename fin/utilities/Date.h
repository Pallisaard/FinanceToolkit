//
// Created by Rasmus Pallisgaard on 16/11/2021.
//

#pragma once
#include <chrono>

class Date : public std::chrono::year_month_day
{
public:
  Date();
  Date(int day, int month, int year);

  static std::chrono::year current_year();
  static Date no_expiration() {
    return {31, 12, 9999};
  }

  friend std::ostream& operator<<(std::ostream& os, const Date& dt);
};