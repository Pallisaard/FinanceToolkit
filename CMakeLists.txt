cmake_minimum_required(VERSION 3.20)
project(FinanceToolKit)

set(CMAKE_CXX_STANDARD 20)

add_executable(FinanceToolKit main.cpp fin/Assets/DataAsset.cpp fin/Assets/DataAsset.h fin/Portfolio/DataPortfolio.cpp fin/Portfolio/DataPortfolio.h fin/utilities/CsvFiles.cpp fin/utilities/CsvFiles.h fin/Assets/BaseAsset.cpp fin/Assets/BaseAsset.h fin/Assets/SimpleBond.cpp fin/Assets/SimpleBond.h fin/utilities/vector_repr.cpp fin/utilities/vector_repr.h fin/utilities/Date.cpp fin/utilities/Date.h fin/Currency/BaseCurrency.cpp fin/Currency/BaseCurrency.h fin/utilities/ostreams.cpp fin/Assets/SimpleStock.cpp fin/Assets/SimpleStock.h fin/Portfolio/Portfolio.cpp fin/Portfolio/Portfolio.h fin/Assets.h fin/Currency.h fin/utility.h fin/Portfolio.h fin/utilities/Rate.cpp fin/utilities/Rate.h fin/Currency/USD.cpp fin/Currency/USD.h fin/Currency/ConvertibleCurrency.cpp fin/Currency/ConvertibleCurrency.h fin/Currency/DKK.cpp fin/Currency/DKK.h)
