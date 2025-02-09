#pragma once

#include <fstream>
#include <string>

using namespace std;

/* Define os tipos de acesso que podem ser usados para acessar o arquivo. Os modos disponíveis são:

   APPEND: abre o arquivo apenas para acrescentar dados no fim do arquivo;
   WRITING: abre o arquivo apenas para a escrita de dados;
   READING: abre o arquivo apenas para a leitura de dados.
*/
enum class AccessType { APPEND, WRITING, READING };

/*
	Esta classe fornece os métodos básicos para manipular um arquivo texto.
*/
class TextFile {
public: 
	// A letra L maiúscula é usada para definir uma string literal do tipo wstring.
	inline static const wstring NEW_LINE = L"\n";

	// Codificação de caracteres UTF-8.
	inline static const string UTF8 = ".UTF8";

	// Codificação de caracteres "pt-BR".
	inline static const string PORTUGUES_BRASIL = "pt-BR";

	TextFile() = default;

	// Fecha o arquivo texto antes do objeto ser removido da memória.
	virtual ~TextFile();

	// Obtém o nome do arquivo texto.
	string getFilename();

	/* Abre um arquivo texto identificado por fileName. O modo de abertura do arquivo deve ser especificado por uma das constantes de AccessType. Se o arquivo não existir ele será criado. 
	     Se o modo for WRITING e o arquivo já existir em disco, todo o seu conteúdo será excluído. Retorna true se o arquivo foi aberto com sucesso ou false caso contrário.
	 */
	bool open(string fileName, AccessType accessType);

	/* Escreve no arquivo texto o conteúdo do objeto string usando a codificação UTF-8. A escrita sempre ocorre no fim do arquivo.
        Retorna true se a operação foi realizada com sucesso ou false caso contrário.
     */
	bool write(wstring text);

	/* Escreve no arquivo texto o conteúdo do objeto string usando a codificação especificada, p. ex., ".1252". A escrita sempre ocorre no fim do arquivo.
	     Retorna true se a operação foi realizada com sucesso ou false caso contrário.
	 */
	bool write(wstring text, const string encoding);

	// Lê o conteúdo do arquivo texto usando a codificação UTF-8. Retorna uma string com todo o conteúdo do arquivo texto.
	wstring read();

	// Lê o conteúdo do arquivo texto usando a codificação especificada, p. ex., ".1252". Retorna uma string com todo o conteúdo do arquivo texto.
	wstring read(const string encoding);

	/* Lê o conteúdo de uma linha do texto. A primeira linha de texto é de número zero (0). Retorna um objeto string com o conteúdo da linha de texto.
	  
	     ATENÇÃO: Este método só irá recuperar a linha de texto correta do arquivo se todas as linhas possuírem o mesmo comprimento em bytes.
	 */
	wstring read(int numberOfLine);

	// Fecha o arquivo texto.
	void close();

private:
	string filename;
	wstring text;

	// Objeto para ler caracteres de 2 bytes (wchar_t), tamanho usado no UTF-16.
	wifstream inputFile;  

	// Objeto para escrever caracteres de 2 bytes (wchar_t), tamanho usado no UTF-16. 
	wofstream outputFile;
}; 
