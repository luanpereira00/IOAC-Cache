#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <fstream>
using std::ifstream;

struct Data{
	int qtdPalavras;
	int qtdLinhas;
	int memPrincipal;
	int mapeamento;
	int vias;
	int polSubstituicao;
	int polEscrita;
};

void abrirArquivo(ifstream *arquivo);

void loadData(struct Data* dados, ifstream *arquivo);

#endif
