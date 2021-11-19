//
// Created by Rasmus Pallisgaard on 16/11/2021.
//

#include "SimpleStock.h"

fin::SimpleStock::SimpleStock(Rate expected_return, Rate volatility, std::string ticker)
    : _expected_return(expected_return), _volatility(volatility), _ticker(std::move(ticker)) {}

Rate fin::SimpleStock::expected_return() const { return _expected_return; }

Rate fin::SimpleStock::volatility() const { return _volatility; }

std::string fin::SimpleStock::ticker() const { return _ticker; }
