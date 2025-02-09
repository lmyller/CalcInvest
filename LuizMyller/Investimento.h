#pragma once

#include "Estrategia.h"
#include "Imposto.h"

using namespace std;

class Investimento {
public:
	Investimento();
	Investimento(string nome);

	Investimento& setNome(string nome);
	string getNome() const;

	Investimento& setRating(string rating);
	string getRating() const;

	Investimento& setProtecaoFgc(bool protecaoFgc);
	bool getProtecaoFgc() const;

	Investimento& setEstrategia(Estrategia estrategia);
	Estrategia getEstrategia() const;

	Investimento& setValorInvestido(float valorInvestido);
	float getValorInvestido() const;

	Investimento& setDataInvestimento(string dataInvestimento);
	string getDataInvestimento() const;

	Investimento& setDataResgate(string dataResgate);
	string getDataResgate() const;

	// Define o prazo em dias úteis.
	Investimento& setPrazo(unsigned prazo);

	// Retorna o prazo em dias úteis.
	virtual unsigned getPrazo() const;

	// Define a taxa percentual ao ano (a.a.).
	Investimento& setTaxa(float taxa);

	// Retorna a taxa percentual ao ano (a.a.).
	float getTaxa() const;

	// Define a alíquota do imposto de renda aplicada sobre o rendimento bruto de um investimento de acordo com o seu prazo em dias.
	Investimento& setImposto(Imposto imposto);

	// Obtém a alíquota do imposto de renda aplicada sobre o rendimento bruto de um investimento de acordo com o seu prazo em dias.
	Imposto getImposto() const;

	// Calcula a taxa ao mês do investimento
	double calcularTaxaMensal() const;

	// Calcula o valor bruto do investimento
	double calcularValorBruto() const;

	// Calcula o rendimento do investimento
	double calcularRendimento() const;

	/* Retorna uma string que representa os dados do investimento. Use o formato abaixo:

			<nome> | <rating> | <estratégia> | FGC: <sim | não>

		O caractere pipe (|) entre os parênteses angulares (< >) significa ou, por exemplo: <sim | não> resulta em sim ou não.
		Veja nos exemplos abaixo como os valores devem substituir as strings no formato acima representadas por <>.

	   Exemplos:
				  CDB Original Jan/2020 | BBB+ | Prefixado | FGC: sim
				  Ações da Vale | AA+ | Renda Variável | FGC: não
	*/

	virtual string toString() const;

	// Calcula o valor do Imposto de Renda (IR) sobre o rendimento obtido no investimento. 
	virtual double calcularIR() = 0;

private:
	string nome; // Nome do investimento, por exemplo, CDB, Tesouro Direto, LCI, LCA e Ações.

	/* O rating, ou classificação de risco, é a nota dada a uma empresa, um país, um título ou uma operação financeira para medir o risco de  crédito.  
	    Serve para indicar a capacidade de um país ou empresa de pagar suas dívidas e as chances de não conseguir, atrasando o pagamento ou dando calote. 
		Os investidores usam os “ratings” para tomarem decisões na hora de aplicar seu dinheiro. 
	   Valores válidos de rating, do menor risco, alto grau de investimento (AAA), para o maior risco, baixo grau de investimento (D).

	   Grau de investimento com qualidade alta e baixo risco: AAA, AA+, AA, AA-, A+, A, A-
	   Grau de investimento com qualidade baixa: BBB+, BBB, BBB-
	   Categoria de especulação, baixa classificação: BB+, BB, BB-, B+, B, B- 
	   Risco de inadimplência (calote) e baixo interesse: CCC+, CCC, CCC-, CC, C, D
	*/
	string rating;

	/* Indica se o investimento tem proteção do Fundo Garantidor de Créditos (FGC).  Os investimento que tem proteção do FGC são: Poupança, CDB, LCI, LCA e Letras de Câmbio (LC).
	
		true: tem proteção
		false: sem proteção
	*/
	bool protecaoFgc;

	// Indica o tipo de estratégia usada no Investimento. 
	Estrategia estrategia;

	// Valor investido no investimento.
	float valorInvestido;

	// Data em que o investimento foi realizado, ou seja, que o dinheiro foi investido.
	string dataInvestimento;

	// Data em que o dinheiro pode ser resgatado do investimento.
	string dataResgate;

	// Período em dias úteis do investimento. Representa a diferença entre as datas de resgate e investimento.
	unsigned prazo;

	/* Valor percentual usado para rentabilizar ou remunerar o valor investido. A taxa (juros) deve ser especificada ao ano (a.a.).
	     Na renda fixa a taxa do investimento é conhecida na data em que o dinheiro é investido, na renda variável a taxa só é conhecida  na data de resgate do investimento.
	*/
	float taxa;

	// Representa a alíquota do imposto de renda aplicada sobre o rendimento bruto de um investimento de acordo com o seu prazo em dias.
	Imposto imposto;
};
