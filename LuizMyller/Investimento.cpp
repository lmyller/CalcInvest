#include <format>
#include <cmath>
#include <iostream>
#include "Investimento.h"

Investimento::Investimento(): Investimento(""){}

Investimento::Investimento(string nome) : nome(nome)
{
	this->rating = "";
	this->protecaoFgc = "";
	this->estrategia = Estrategia();
	this->valorInvestido = 0.0f;
	this->dataInvestimento = "";
	this->dataResgate = "";
	this->prazo = 0;
	this->taxa = 0.0f;
	this->imposto = Imposto();
}

Investimento& Investimento::setNome(string nome)
{
	this->nome = nome;
	return *this;
}

string Investimento::getNome() const
{
	return this->nome;
}

Investimento& Investimento::setRating(string rating)
{
	this->rating = rating;
	return *this;
}

string Investimento::getRating() const
{
	return this->rating;
}

Investimento& Investimento::setProtecaoFgc(bool protecaoFgc)
{
	this->protecaoFgc = protecaoFgc;
	return *this;
}

bool Investimento::getProtecaoFgc() const
{
	return this->protecaoFgc;
}

Investimento& Investimento::setEstrategia(Estrategia estrategia)
{
	this->estrategia = estrategia;
	return *this;
}

Estrategia Investimento::getEstrategia() const
{
	return this->estrategia;
}

Investimento& Investimento::setValorInvestido(float valorInvestido)
{
	this->valorInvestido = valorInvestido;
	return *this;
}

float Investimento::getValorInvestido() const
{
	return this->valorInvestido;
}

Investimento& Investimento::setDataInvestimento(string dataInvestimento)
{
	this->dataInvestimento = dataInvestimento;
	return *this;
}

string Investimento::getDataInvestimento() const
{
	return this->dataInvestimento;
}

Investimento& Investimento::setDataResgate(string dataResgate)
{
	this->dataResgate = dataResgate;
	return *this;
}

string Investimento::getDataResgate() const
{
	return this->dataResgate;
}

Investimento& Investimento::setPrazo(unsigned prazo)
{
	this->prazo = prazo;
	return *this;
}

unsigned Investimento::getPrazo() const
{
	return this->prazo;
}

Investimento& Investimento::setTaxa(float taxa)
{
	this->taxa = taxa;
	return *this;
}

float Investimento::getTaxa() const
{
	return this->taxa;
}

Investimento& Investimento::setImposto(Imposto imposto)
{
	this->imposto = imposto;
	return *this;
}

Imposto Investimento::getImposto() const
{
	return this->imposto;
}

string Investimento::toString() const
{
	return format("{} | {} | {} | {} |", this->getNome(), this->getRating(), Estrategia::tipoEstrategia(this->getEstrategia().getEstrategia()), this->getProtecaoFgc() == true ? "sim" : "não");
}

// Calcula o valor bruto do investimento
double Investimento::calcularValorBruto() const
{
	/*
	* Investimento::getPrazo() * static_cast<float>(12) / 252 converte o prazo para deixar em meses para o cálculo do valor bruto
	*/
	return valorInvestido * pow(1 + (calcularTaxaMensal() / 100.0), Investimento::getPrazo() * static_cast<float>(12) / 252);
}

// Calcula a taxa ao mês do investimento
double Investimento::calcularTaxaMensal() const
{
	return ((pow(1 + (this->taxa / 100.0), 1.0 / 12.0)) - 1.0) * 100.0;
}

// Calcula o rendimento do investimento
double Investimento::calcularRendimento() const
{
	return calcularValorBruto() - this->valorInvestido;
}
