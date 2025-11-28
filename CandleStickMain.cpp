#include "CandleStickMain.h"
#include "CSVReader.h"
#include "Helper.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>

CandleStickMain::CandleStickMain() {

}

void CandleStickMain::init() {
    int input;

    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void CandleStickMain::printMenu() {

    std::cout << "1. Print help" << std::endl;
    std::cout << "2. Import file" << std::endl;
    std::cout << "3. Print statistics" << std::endl;
}

void CandleStickMain::printHelp() {
    std::cout << "Help you analyse the temperature" << std::endl;
}

void CandleStickMain::importFile() {
    std::string fileName;
    std::cout << "Input csv file name" << std::endl;
    std::getline(std::cin, fileName);
    rawdata = CSVReader::readCSV(fileName);
    sort(rawdata.begin(), rawdata.end());

    data.clear();

    std::string currentDate{""};
    std::string curCountryCode{""};
    std::string extractedDate{""};
    double curCount = 0, closeTotal = 0, open = 0, low, high, curTemp;
    for (int z = 0; z < COUNTRY_CODE_NUM; z++) {
        currentDate = "";
        curCountryCode = countryCodeArr[z];
        curCount = 0;
        closeTotal = 0;
        open = 0;
        for (int i = 0; i < rawdata.size(); i++) {
            extractedDate = rawdata[i].date.substr(0, 10);
            curTemp = rawdata[i].getTemperatureByCountry(curCountryCode);
            if (currentDate.length() == 0) {
                currentDate = extractedDate;
                closeTotal = curTemp;
                curCount = 1;
                low = curTemp;
                high = curTemp;
                continue;
            }

            if(currentDate != extractedDate) {
                data.emplace_back(currentDate, curCountryCode, open, high, low, closeTotal / curCount);
                open = closeTotal / curCount;
                closeTotal = curTemp;
                curCount = 1;
                high = curTemp;
                low = curTemp;
                currentDate = extractedDate;
            } else {
                high = std::max(high, curTemp);
                low = std::min(low, curTemp);
                closeTotal += curTemp;
                curCount += 1;
            }
        }
        data.emplace_back(currentDate, curCountryCode, open, high, low, closeTotal / curCount);
    }

    // for (int i = 0; i < std::min((int) data.size(), 5); i++) {
    //     std::cout << data[i].toString() << std::endl;
    // }
}

void CandleStickMain::printStats() {
    std::string startingDate, endingDate, countryCode;
    do {
        std::cout << "Please input starting date in YYYY-MM-DD"<< std::endl;
        std::getline(std::cin, startingDate);
    } while(!verifyDate(startingDate));

    do {
        std::cout << "Please input ending time date in YYYY-MM-DD"<< std::endl;
        std::getline(std::cin, endingDate);
    } while(!verifyDate(endingDate));

    do {
        std::cout << "Please input valid two character country code in upper case, eg: FR"<< std::endl;
        std::getline(std::cin, countryCode);
    } while(!verifyCountrycode(countryCode));

    std::vector<CandleStick> filteredData{};

    for (int i = 0; i < data.size(); i++) {
        if (data[i].isWithinDateRange(startingDate, endingDate) && data[i].countryCode == countryCode) {
            filteredData.push_back(data[i]);
        }
    }

    printTextGraph(filteredData);
}

void CandleStickMain::printTextGraph(std::vector<CandleStick> filteredData) {
/*

   |        
  ■■■
   |

19800101
h:
o:
c:
l:
*/
    double lowest = 9999999, highest = -9999999;
    // std::cout << "filteredData: " << std::endl;
    for (int i = 0; i < filteredData.size(); i++) {
        // std::cout << filteredData[i].toString() << std::endl;
        lowest = std::min(lowest, filteredData[i].low);
        highest = std::max(highest, filteredData[i].high);
    }

    // These two variables determine the height of the graph
    // 1 degree = 1 line
    lowest = std::round(lowest - 3);
    highest = std::round(highest + 3);

    graph.clear();
    for (int i = lowest; i < highest + 6; i++) {
        graph.push_back("");
    }

    for (int i = 0; i < filteredData.size(); i++) {
        printTextGraphBlock(filteredData[i], highest, lowest);
    }

    for(int i = lowest; i < highest + 6; i++ ) {
        std::cout << graph[i - lowest] << std::endl;
    }
}

void CandleStickMain::printTextGraphBlock(CandleStick& data, int top, int bottom) {
    
    int graphHeight = top - bottom;
    std::vector<std::string> tmp;
    for (int i = 0; i < graphHeight+6; i++) {
        std::string tmpStr = "";
        for (int z = 0; z < BLOCK_WIDTH + 1; z++) {
            tmpStr = tmpStr + " ";
        }
        tmp.push_back(tmpStr);
    }

    tmp[graphHeight + 1] = " " + data.date + " |";

/*
     |  <- highRow (row where the vertical bar starts, relative to top row (row 0))
     |
    ■■■ <- startRow (row where block starts)
    ■■■
    ■■■ <- endRow (row where block ends)
     |
     | <- lowRow (row where vertical bar ends)
*/

    int highRow, startRow, endRow, lowRow;
    highRow = top - std::round(data.high);
    startRow = top - std::round(std::max(data.open, data.close));
    endRow = top - std::round(std::min(data.open, data.close));
    lowRow = top - std::round(data.low);

    // To guarantee at least one block gets printed
    bool blockNotPrinted = true;
    for (int i = highRow; i < lowRow; i++) {
        if(i < startRow) {
            tmp[i] = "      |      ";
        } else if (i < endRow || blockNotPrinted) {
            tmp[i] = "     ■■■     ";
            blockNotPrinted = false;
        } else if (i <= lowRow) {
            tmp[i] = "      |      ";
        }
    }

    // print high, open, close, low
    char buf[14];
    snprintf(buf, 14, "  h:%#.5g   |", data.high);
    std::string highText{buf};
    tmp[graphHeight + 2] = highText;

    snprintf(buf, 14, "  o:%#.5g   |", data.open);
    std::string openText{buf};
    tmp[graphHeight + 3] = openText;

    snprintf(buf, 14, "  c:%#.5g   |", data.close);
    std::string closeText{buf};
    tmp[graphHeight + 4] = closeText;

    snprintf(buf, 14, "  l:%#.5g   |", data.low);
    std::string lowText{buf};
    tmp[graphHeight + 5] = lowText;

    // aaaaaaaaaaaa
    //  2023-09-11 
    //  h:         

    for(int i = 0; i < graphHeight + 6; i++) {
        graph[i] = graph[i] + tmp[i];
    }
}

int CandleStickMain::getUserOption() {
    int userOption = 0;
    std::string line;
    std::cout <<"Type 1~3" << std::endl;
    std::getline(std::cin, line);
    try {
        userOption = std::stoi(line);
    } catch(const std::exception& e)
    {

    }
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
} 

void CandleStickMain::processUserOption(int userOption)
{
    if (userOption == 0)
    {
        std::cout << "invalid option. Choose 1~3" << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        importFile();
    }
    if (userOption == 3)
    {
        printStats();
    }
}