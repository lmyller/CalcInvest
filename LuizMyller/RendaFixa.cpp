#include <format>
#include <iostream>
#include "RendaFixa.h"

RendaFixa::RendaFixa()
{}

RendaFixa::RendaFixa(string nome) : Investimento(nome)
{}

string RendaFixa::toString() const
{
    return format("{} Prazo: {}", Investimento::toString(), getPrazoString());
}

unsigned RendaFixa::getPrazo() const
{
    unsigned prazo = Investimento::getPrazo();

    return prazo < 252 ? (prazo * 12 / 252) : (prazo / 252);
}

double RendaFixa::calcularIR()
{
    return Imposto::calcularIR(calcularValorBruto() - this->getValorInvestido(), Investimento::getPrazo());
}

// Retorna uma string com o prazo formatado
string RendaFixa::getPrazoString() const
{
    unsigned prazo = Investimento::getPrazo();

    return prazo < 252 ? format("{} meses", (prazo * 12 / 252)) : obterPrazoEmAnos(prazo);
}

// Recebe o prazo e retorna uma string formatada contendo o prazo em anos ou em anos e meses
string RendaFixa::obterPrazoEmAnos(unsigned prazo) const
{
    unsigned anos = prazo / 252;
    unsigned meses = (prazo % 252) * 12 / 252;

    return meses > 0 ? format("{} anos e {} meses", anos, meses) : format("{} anos", anos);
}

