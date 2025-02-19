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

	/* Remove caracteres nulos de uma string, isto é necessário para a correta exibição de arquivos texto no notepad++ gerado por wstring, onde pode
	 * ocorrer a exibição de caracteres nulos. Isto faz com que seja exibido "NUL" no notepad++.
	 */
	static wstring removeNulls(const wstring& string);
};