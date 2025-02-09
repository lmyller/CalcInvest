#pragma once

#include <string>

using namespace std;

enum class EstrategiaInvestimento { INFLACAO, PREFIXADO, POS_FIXADO, RENDA_VARIAVEL, INTERNACIONAL, MULTIMERCADO, ALTERNATIVO };

/*
	Define as estratégias dos diferentes tipos de investimento.
*/
class Estrategia {
public:
	Estrategia() = default;
	Estrategia(EstrategiaInvestimento estrategia);

	/* Obtém o tipo de estratégia de um investimento.  O valor resultante segundo uma das constantes definidas na enumeração Estrategia corresponde a uma string literal abaixo:
	   
	   "Inflação", "Prefixado", "Pós-fixado", "Renda Variável", "Internacional", "Multimercado" ou "Alternativo".
	*/
	static string tipoEstrategia(EstrategiaInvestimento estrategia);
	static EstrategiaInvestimento obterEstrategiaInvestimento(string estrategia);

	Estrategia& setEstrategia(EstrategiaInvestimento estrategia);
	EstrategiaInvestimento getEstrategia();

private:
	EstrategiaInvestimento estrategia;
};
