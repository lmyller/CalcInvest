#include "Estrategia.h"

Estrategia::Estrategia(EstrategiaInvestimento estrategia) : estrategia(estrategia)
{}

string Estrategia::tipoEstrategia(EstrategiaInvestimento estrategia)
{
	switch (estrategia)
	{
	case EstrategiaInvestimento::INFLACAO: return "Inflação";
	case EstrategiaInvestimento::PREFIXADO: return "Prefixado";
	case EstrategiaInvestimento::POS_FIXADO: return "Pós-fixado";
	case EstrategiaInvestimento::RENDA_VARIAVEL: return "Renda Variável";
	case EstrategiaInvestimento::INTERNACIONAL: return "Internacional";
	case EstrategiaInvestimento::MULTIMERCADO: return "Multimercado";
	case EstrategiaInvestimento::ALTERNATIVO: return "Alternativo";
	}

	return "";
}

EstrategiaInvestimento Estrategia::obterEstrategiaInvestimento(string estrategia)
{
	if (estrategia == "Inflação")
		return EstrategiaInvestimento::INFLACAO;
	if (estrategia == "Prefixado")
		return EstrategiaInvestimento::PREFIXADO;
	if (estrategia == "Pós-fixado")
		return EstrategiaInvestimento::POS_FIXADO;
	if (estrategia == "Renda Variável")
		return EstrategiaInvestimento::RENDA_VARIAVEL;
	if (estrategia == "Internacional")
		return EstrategiaInvestimento::INTERNACIONAL;
	if (estrategia == "Multimercado")
		return EstrategiaInvestimento::MULTIMERCADO;
	
	return EstrategiaInvestimento::ALTERNATIVO;
}

Estrategia& Estrategia::setEstrategia(EstrategiaInvestimento estrategia)
{
	this->estrategia = estrategia;
	return *this;
}

EstrategiaInvestimento Estrategia::getEstrategia()
{
	return this->estrategia;
}
