#pragma once

#include <string>
#include <vector>
#include <optional>

using namespace std;

/*
   Esta classe representa uma linha do arquivo CSV (Comma Separated Values). 
   A linha do arquivo representa um conjunto de dados que consiste em um ou mais valores separados por vírgula (,) ou ponto e vírgula (;).
   Esta classe considera apenas os dados da linha, sem o caractere separador.
 */
class Line {
public:
	// Inicializa o conteúdo da linha sem o caractere separador.
	Line(vector<string> line);

	/* Obtém os dados da linha.
	   Retorna um vector com os dados da linha. A posição de cada dado nesse vector corresponde a sua posição na linha do arquivo CSV, 
	   ou seja, o primeiro campo da linha ocupa a posição zero do vector, o segundo campo ocupa a posição um e assim por diante.
	 */
	vector<string> getLine();

	/* Obtém o dado segundo sua posição na linha. A posição do dado corresponde a sua posição na linha do arquivo CSV, 
	   ou seja, o primeiro campo da linha ocupa a posição zero, o segundo campo ocupa a posição um e assim por diante.
	   Se a posição for válida retorna o dado da linha na posição indicada, caso contrário, um optional vazio.
	 */
	optional<string> getData(size_t position);

	/* Obtém o próximo dado da linha. 
	   Se a linha não tem mais dados retorna um optional vazio.
	 */
	optional<string> next();

	// Informa se a linha tem mais dados. Returna true se a linha tem mais dados, se não, false.
	bool hasNext();

	// Obtém a quantidade de dados da linha. Retorna o número de dados da linha.
	size_t quantityOfData();

private:
	vector<string> line;
	size_t lineIndex = 0;
};

