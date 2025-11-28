#pragma once
#include <string>

static const std::string countryCodeArr[28] = {"AT", "BE", "BG", "CH", "CZ", "DE", "DK",
                                        "EE", "ES", "FI", "FR", "GB", "GR", "HR",
                                        "HU", "IE", "IT", "LT", "LU", "LV", "NL",
                                        "NO", "PL", "PT", "RO", "SE", "SI", "SK"};
static const int COUNTRY_CODE_NUM = 28;

bool verifyDate(std::string date);
bool verifyTimestamp(std::string timestamp);
bool verifyCountrycode(std::string countryCode);