//
// Created by Rasmus Pallisgaard on 16/11/2021.
//

#pragma once

#include <string>
#include <utility>

#include "BaseAsset.h"
#include "../Currency/BaseCurrency.h"
#include "../utilities/Date.h"

namespace fin {
class SimpleBond : public BaseAsset {
private:
  Date _maturity_date{};
  BaseCurrency _face_value{};
  Rate _coupon_rate{};
  std::string _ticker{};

public:
  SimpleBond();

  SimpleBond(double face_value, Rate coupon_rate, std::string ticker);

  SimpleBond(Date maturity_date, double face_value, Rate coupon_rate);

  SimpleBond(Date maturity_date, const fin::BaseCurrency& face_value, Rate coupon_rate);

  SimpleBond(Date maturity_date, double face_value, Rate coupon_rate, std::string ticker);

  SimpleBond(Date maturity_date, const fin::BaseCurrency& face_value, Rate coupon_rate, std::string ticker);

  SimpleBond(const SimpleBond& b);
  [[nodiscard]] Rate coupon_rate() const;

  [[nodiscard]] BaseCurrency face_value() const;

  [[nodiscard]] std::string ticker() const override;;

  [[nodiscard]] Date maturity_date() const;

  [[nodiscard]] Rate expected_return() const override;

  [[nodiscard]] Rate volatility() const override;


  [[nodiscard]] fin::BaseCurrency coupon_payment() const;

  [[nodiscard]] int years_to_expiration() const;

  [[nodiscard]] fin::BaseCurrency present_value(Rate market_interest_rate) const;

  [[nodiscard]] fin::BaseCurrency current_yield(Rate market_interest_rate) const;
};


}


