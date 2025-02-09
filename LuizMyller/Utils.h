#pragma once

#include <ctime>
#include <string>

using namespace std;

class Utils
{
public:
	// Converte uma data de string para time_t
	static time_t converterData(const string& data);

	// Recebe a data inicial e a data final e retorna a diferença das duas datas em dias
	static unsigned diferencaDatas(const string& dataInicial, const string& dataFinal);

	// Converte uma string em wstring
	static wstring stringToWstring(const string& string);
};