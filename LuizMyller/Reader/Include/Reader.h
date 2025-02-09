#pragma once

#include "Line.h"

/* Esta classe representa possui m�todos para ler o conte�do de um arquivo CSV (Comma Separated Values).
   A linha do arquivo representa um conjunto de dados que consiste em um ou mais valores separados por v�rgula (,) ou ponto e v�rgula (;).
 */
class Reader {
public:
	// Representa o caractere v�rgula (',').
	static const char COMMA = ',';

	// Representa o caractere ponto e v�rgula (';').
	static const char SEMICOLON = ';';

	Reader() = delete;

	/* L� o nome do arquivo CSV assmindo que o caractere separador padr�o em cada linha do arquivo � a v�rgula (',').
	   Retorna um vector com o conte�do de cada linha do arquivo. Se o arquivo n�o foi aberto retorna um vector de tamanho zero.
	 */
	static vector<Line> read(string fileName);

	/* L� o nome do arquivo CSV considerando o caractere separador especificado.
	   O separatorChar representa o caractere separador usado no arquivo CSV. Os valores v�lidos s�o COMMA (',') e SEMICOLON (';'). 
	   Se for especificado um valor inv�lido ele ser� ignorado e o caractere separador padr�o (COMMA (',')) ser� usado.
	   Retorna um vector com o conte�do de cada linha do arquivo. Se o arquivo n�o foi aberto retorna um vector de tamanho zero.
	 */
	static vector<Line> read(string fileName, char separatorChar);
};

