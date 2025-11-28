#include "CSVReader.h"
#include "Helper.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader() {

}

std::vector<CandleStickRaw> CSVReader::readCSV(std::string csvFilename) {

    std::vector<CandleStickRaw> entries;

    std::ifstream csvFile{csvFilename};
    std::string line;
    bool skipHeader = true;
    if (csvFile.is_open()) {

        while(std::getline(csvFile, line)) {
            if (skipHeader) {
                skipHeader = false;
                continue;
            }
            try {
                CandleStickRaw CS = stringToCS(tokenise(line, ','));
                entries.push_back(CS);
            } catch(const std::exception& e)
            {
                std::cout << "CSVReader::readCSV bad data" << std::endl;
            }
        }
    } else {
        std::cout << "Unable to read filename " + csvFilename << std::endl;
        return std::vector<CandleStickRaw>();
    }

    std::cout << "CSVReader::readCSV read " << entries.size() << " entries" << std::endl;
    return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator) {
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;
    start = csvLine.find_first_not_of(separator, 0);
    do {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) break;
        if (end >= 0) token = csvLine.substr(start, end - start);
        else token = csvLine.substr(start, csvLine.length() - start);
        tokens.push_back(token);
        start = end + 1;
    } while (end > 0);

    return tokens;
}

CandleStickRaw CSVReader::stringToCS(std::vector<std::string> tokens) {
    double AT_temperature, BE_temperature, BG_temperature, CH_temperature,
    CZ_temperature, DE_temperature, DK_temperature, EE_temperature, ES_temperature,
    FR_temperature, GB_temperature, GR_temperature, HR_temperature, HU_temperature,
    IE_temperature, IT_temperature, LT_temperature, LU_temperature, LV_temperature,
    NL_temperature, NO_tmeperature, PL_temperature, PT_temperature, RO_temperature,
    SE_temperature, SI_temperature, SK_temperature;

    if (tokens.size() != 29) {
        std::cout<< "Bad line " << std::endl;
        std::cout << tokens.size() << std::endl;
        throw std::exception();
    }

    if (!verifyTimestamp(tokens[0])) {
        std::cout << "CSVReader::stringToCS timestamp in bad format! " << tokens[0] << std::endl;
        throw;
    }

    double temperatures[28];
    int i = 1;
    try {
        while(i < 29) {
            temperatures[i - 1] = stod(tokens[i]);
            i++;
        }
    } catch(const std::exception& e) {
        std::cout << "CSVReader::stringsToCS Bad float! " << tokens[i]<< std::endl;
        throw;
    }

    CandleStickRaw CS{
        tokens[0].substr(0, 10),
        temperatures
    };
    return CS;
}