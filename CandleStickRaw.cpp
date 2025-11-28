#include "CandleStickRaw.h"

CandleStickRaw::CandleStickRaw (
    std::string _date,
    double temperatures[28]
)
:
date(_date) 
{
    AT_temperature = temperatures[0];
    BE_temperature = temperatures[1];
    BG_temperature = temperatures[2];
    CH_temperature = temperatures[3];
    CZ_temperature = temperatures[4];
    DE_temperature = temperatures[5];
    DK_temperature = temperatures[6];
    EE_temperature = temperatures[7];
    ES_temperature = temperatures[8];
    FI_temperature = temperatures[9];
    FR_temperature = temperatures[10];
    GB_temperature = temperatures[11];
    GR_temperature = temperatures[12];
    HR_temperature = temperatures[13];
    HU_temperature = temperatures[14];
    IE_temperature = temperatures[15];
    IT_temperature = temperatures[16];
    LT_temperature = temperatures[17];
    LU_temperature = temperatures[18];
    LV_temperature = temperatures[19];
    NL_temperature = temperatures[20];
    NO_temperature = temperatures[21];
    PL_temperature = temperatures[22];
    PT_temperature = temperatures[23];
    RO_temperature = temperatures[24];
    SE_temperature = temperatures[25];
    SI_temperature = temperatures[26];
    SK_temperature = temperatures[27];   
}

bool CandleStickRaw::operator<(const CandleStickRaw& other) const {
    return date < other.date;
}
std::string CandleStickRaw::toString() {
    return "Date: " +  date + ", AT_temperature:" + std::to_string(AT_temperature) + ", BE_temperature:" 
        + std::to_string(BE_temperature) + ", BG_temperature:" + std::to_string(BG_temperature) 
        + ", CH_temperature:" + std::to_string(CH_temperature) + ", CZ_temperature:" + std::to_string(CZ_temperature) 
        + ", DE_temperature:" + std::to_string(DE_temperature) + ", DK_temperature:" + std::to_string(DK_temperature) 
        + ", EE_temperature:" + std::to_string(EE_temperature) + ", ES_temperature:" + std::to_string(ES_temperature) 
        + ", FI_temperature:" + std::to_string(FI_temperature) + ", FR_temperature:" + std::to_string(FR_temperature) 
        + ", GB_temperature:" + std::to_string(GB_temperature) + ", GR_temperature:" + std::to_string(GR_temperature) 
        + ", HU_temperature:" + std::to_string(HU_temperature) + ", IE_temperature:" + std::to_string(IE_temperature)
        + ", IT_temperature:" + std::to_string(IT_temperature) + ", LT_temperature:" + std::to_string(LT_temperature)
        + ", LU_temperature:" + std::to_string(LU_temperature) + ", LV_temperature:" + std::to_string(LV_temperature)
        + ", NL_temperature:" + std::to_string(NL_temperature) + ", NO_temperature:" + std::to_string(NO_temperature)
        + ", PL_temperature:" + std::to_string(PL_temperature) + ", PT_temperature:" + std::to_string(PT_temperature)
        + ", RO_temperature:" + std::to_string(RO_temperature) + ", SE_temperature:" + std::to_string(SE_temperature)
        + ", SI_temperature:" + std::to_string(SI_temperature) + ", SK_temperature:" + std::to_string(SK_temperature);
}

bool CandleStickRaw::isWithinDateRange(std::string startingDate, std::string endingDate) {
    return date >= startingDate && date <= endingDate;
}

double CandleStickRaw::getTemperatureByCountry(std::string countryCode) {
    if (countryCode == "AT") {
        return AT_temperature;
    } else if (countryCode == "BE") {
        return BE_temperature;
    } else if (countryCode == "BG") {
        return BG_temperature;
    } else if (countryCode == "CH") {
        return CH_temperature;
    } else if (countryCode == "CZ") {
        return CZ_temperature;
    } else if (countryCode == "DE") {
        return DE_temperature;
    } else if (countryCode == "DK") {
        return DK_temperature;
    } else if (countryCode == "EE") {
        return EE_temperature;
    } else if (countryCode == "ES") {
        return ES_temperature;
    } else if (countryCode == "FI") {
        return FI_temperature;
    } else if (countryCode == "FR") {
        return FR_temperature;
    } else if (countryCode == "GB") {
        return GB_temperature;
    } else if (countryCode == "GR") {
        return GR_temperature;
    } else if (countryCode == "HU") {
        return HU_temperature;
    } else if (countryCode == "IE") {
        return IE_temperature;
    } else if (countryCode == "IT") {
        return IT_temperature;
    } else if (countryCode == "LT") {
        return LT_temperature;
    } else if (countryCode == "LU") {
        return LU_temperature;
    } else if (countryCode == "LV") {
        return LV_temperature;
    } else if (countryCode == "NL") {
        return NL_temperature;
    } else if (countryCode == "NO") {
        return NO_temperature;
    } else if (countryCode == "PL") {
        return PL_temperature;
    } else if (countryCode == "PT") {
        return PT_temperature;
    } else if (countryCode == "RO") {
        return RO_temperature;
    } else if (countryCode == "SE") {
        return SE_temperature;
    } else if (countryCode == "SI") {
        return SI_temperature;
    } else if (countryCode == "SK") {
        return SK_temperature;
    }

    return 0;
}