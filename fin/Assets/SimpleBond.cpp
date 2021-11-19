//
// Created by Rasmus Pallisgaard on 16/11/2021.
//

#include "SimpleBond.h"
#include <iostream>
#include <utility>

fin::SimpleBond::SimpleBond() = default;

fin::SimpleBond::SimpleBond(double face_value, Rate coupon_rate, std::string ticker)
    : _face_value(face_value), _coupon_rate(coupon_rate), _ticker(std::move(ticker)) {
  _maturity_date = Date::no_expiration();
}

fin::SimpleBond::SimpleBond(Date maturity_date, double face_value, Rate coupon_rate)
    : _maturity_date(maturity_date), _face_value(fin::BaseCurrency(face_value)), _coupon_rate(coupon_rate) {}

fin::SimpleBond::SimpleBond(Date maturity_date, const fin::BaseCurrency& face_value, Rate coupon_rate)
    : _maturity_date(maturity_date), _face_value(face_value.to_base()), _coupon_rate(coupon_rate) {}

fin::SimpleBond::SimpleBond(Date maturity_date, double face_value, Rate coupon_rate, std::string ticker)
    : _maturity_date(maturity_date), _face_value(fin::BaseCurrency(face_value)), _coupon_rate(coupon_rate),
      _ticker(std::move(ticker)) {}

fin::SimpleBond::SimpleBond(Date maturity_date, const fin::BaseCurrency& face_value, Rate coupon_rate, std::string ticker)
    : _maturity_date(maturity_date), _face_value(face_value.to_base()), _coupon_rate(coupon_rate), _ticker(std::move(ticker)) {}

fin::SimpleBond::SimpleBond(const fin::SimpleBond &b) {
  _maturity_date = b.maturity_date();
  _face_value = b.face_value();
  _ticker = b.ticker();
  _coupon_rate = b.coupon_rate();
}

Rate fin::SimpleBond::coupon_rate() const {
  return _coupon_rate;
}

fin::BaseCurrency fin::SimpleBond::face_value() const {
  return _face_value;
}

std::string fin::SimpleBond::ticker() const {
  return _ticker;
}

Date fin::SimpleBond::maturity_date() const {
  return _maturity_date;
}

fin::BaseCurrency fin::SimpleBond::coupon_payment() const {
  return _coupon_rate.to_decimal() * _face_value;
}

Rate fin::SimpleBond::expected_return() const {
  return _coupon_rate;
}

Rate fin::SimpleBond::volatility() const {
  return Rate(0.0);
}

int fin::SimpleBond::years_to_expiration() const {
  std::chrono::year current_year = Date::current_year();
  return int(_maturity_date.year()) - int(current_year);
}

fin::BaseCurrency fin::SimpleBond::present_value(Rate market_interest_rate) const {
  int y_to_m = years_to_expiration();
  double i_R = market_interest_rate.to_decimal();
  double C = (1 - pow(1 + i_R, -y_to_m)) / i_R;
  double M = pow(1 + i_R, -y_to_m);
  return coupon_payment() * C + _face_value * M;
}

fin::BaseCurrency fin::SimpleBond::current_yield(Rate market_interest_rate) const {
  return coupon_payment() / present_value(market_interest_rate);
}





