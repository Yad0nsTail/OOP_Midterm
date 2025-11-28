#pragma once

#include "CSVReader.h"
#include "CandleStick.h"

class CandleStickMain
{
    public:
        CandleStickMain();
        void init();

    private:
        static const int BLOCK_WIDTH = 12;

        void printMenu();
        void printHelp();
        void importFile();
        void printStats();
        void printTextGraph(std::vector<CandleStick> filteredData);
        void printTextGraphBlock(CandleStick& data, int top, int bottom);
        int getUserOption();
        void processUserOption(int userOption);
        void selectTimeFrame();

        std::vector<CandleStickRaw> rawdata;
        std::vector<CandleStick> data;
        std::vector<std::string> graph;
};