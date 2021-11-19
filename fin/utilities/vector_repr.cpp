//
// Created by Rasmus Pallisgaard on 16/11/2021.
//

#include "vector_repr.h"

std::string vector_repr(std::vector<std::string>& vec)
{
  std::string str = "{";

  for (auto&& c : vec) {
    str += c;
    str += ", ";
  }

  if (!vec.empty()) {
    str.pop_back();
    str.pop_back();
  }

  return str + "}";
}

template <typename T>
std::string vector_repr(std::vector<T>& vec)
{
  std::string str = "{";

  for (auto&& c : vec) {
    str += std::to_string(c);
    str += ", ";
  }

  if (vec.size() > 0) {
    str.pop_back();
    str.pop_back();
  }

  return str + "}";
}

template <typename T>
std::string vector_repr(std::vector<T>&& vec)
{
  std::string str = "{";

  for (auto c : vec) {
    str += std::to_string(c);
    str += ", ";
  }

  if (vec.size() > 0) {
    str.pop_back();
    str.pop_back();
  }

  return str + "}";
}
