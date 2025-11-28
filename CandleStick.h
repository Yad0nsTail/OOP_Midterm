#pragma once

#include <string>

class CandleStick {

    public:

        CandleStick(
            std::string _date,
            std::string _countryCode,
            double _open,
            double _high,
            double _low,
            double _close
        );

        std::string toString();
        bool isWithinDateRange(std::string startingDate, std::string endingDate);

        std::string countryCode;
        std::string date;
        double open;
        double high;
        double low;
        double close;
};
