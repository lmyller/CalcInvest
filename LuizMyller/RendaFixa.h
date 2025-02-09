#pragma once

#include "Investimento.h"

class RendaFixa : public Investimento {
public:
	RendaFixa();
	RendaFixa(string nome);

	/* Retorna uma string que representa os dados do investimento. Usa o formato abaixo:

		<nome> | <rating> | <estratégia> | FGC: <sim | não> | Prazo: <X> anos [e <Y> meses] | [ <Y> meses]

	   O caractere pipe (|) entre os parênteses angulares (< >) significa ou, por exemplo: <sim | não> resulta em sim ou não.
       Os colchetes indicam uso opcional e que será usado no caso em que o período de investimento não representar um ano completo, por exemplo, 5 anos e 6 meses.
	   
       Exemplos:
					CDB Original Jan/2020 | BBB+ | Inflação | FGC: sim | Prazo: 3 anos e 4 meses
					CDB PAN Nov/2025 | BBB+ | Pós-fixado | FGC: sim | Prazo: 4 anos
					CRI WS | AA+ | Prefixado | FGC: não | Prazo: 11 meses

		Na renda fixa o prazo deve ser exibido em meses se o período de investimento for inferior a um ano (até 12 meses), caso contrário, em anos.
	*/
	virtual string toString() const;

	// Retorna o prazo em meses se o período de investimento for inferior a um ano (12 meses), caso contrário, em anos.
	virtual unsigned getPrazo() const;

	/* Calcula o valor do Imposto de Renda (IR) sobre o rendimento obtido no investimento. 
	   Investimentos de renda fixa possuem quatro alíquotas de IR definidas na classe Imposto de acordo com o prazo do investimento.
	*/ 
	virtual double calcularIR();

private:
	// Retorna uma string com o prazo formatado
	string getPrazoString() const;

	// Recebe o prazo e retorna uma string formatada contendo o prazo em anos ou em anos e meses
	string obterPrazoEmAnos(unsigned prazo) const;
};
