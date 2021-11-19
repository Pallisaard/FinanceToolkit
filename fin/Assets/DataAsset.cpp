//
// Created by Rasmus Pallisgaard on 18/10/2021.
//

#include "DataAsset.h"

double fin::expected_return(const std::vector<double>& returns, const std::vector<double>& probabilities)
{
  if (probabilities.empty())
    return std::accumulate(returns.begin(), returns.end(), 0.0) / (double)returns.size();

  assert(probabilities.size() == returns.size());

  return std::inner_product(returns.begin(), returns.end(), probabilities.begin(), 0.0);
}

double fin::variance(const std::vector<double>& returns, const std::vector<double>& probabilities)
{
  assert(returns.size() == probabilities.size());

  double exp_returns = fin::expected_return(returns, probabilities);

  auto avg_diff = [&exp_returns](double cur, double ret) { return cur + std::pow(ret - exp_returns, 2); };

  auto weighted_diff = [&exp_returns](double ret, double prob) { return prob * std::pow(ret - exp_returns, 2.0); };

  if (probabilities.empty())
    return std::accumulate(returns.begin(), returns.end(), 0.0, avg_diff) / (double)returns.size();

  return std::inner_product(returns.begin(), returns.end(), probabilities.begin(), 0.0, std::plus<>(), weighted_diff);
}

double fin::standard_deviation(const std::vector<double>& returns, const std::vector<double>& probabilities)
{
  return std::sqrt(fin::variance(returns, probabilities));
}

double fin::covariance(const std::vector<double>& returns1, const std::vector<double>& returns2, const std::vector<
  double>& probabilities1, const std::vector<double>& probabilities2)
{
  assert(returns1.size() == returns2.size());
  assert(probabilities1.size() == probabilities2.size());

  auto cov_sum = 0.0;
  auto exp_ret_1 = expected_return(returns1, probabilities1);
  auto exp_ret_2 = expected_return(returns2, probabilities2);

  if (probabilities1.empty()) {
    for (int i = 0; i < returns1.size(); ++i)
      cov_sum += (returns1[i] - exp_ret_1) * (returns2[i] - exp_ret_2);

    cov_sum /= double(returns1.size());
  } else {
    for (int i = 0; i < returns1.size(); ++i)
      cov_sum += std::sqrt(probabilities1[i]) * (returns1[i] - exp_ret_1) * std::sqrt(probabilities2[i]) * (returns2[i] - exp_ret_2);
  }

  return cov_sum ;

}

double fin::covariance(const fin::DataAsset& asset1, const fin::DataAsset& asset2)
{
  return fin::covariance(asset1.returns(), asset2.returns(), asset1.probabilities(), asset2.probabilities());
}

double fin::correlation(const std::vector<double>& returns1, const std::vector<double>& returns2, const std::vector<
  double>& probabilities1, const std::vector<double>& probabilities2)
{
  double cov = covariance(returns1, returns2, probabilities1, probabilities2);

  double std1 = standard_deviation(returns1, probabilities1);
  double std2 = standard_deviation(returns2, probabilities2);

  return cov / (std1 * std2);
}

double fin::correlation(const fin::DataAsset& asset1, const fin::DataAsset& asset2)
{
  return fin::correlation(asset1.returns(), asset2.returns(), asset1.probabilities(), asset2.probabilities());
}

fin::DataAsset::DataAsset(std::vector<double> returns)
  : _returns(std::move(returns)) {}

fin::DataAsset::DataAsset(std::vector<double> returns, uint64_t amount)
  : _returns(std::move(returns)), _amount(amount) {}

fin::DataAsset::DataAsset(std::vector<double> returns, std::string name)
  : _returns(std::move(returns)), _name(std::move(name)) {}

fin::DataAsset::DataAsset(std::vector<double> returns, uint64_t amount, std::string name)
  : _returns(std::move(returns)), _amount(amount), _name(std::move(name)) {}

fin::DataAsset::DataAsset(std::vector<double> returns, std::vector<double> probabilities, std::string name)
  : _returns(std::move(returns)), _probabilities(std::move(probabilities)), _name(std::move(name)) {}

double fin::DataAsset::expected_return() const { return fin::expected_return(_returns, _probabilities); }

double fin::DataAsset::variance() const { return fin::variance(_returns, _probabilities); }

double fin::DataAsset::standard_deviation() const { return fin::standard_deviation(_returns, _probabilities); }

std::vector<double> fin::DataAsset::returns() const { return _returns; }

std::vector<double> fin::DataAsset::probabilities() const { return _probabilities; }

uint64_t fin::DataAsset::amount() const { return _amount; }

void fin::DataAsset::set_amount(uint64_t amount) { _amount = amount; }

std::string fin::DataAsset::name() const { return _name; }

size_t fin::DataAsset::size() const { return returns().size(); }

double fin::DataAsset::covariance(const fin::DataAsset& other) const
{
  return fin::covariance(_returns, other.returns(), _probabilities, other.probabilities());
}
double fin::DataAsset::correlation(const fin::DataAsset& other) const
{
  return fin::correlation(_returns, other.returns(), _probabilities, other.probabilities());
}
