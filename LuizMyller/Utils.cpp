#include <sstream>
#include <iostream>
#include <iomanip>
#include "Utils.h"

time_t Utils::converterData(const string& data)
{
    tm tm = {};
    istringstream ss(data);
    ss >> get_time(&tm, "%d/%m/%Y");
    return mktime(&tm);
}

unsigned Utils::diferencaDatas(const string& dataInicial, const string& dataFinal)
{
    time_t dataInicialTime = converterData(dataInicial);
    time_t dataFinalTime = converterData(dataFinal);

    double diferencaSegundos = difftime(dataFinalTime, dataInicialTime);
    double diferencaDias = diferencaSegundos / (60 * 60 * 24);
    
    return static_cast<unsigned>(diferencaDias * (252.0 / 365.0));
}

wstring Utils::stringToWstring(const string& string)
{
    return wstring(string.begin(), string.end());
}
