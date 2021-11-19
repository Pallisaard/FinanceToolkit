//
// Created by Rasmus Pallisgaard on 16/11/2021.
//

#include <iostream>
#include<iomanip>

#include "Date.h"
Date::Date(int day, int month, int year) : year_month_day(std::chrono::year(year), std::chrono::month(month), std::chrono::day(day))
{}

std::ostream& operator<<(std::ostream& os, const Date& dt) {
  os << std::setfill('0') << std::setw(2) << uint(dt.day()) << '/'
     << std::setw(2) << std::setfill('0') << uint(dt.month()) << '/'
     << std::setw(4) << std::setfill('0') << int(dt.year());
  return os;
}
Date::Date() : year_month_day() {}
std::chrono::year Date::current_year()
{
  auto current = std::chrono::system_clock::now();
  auto current_t = std::chrono::system_clock::to_time_t(current);
  auto current_year = 1900 + localtime(&current_t)->tm_year;
  return std::chrono::year(current_year);
};
