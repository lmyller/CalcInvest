#include <iostream>
#include <locale>
#include "TextFile.h"

// Fecha o arquivo texto antes do objeto ser removido da memória.
TextFile::~TextFile() 
{
	close();
}

// Obtém o nome do arquivo texto.
string TextFile::getFilename() 
{
	return filename;
}

/* Abre um arquivo texto identificado por fileName. O modo de abertura do arquivo deve ser especificado por uma das constantes de AccessType. Se o arquivo não existir ele será criado.
	 Se o modo for WRITING e o arquivo já existir em disco, todo o seu conteúdo será excluído. Retorna true se o arquivo foi aberto com sucesso ou false caso contrário.
*/
bool TextFile::open(string fileName, AccessType accessType) 
{
	this->filename = fileName;

	// Abre o arquivo segundo o tipo de acesso escolhido.
	switch (accessType) 
	{
		case AccessType::APPEND: outputFile.open(fileName, ios::app); return outputFile.is_open() ? true : false;
		case AccessType::WRITING: outputFile.open(fileName, ios::out); return outputFile.is_open() ? true : false;
		case AccessType::READING: inputFile.open(fileName, ios::in); return inputFile.is_open() ? true : false;
	}
	return false;
} 

/* Escreve no arquivo texto o conteúdo do objeto string usando a codificação UTF-8. A escrita sempre ocorre no fim do arquivo.
 	 Retorna true se a operação foi realizada com sucesso ou false caso contrário.
*/
bool TextFile::write(wstring conteudo) 
{
	return write(conteudo, UTF8);
} 

/* Escreve no arquivo texto o conteúdo do objeto string usando a codificação especificada, p. ex., ".1252". A escrita sempre ocorre no fim do arquivo.
	 Retorna true se a operação foi realizada com sucesso ou false caso contrário.
*/
bool TextFile::write(wstring conteudo, const string encoding)
{
	// Cria um objeto locale com a codificação especificada.
	const locale local(encoding);

	// Define o locale do arquivo.
	outputFile.imbue(local);

	// Verifica se o arquivo está aberto. 
	if (outputFile.is_open())
	{
		// Posiciona o ponteiro no fim do arquivo e escreve o conteúdo.
		outputFile.seekp(0, ios::end);
		outputFile << conteudo << endl;
		return true;
	}
	return false;
}

// Lê o conteúdo do arquivo texto usando a codificação UTF-8. Retorna uma string com todo o conteúdo do arquivo texto.
wstring TextFile::read() 
{
	return read(UTF8);
}


// Lê o conteúdo do arquivo texto usando a codificação especificada, p. ex., ".1252". Retorna uma string com todo o conteúdo do arquivo texto.
wstring TextFile::read(const string encoding) 
{
	wstring line;
	
	// Cria um objeto locale com a codificação especificada.
	const locale local(encoding);

	// Define o locale do arquivo.
	inputFile.imbue(local);

	// Lê o conteúdo do arquivo até atingir o fim do arquivo.
	do { 
				// Lê o conteúdo de uma linha do arquivo até encontrar o caractere nova linha ('\n'). 
				getline(inputFile, line);

				// Verifica se atingiu o fim do arquivo. Se não atingiu armazena a linha lida em um objeto string.
				if (!inputFile.eof()) 
				{
					text.append(line);
					text.append(NEW_LINE);
				}
	} while (!inputFile.eof());

   return text;
} 

/* Lê o conteúdo de uma linha do texto. A primeira linha de texto é de número zero (0). Retorna um objeto string com o conteúdo da linha de texto.

	 ATENÇÃO: Este método só irá recuperar a linha de texto correta do arquivo se todas as linhas possuírem o mesmo comprimento em bytes.
*/
wstring TextFile::read(int numberOfLine) 
{
	wstring line;

	// Lê o conteúdo do arquivo até atingir o fim do arquivo.
	if (numberOfLine >= 0) 
	{
		inputFile.seekg(numberOfLine);
		getline(inputFile, line);
	}
	return line;
} 

// Fecha o arquivo texto.
void TextFile::close() 
{
	// Verifica se o arquivo está aberto.
	if (inputFile.is_open()) inputFile.close();
	if (outputFile.is_open()) outputFile.close();

	// Apaga o conteúdo do texto.
	text.clear();
}