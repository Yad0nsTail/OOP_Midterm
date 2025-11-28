#pragma once

#include <string>

class CandleStickRaw {

    public:

        CandleStickRaw(
            std::string _date,
            double temperatures[28]
        );

        bool operator<(const CandleStickRaw& other) const;

        std::string toString();
        bool isWithinDateRange(std::string startingDate, std::string endingDate);
        double getTemperatureByCountry(std::string countryCode);

        std::string date;

    private:
        double AT_temperature;
        double BE_temperature;
        double BG_temperature;
        double CH_temperature;
        double CZ_temperature;
        double DE_temperature;
        double DK_temperature;
        double EE_temperature;
        double ES_temperature;
        double FI_temperature;
        double FR_temperature;
        double GB_temperature;
        double GR_temperature;
        double HR_temperature;
        double HU_temperature;
        double IE_temperature;
        double IT_temperature;
        double LT_temperature;
        double LU_temperature;
        double LV_temperature;
        double NL_temperature;
        double NO_temperature;
        double PL_temperature;
        double PT_temperature;
        double RO_temperature;
        double SE_temperature;
        double SI_temperature;
        double SK_temperature;
};
