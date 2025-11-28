#include "CandleStick.h"

CandleStick::CandleStick (
    std::string _date,
    std::string _countryCode,
    double _open,
    double _high,
    double _low,
    double _close
)
:
date(_date),
countryCode(_countryCode),
open(_open),
high(_high),
low(_low),
close(_close)
{
}

std::string CandleStick::toString() {
    return "Date: " +  date + ", country code: " + countryCode + ", open: " + std::to_string(open) 
        + ", high: " + std::to_string(high) + ", low: " + std::to_string(low) + ", close: " + std::to_string(close);
}

bool CandleStick::isWithinDateRange(std::string startingDate, std::string endingDate) {
    return date >= startingDate && date <= endingDate;
}