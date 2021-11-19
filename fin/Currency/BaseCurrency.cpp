//
// Created by Rasmus Pallisgaard on 16/11/2021.
//

#include "BaseCurrency.h"

fin::BaseCurrency::BaseCurrency() = default;
fin::BaseCurrency::BaseCurrency(double val)
{
  _val = val;
}
fin::BaseCurrency::BaseCurrency(int val)
  : _val(double(val)) {}
fin::BaseCurrency::BaseCurrency(uint val)
  : _val(double(val)) {}
fin::BaseCurrency::operator int() const { return int(_val); }
fin::BaseCurrency::operator double() const { return _val; }
fin::BaseCurrency::operator uint() const { return uint64_t(_val); }
bool fin::BaseCurrency::is_whole() const
{
  return (double(int(_val)) == _val);
}
double fin::BaseCurrency::val() const
{
  return _val;
}
fin::BaseCurrency fin::operator/(fin::BaseCurrency const& c1, double const& c2)
{
  return BaseCurrency(c1.val() * c1.get_conversion_rate() / c2);
}
fin::BaseCurrency fin::operator/(double const& c1, fin::BaseCurrency const& c2)
{
  return c2 / c1;
}fin::BaseCurrency fin::operator/(BaseCurrency const& c1, fin::BaseCurrency const& c2)
{
  return BaseCurrency(c2.val() * c2.get_conversion_rate() / c1.val() * c1.get_conversion_rate());
}
fin::BaseCurrency fin::operator*(fin::BaseCurrency const& c1, double const& c2)
{
  return BaseCurrency(c1.val() * c1.get_conversion_rate() * c2);
}
fin::BaseCurrency fin::operator*(double const& c1, fin::BaseCurrency const& c2)
{
  return c2 * c1;
}
fin::BaseCurrency fin::operator*(BaseCurrency const& c1, fin::BaseCurrency const& c2)
{
  return BaseCurrency(c2.val() * c2.get_conversion_rate() * c1.val() * c1.get_conversion_rate());
}
fin::BaseCurrency fin::operator+(fin::BaseCurrency const& c1, fin::BaseCurrency const& c2)
{
  return BaseCurrency(c1.val() * c1.get_conversion_rate() + c2.val() * c2.get_conversion_rate());
}
std::ostream& fin::operator<<(std::ostream& os, const fin::BaseCurrency& cr)
{
  os << cr.val() << " " << cr.get_symbol();
  return os;
}

fin::BaseCurrency fin::BaseCurrency::to_base() const {
  return BaseCurrency(_val * get_conversion_rate());
}








