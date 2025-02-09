#pragma once

#include "CarteiraInvestimentos.h"

/*
     Inicia o programa, realiza a importação e exibe o relatório.
*/ 
class CalcInvest
{
    public:
        CalcInvest();

        /* Inicia o programa acionando os serviços de importação de investimentos e geração dos relatório.
            Retorna EXIT_SUCESS se o programa executou com sucesso ou EXIT_FAILURE se ocorreu algum erro na importação dos investimentos ou geração dos relatórios.
        */
        int calcInvest();

    private:
        // Representa a carteira de investimentos do investidor.
        CarteiraInvestimentos carteiraInvestimentos;

       // Realiza a importação dos investimentos armazenados no arquivo csv. Retorna true se a importação foi realizada com sucesso ou false se ocorreu algum erro na importação.
       bool importarInvestimentos(string nomeArquivo);

       Investimento* criarInvestimento(Line& line);

        // Exibe os dois tipos de relatórios: investimentos por tipo (renda fixa e renda variável) e investimentos por estratégia.
       void exibirRelatorios();

       // Gera o relatório de investimentos organizados por tipo (renda fixa e renda variável). Retorna true se o relatório foi gerado com sucesso ou false se ocorreu algum erro.
       bool investimentosPorTipo();

       // Gera o relatório de investimentos organizados por estratégia. Retorna true se o relatório foi gerado com sucesso ou false se ocorreu algum erro.
       bool investimentosPorEstrategia();

       // Obtém o investimento e retorna uma string contendo o relatorio de um investimento
       string obterRelatorioPorTipo(Investimento* investimento);
       
       // Obtém o investimento e retorna uma string contendo o relatorio de um investimento
       string obterRelatorioPorEstrategia(Investimento* investimento);
};

