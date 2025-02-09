#include "CarteiraInvestimentos.h"

CarteiraInvestimentos::CarteiraInvestimentos()
{}

bool CarteiraInvestimentos::adicionarInvestimento(const Investimento* investimento)
{
	investimentos.push_back(const_cast<Investimento*>(investimento));

	return true;
}

Investimento* CarteiraInvestimentos::obterInvestimento(string nome)
{
	if (investimentos.empty())
		return nullptr;

	for (const auto& investimento : investimentos)
		if (investimento->getNome().compare(nome) == 0)
			return investimento;

	return nullptr;
}

Investimento* CarteiraInvestimentos::obterInvestimento(unsigned& indice)
{
	if (investimentos.empty() || numeroInvestimentos() < indice)
		return nullptr;

	return investimentos[indice];
}

unsigned CarteiraInvestimentos::numeroInvestimentos()
{
	return investimentos.size();
}
