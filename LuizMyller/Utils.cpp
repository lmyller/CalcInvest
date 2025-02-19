#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
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
	// Obtém o tamanho da string.
	const size_t STRING_SIZE = string.size() + 1;

	// Aloca memória (buffer) para a wstring. 
	wchar_t* ptrwstring = new wchar_t[STRING_SIZE];

	// Número de caracteres a serem convertidos.
	size_t stringSize;

	// Converte a string em uma wstring e armazena no buffer apontado por ptrwstring.  Subtrai 1 para descartar o terminador nulo '\0'.
	mbstowcs_s(&stringSize, ptrwstring, STRING_SIZE, string.c_str(), STRING_SIZE - 1);

	// Copia o número de caracteres convertidos para a wstring.
	wstring widestring(ptrwstring, stringSize);

	// Remove a memória criada para a wstring.
	delete[] ptrwstring;

	return widestring;
}

// Função que remove caracteres nulos de uma string
wstring Utils::removeNulls(const wstring& string)
{
    std::wstring stringSemNull;

    for (wchar_t caractere : string)
    {
        if (caractere != L'\0')
        {
            stringSemNull += caractere;
        }
    }
    return stringSemNull;
}