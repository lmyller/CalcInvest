#pragma once

#include <memory>
#include <vector>
#include <optional>
#include "Investimento.h"

/* Representa a carteira de investimentos do investidor.
     A carteira de investimentos é um grupo de ativos (propriedades ou itens de valor) que pertencem a um investidor.   
	 Estes ativos podem ser ações, CDB, fundos, títulos públicos, debêntures, etc. 
*/ 
class CarteiraInvestimentos
{
	private:
		// Carteira de investimentos do investidor.
		vector<Investimento*> investimentos;

	public:
		CarteiraInvestimentos();
		
		// Adiciona um investimento na carteira de investimentos do investidor.
		bool adicionarInvestimento(const Investimento* investimento);

		// Obtém um investimento da carteira de investimentos do investidor. Pesquisa pelo nome e retorna o investimento se encontrá-lo.
		Investimento* obterInvestimento(string nome);

		// Obtém um investimento da carteira de investimentos do investidor. Pesquisa pela posição e retorna o investimento se encontrá-lo.
		Investimento* obterInvestimento(unsigned& indice);

		// Obtém o número de investimentos que o investidor possui em sua carteira de investimentos.
		unsigned numeroInvestimentos();
};

