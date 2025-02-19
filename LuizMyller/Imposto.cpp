#include "Imposto.h"

Imposto::Imposto(double aliquota)
{
	this->aliquota = aliquota;
}

Imposto& Imposto::setAliquota(double aliquota)
{
	this->aliquota = aliquota;
	return *this;
}

double Imposto::getAliquota() const
{
	return this->aliquota;
}

double Imposto::calcularIR(double rendimentoBruto, unsigned prazo)
{
	if (prazo <= 180)
		return rendimentoBruto * Imposto::TAXA_IR_22_5;
	if (prazo >= 181 && prazo <= 360)
		return rendimentoBruto * Imposto::TAXA_IR_20;
	if (prazo >= 361 && prazo <= 720)
		return rendimentoBruto * Imposto::TAXA_IR_17_5;

	return rendimentoBruto * Imposto::TAXA_IR_15;
}

// Obtém a alíquota do IR a partir do prazo
double Imposto::obterAliquota(unsigned prazo)
{
	if (prazo <= 180)
		return Imposto::TAXA_IR_22_5;
	if (prazo >= 181 && prazo <= 360)
		return Imposto::TAXA_IR_20;
	if (prazo >= 361 && prazo <= 720)
		return Imposto::TAXA_IR_17_5;

	return Imposto::TAXA_IR_15;
}
