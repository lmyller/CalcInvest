#include <format>
#include <iostream>
#include "RendaVariavel.h"

RendaVariavel::RendaVariavel()
{}

RendaVariavel::RendaVariavel(string nome) : Investimento(nome)
{}

string RendaVariavel::toString() const
{
	return format("{} Prazo: {}", Investimento::toString(), getPrazoString());
}

unsigned RendaVariavel::getPrazo() const
{
	unsigned prazo = Investimento::getPrazo();

	return prazo < 252 ? prazo : (prazo / 252) * 252;
}

// Retorna uma string com o prazo formatado
string RendaVariavel::getPrazoString() const
{
	unsigned prazo = Investimento::getPrazo();

	return prazo < 252 ? format("{} dias", prazo) : obterPrazoEmAnos(prazo);
}

double RendaVariavel::calcularIR()
{
	return Imposto::calcularIR(calcularValorBruto() - this->getValorInvestido(), 1000);
}

// Recebe o prazo e retorna uma string formatada contendo o prazo em anos ou em anos e meses
string RendaVariavel::obterPrazoEmAnos(unsigned prazo) const
{
	unsigned anos = prazo / 252;
	unsigned meses = (prazo % 252) * 12 / 252;

	return meses > 0 ? format("{} anos e {} meses", anos, meses) : format("{} anos", anos);
}
