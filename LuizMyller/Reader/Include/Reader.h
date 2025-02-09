#pragma once

#include "Line.h"

/* Esta classe representa possui métodos para ler o conteúdo de um arquivo CSV (Comma Separated Values).
   A linha do arquivo representa um conjunto de dados que consiste em um ou mais valores separados por vírgula (,) ou ponto e vírgula (;).
 */
class Reader {
public:
	// Representa o caractere vírgula (',').
	static const char COMMA = ',';

	// Representa o caractere ponto e vírgula (';').
	static const char SEMICOLON = ';';

	Reader() = delete;

	/* Lê o nome do arquivo CSV assmindo que o caractere separador padrão em cada linha do arquivo é a vírgula (',').
	   Retorna um vector com o conteúdo de cada linha do arquivo. Se o arquivo não foi aberto retorna um vector de tamanho zero.
	 */
	static vector<Line> read(string fileName);

	/* Lê o nome do arquivo CSV considerando o caractere separador especificado.
	   O separatorChar representa o caractere separador usado no arquivo CSV. Os valores válidos são COMMA (',') e SEMICOLON (';'). 
	   Se for especificado um valor inválido ele será ignorado e o caractere separador padrão (COMMA (',')) será usado.
	   Retorna um vector com o conteúdo de cada linha do arquivo. Se o arquivo não foi aberto retorna um vector de tamanho zero.
	 */
	static vector<Line> read(string fileName, char separatorChar);
};

