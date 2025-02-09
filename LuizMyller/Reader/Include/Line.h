#pragma once

#include <string>
#include <vector>
#include <optional>

using namespace std;

/*
   Esta classe representa uma linha do arquivo CSV (Comma Separated Values). 
   A linha do arquivo representa um conjunto de dados que consiste em um ou mais valores separados por v�rgula (,) ou ponto e v�rgula (;).
   Esta classe considera apenas os dados da linha, sem o caractere separador.
 */
class Line {
public:
	// Inicializa o conte�do da linha sem o caractere separador.
	Line(vector<string> line);

	/* Obt�m os dados da linha.
	   Retorna um vector com os dados da linha. A posi��o de cada dado nesse vector corresponde a sua posi��o na linha do arquivo CSV, 
	   ou seja, o primeiro campo da linha ocupa a posi��o zero do vector, o segundo campo ocupa a posi��o um e assim por diante.
	 */
	vector<string> getLine();

	/* Obt�m o dado segundo sua posi��o na linha. A posi��o do dado corresponde a sua posi��o na linha do arquivo CSV, 
	   ou seja, o primeiro campo da linha ocupa a posi��o zero, o segundo campo ocupa a posi��o um e assim por diante.
	   Se a posi��o for v�lida retorna o dado da linha na posi��o indicada, caso contr�rio, um optional vazio.
	 */
	optional<string> getData(size_t position);

	/* Obt�m o pr�ximo dado da linha. 
	   Se a linha n�o tem mais dados retorna um optional vazio.
	 */
	optional<string> next();

	// Informa se a linha tem mais dados. Returna true se a linha tem mais dados, se n�o, false.
	bool hasNext();

	// Obt�m a quantidade de dados da linha. Retorna o n�mero de dados da linha.
	size_t quantityOfData();

private:
	vector<string> line;
	size_t lineIndex = 0;
};

