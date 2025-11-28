#include "Helper.h"

#include <iostream>

bool verifyDate(std::string date) {
    if (date.length() < 10) {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (date[i] != '-') {
                std::cout << std::to_string(i) + "th character not a dash!" << std::endl;
                return false;
            }
            continue;
        }
        int ascii = (int) date[i];
        if (ascii < 48 || ascii > 57) {
            std::cout << std::to_string(i) + "th character not a number!" << std::endl;
            return false;
        }
    }

    return true;
}

bool verifyTimestamp(std::string timestamp) {
    if (!verifyDate(timestamp)) {
        return false;
    }

    // example: 1980-01-01T13:00:00Z
    if (timestamp.length() < 19) {
        return false;
    }

    for (int i = 11; i < 19; i++) {
        if (i == 13 || i == 16) {
            if(timestamp[i] != ':') {
                std::cout << "time not in proper format HH:MM:SS - " << timestamp << std::endl;
            }
            continue;
        }
        int ascii = (int) timestamp[i];
        if (ascii < 48 || ascii > 57) {
            std::cout << std::to_string(i) + "th character not a number!" << std::endl;
            return false;
        }
    }
    return true;
}

bool verifyCountrycode(std::string countryCode) {
    return countryCode == "AT" || countryCode == "BE" || countryCode == "BG" 
    || countryCode == "CH" || countryCode == "CZ" || countryCode == "DE" || countryCode == "DK"
    || countryCode == "EE" || countryCode == "ES" || countryCode == "FI" || countryCode == "FR"
    || countryCode == "GB" || countryCode == "GR" || countryCode == "HR" || countryCode == "HU"
    || countryCode == "IE" || countryCode == "IT" || countryCode == "LT" || countryCode == "LU"
    || countryCode == "LV" || countryCode == "NL" || countryCode == "NO" || countryCode == "PL" 
    || countryCode == "PT" || countryCode == "RO" || countryCode == "SE" || countryCode == "SI"
    || countryCode == "SK";
}
        