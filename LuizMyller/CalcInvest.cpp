#include <iostream>
#include <locale>
#include <iomanip>
#include <format>
#include <unordered_map>
#include <codecvt>
#include "Reader.h"
#include "Line.h"
#include "TextFile.h"
#include "Utils.h"
#include "CalcInvest.h"
#include "RendaFixa.h"
#include "RendaVariavel.h"

CalcInvest::CalcInvest(){}

int CalcInvest::calcInvest()
{
    locale::global(locale("pt_BR.utf8"));
    setlocale(LC_ALL, "pt-BR");

    importarInvestimentos("Investimentos.csv");
    exibirRelatorios();

    return EXIT_SUCCESS;
}

bool CalcInvest::importarInvestimentos(string nomeArquivo)
{
    char inicio = 0;
    vector<Line> lines = Reader::read(nomeArquivo, Reader::SEMICOLON);

    if (lines.size() == 0)
        return false;

    for (Line& line : lines) {
        if (inicio == 0)
        {
            inicio++;
            continue;
        }

        Investimento* investimento = criarInvestimento(line);
        carteiraInvestimentos.adicionarInvestimento(investimento);
    }

    return true;
}

// Cria um objeto investimento a partir da linha do arquivo no argumento "line"
Investimento* CalcInvest::criarInvestimento(Line& line)
{
    Investimento* investimento;
    string dataInvestimento = line.getData(7).value();
    string dataResgate = line.getData(8).value();
    unsigned prazo = Utils::diferencaDatas(dataInvestimento, dataResgate);

    if (line.getData(0).value() == "RV")
    {
        investimento = new RendaVariavel(line.getData(2).value());
        investimento->setImposto(Imposto(Imposto::TAXA_IR_15));
    }

    else
    {
        investimento = new RendaFixa(line.getData(2).value());
        investimento->setImposto(Imposto(Imposto::obterAliquota(prazo)));
    }

    investimento->setEstrategia(Estrategia::obterEstrategiaInvestimento(line.getData(1).value()));
    investimento->setRating(line.getData(3).value());
    investimento->setProtecaoFgc(line.getData(4).value() == "sim" ? true : false);
    investimento->setValorInvestido(stof(line.getData(5).value().c_str()));
    investimento->setTaxa(stof(line.getData(6).value().substr(0, line.getData(6).value().length() - 1)));
    investimento->setDataInvestimento(dataInvestimento);
    investimento->setDataResgate(dataResgate);
    investimento->setPrazo(prazo);

    return investimento;
}

void CalcInvest::exibirRelatorios()
{
    investimentosPorTipo();
    investimentosPorEstrategia();
}

bool CalcInvest::investimentosPorTipo()
{
    TextFile textFile;
    unordered_map<string, vector<Investimento*>> investimentosMap;
    unsigned char cont = 1;
   
    // Abre arquivo para escrita
    textFile.open("InvestimentosPorTipo.txt", AccessType::WRITING);

    for (unsigned indice = 0; indice < carteiraInvestimentos.numeroInvestimentos(); indice++)
    {
        Investimento *investimento = carteiraInvestimentos.obterInvestimento(indice);

        /* 
        *  Organiza os investimento em renda fixa e renda variável.
        *  O unordered_map armazena a chave que é o tipo do investimento e um vector contendo os investimentos do tipo da chave.
        */
        if (typeid(*investimento) == typeid(RendaFixa))
            investimentosMap["Renda Fixa"].push_back(investimento);

        else
            investimentosMap["Renda Variável"].push_back(investimento);
    }

    for (const auto& investimentoEstrategia : investimentosMap)
    {
        string tipo = investimentoEstrategia.first;

        string tipoString = format("{}. {}\n", cont++, tipo);

        // Converte a string para wstring
        textFile.write(Utils::stringToWstring(tipoString));

        for (Investimento* investimento : investimentoEstrategia.second)
        {
            // Escreve no arquivo o relatório por tipo do investimento
            textFile.write(Utils::stringToWstring(obterRelatorioPorTipo(investimento)));
        }
    }

    textFile.close();

    return true;
}

bool CalcInvest::investimentosPorEstrategia()
{
    TextFile textFile;
    unordered_map<string, vector<Investimento*>> investimentosMap;
    unsigned char cont = 1;

    // Abre arquivo para escrita
    textFile.open("InvestimentosPorEstrategia.txt", AccessType::WRITING);

    for (unsigned indice = 0; indice < carteiraInvestimentos.numeroInvestimentos(); indice++)
    {
        Investimento* investimento = carteiraInvestimentos.obterInvestimento(indice);

        /*
        *  Organiza os investimentos pela estratégia.
        *  O unordered_map armazena a chave que é a estratégia do investimento e um vector contendo os investimentos 
        *  do tipo da chave.
        */
        investimentosMap[Estrategia::tipoEstrategia(investimento->getEstrategia().getEstrategia())].push_back(investimento);
    }

    for (const auto& investimentoEstrategia : investimentosMap)
    {
        string estrategia = investimentoEstrategia.first;

        string estrategiaString = format("{}. Estratégia: {}\n", cont++, estrategia);

        // Converte a string para wstring
        textFile.write(Utils::stringToWstring(estrategiaString));

        for (Investimento* investimento : investimentoEstrategia.second)
        {
            // Escreve no arquivo o relatório por tipo do investimento
            textFile.write(Utils::stringToWstring(obterRelatorioPorEstrategia(investimento)));
        }
    }
    textFile.close();

    return true;
}

string CalcInvest::obterRelatorioPorTipo(Investimento* investimento)
{
    float valorInvestido = investimento->getValorInvestido();
    double valorBruto = investimento->calcularValorBruto();
    double rendimentoBruto = valorBruto - valorInvestido;
    double imposto = investimento->calcularIR();
    double rentabilidadeBruta = ((valorBruto / valorInvestido) - 1) * 100;
    double rentabilidadeLiquida = (((valorBruto - imposto) / valorInvestido) - 1) * 100;

    string relatorio = format(
        "- {}\n\n"
        "   Valor investido: R$ {:1.2f}\n"
        "   Taxa ao ano: {:1.2f}% a.a.\n"
        "   Taxa ao mês: {:1.2f}% a.m.\n"
        "   Data do investimento: {}\n"
        "   Data de resgate: {}\n"
        "   Valor bruto: R$ {:1.2f}\n"
        "   Valor líquido: R$ {:1.2f}\n"
        "   Alíquota de IR: {:1.2f}%\n"
        "   Valor do IR: R$ {:1.2f}\n"
        "   Rendimento bruto: R$ {:1.2f}\n"
        "   Rendimento líquido: R$ {:1.2f}\n"
        "   Rentabilidade bruta: {:1.2f}%\n"
        "   Rentabilidade líquida: {:1.2f}%\n",
        investimento->toString(),
        valorInvestido,
        investimento->getTaxa(),
        investimento->calcularTaxaMensal(),
        investimento->getDataInvestimento(),
        investimento->getDataResgate(),
        valorBruto,
        valorBruto - imposto,
        investimento->getImposto().getAliquota() * 100.0,
        imposto,
        rendimentoBruto,
        rendimentoBruto - imposto,
        rentabilidadeBruta,
        rentabilidadeLiquida
    );

    return relatorio;
}

string CalcInvest::obterRelatorioPorEstrategia(Investimento* investimento)
{
    float valorInvestido = investimento->getValorInvestido();
    double valorBruto = investimento->calcularValorBruto();
    double imposto = investimento->calcularIR();
    double rendimentoLiquido = (valorBruto - valorInvestido) - imposto;
    double rentabilidadeLiquida = (((valorBruto - imposto) / valorInvestido) - 1) * 100;

    string relatorio = format(
        " - {}\n\n"
        "    Valor investido       Valor bruto        Valor líquido       Rendimento líquido        Rentabilidade líquida\n"
        "    R$ {:9.2f}          R$ {:9.2f}       R$ {:9.2f}         R$ {:9.2f}              {:9.2f}%\n",
        investimento->getNome(),
        valorInvestido,
        valorBruto,
        valorBruto - imposto,
        rendimentoLiquido,
        rentabilidadeLiquida
    );

    return relatorio;
}

int main() 
{
    return CalcInvest().calcInvest();
}
