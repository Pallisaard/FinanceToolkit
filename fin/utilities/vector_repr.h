//
// Created by Rasmus Pallisgaard on 16/11/2021.
//

#pragma once
#include <vector>
#include <string>

std::string vector_repr(std::vector<std::string>& vec);
template <typename T>
std::string vector_repr(std::vector<T>& vec);
template <typename T>
std::string vector_repr(std::vector<T>&& vec);
template <typename T>
std::string vector_repr(std::vector<std::vector<T>>& vec);