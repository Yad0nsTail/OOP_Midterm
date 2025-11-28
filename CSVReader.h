#pragma once
#include "CandleStickRaw.h"
#include <vector>
#include <string>

class CSVReader {

    public:
        CSVReader();

        static std::vector<CandleStickRaw> readCSV(std::string csvFile);
        static std::vector<std::string> tokenise(std::string csvLine, char separator);

        static CandleStickRaw stringToCS(
            std::string date,
            std::string AT_temperature,
            std::string BE_temperature,
            std::string BG_temperature,
            std::string CH_temperature,
            std::string DE_temperature,
            std::string DK_temperature,
            std::string ES_temperature,
            std::string FI_temperature,
            std::string FR_temperature,
            std::string GB_temperature,
            std::string GR_temperature,
            std::string HU_temperature,
            std::string IE_temperature,
            std::string IT_temperature,
            std::string LT_temperature,
            std::string LU_temperature,
            std::string LV_temperature,
            std::string NL_temperature,
            std::string NO_temperature,
            std::string PL_temperature,
            std::string PT_temperature,
            std::string RO_temperature,
            std::string SE_temperature,
            std::string SI_temperature,
            std::string SK_temperature
        );

    private:
        static CandleStickRaw stringToCS(std::vector<std::string> strings);
    
};
