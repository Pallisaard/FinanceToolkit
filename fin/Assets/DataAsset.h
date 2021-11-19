//
// Created by Rasmus Pallisgaard on 18/10/2021.
//
#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <functional>
#include <cassert>
#include <cmath>
#include <iostream>

namespace fin
{
class DataAsset
{
  std::vector<double> _returns;
  uint64_t _amount = 1;
  std::string _name;
  std::vector<double> _probabilities;

public:
  DataAsset() = default;
  ~DataAsset() = default;

  explicit DataAsset(std::vector<double> returns);
  DataAsset(std::vector<double> returns, uint64_t amount);
  DataAsset(std::vector<double> returns, std::string name);
  DataAsset(std::vector<double> returns, uint64_t amount, std::string name);
  DataAsset(std::vector<double> returns, std::vector<double> probabilities, std::string name);

  [[nodiscard]] uint64_t amount() const;

  void set_amount(uint64_t amount);

  [[nodiscard]] std::vector<double> returns() const;
  [[nodiscard]] std::vector<double> probabilities() const;

  [[nodiscard]] std::string name() const;

  [[nodiscard]] size_t size() const;

  [[nodiscard]] double expected_return() const;

  [[nodiscard]] double variance() const;

  [[nodiscard]] double standard_deviation() const;

  [[nodiscard]] double covariance(const DataAsset& other) const;

  [[nodiscard]] double correlation(const DataAsset& other) const;
};


double expected_return(const std::vector<double>& returns, const std::vector<double>& probabilities = {});

double variance(const std::vector<double>& returns, const std::vector<double>& probabilities = {});

double standard_deviation(const std::vector<double>& returns, const std::vector<double>& probabilities = {});

double covariance(const std::vector<double>& returns1, const std::vector<double>& returns2, const std::vector<double>& probabilities1 = {}, const std::vector<double>& probabilities2 = {});
double covariance(const fin::DataAsset& asset1, const fin::DataAsset& asset2);

double correlation(const std::vector<double>& returns1, const std::vector<double>& returns2, const std::vector<double>& probabilities1 = {}, const std::vector<double>& probabilities2 = {});
double correlation(const fin::DataAsset& asset1, const fin::DataAsset& asset2);


}