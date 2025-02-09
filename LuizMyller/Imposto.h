#pragma once

/*
	Representa o valor percentual com que o Imposto de Renda (IR) incide sobre o rendimento bruto de um investimento.
	Define as alíquotas de Imposto de Renda.
*/
class Imposto {
private:
	double aliquota; // Percentual com que o imposto incide sobre o rendimento bruto de um investimento.

public:
	// Taxa de 22.5% de IR a ser calculada sobre o rendimento bruto de um investimento de até 180 dias.
	inline static const double TAXA_IR_22_5 = 0.225;

	// Taxa de 20% de IR a ser calculada sobre o rendimento bruto de um investimento de 181 a 360 dias.
	inline static const double TAXA_IR_20 = 0.20;

	// Taxa de 17.5% de IR a ser calculada sobre o rendimento bruto de um investimento de 361 a 720 dias.
	inline static const double TAXA_IR_17_5 = 0.175;

	// Taxa de 15% de IR a ser calculada sobre o rendimento bruto de um investimento acima de 720 dias.
	inline static const double TAXA_IR_15 = 0.15;

	Imposto() = default;
	Imposto(double aliquota);

	Imposto& setAliquota(double aliquota);
	double getAliquota() const;

	// Calcula o valor do Imposto de Renda (IR) sobre o rendimento bruto do investimento de acordo com o seu prazo em dias.
	static double calcularIR(double rendimentoBruto, unsigned prazo);

	// Obtém a alíquota do IR a partir do prazo
	static double obterAliquota(unsigned prazo);
};
