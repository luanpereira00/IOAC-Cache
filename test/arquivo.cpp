#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::getline;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <cstdlib>

#include "arquivo.h"

void abrirArquivo(ifstream *arquivo){
	string arq;
	//cout << "Digite o endereco do arquivo: ";
	//cin >> arq;
	arq = "dados.txt";

	arquivo->open(arq);
	if(!(*arquivo)){
		cerr << "Impossivel abrir o arquivo!" << endl;
		exit(1);
	}
	else{
		cout << "Arquivo aberto!" << endl;
	}

}

void loadData(Data* dados, ifstream* arquivo){
	string aux;

	getline(*arquivo, aux);
	dados->qtdPalavras = atoi(aux.c_str());

	getline(*arquivo, aux);
	dados->qtdLinhas = atoi(aux.c_str());

	getline(*arquivo, aux);
	dados->memPrincipal = atoi(aux.c_str());

	getline(*arquivo, aux);
	dados->mapeamento = atoi(aux.c_str());

	getline(*arquivo, aux);
	dados->vias = atoi(aux.c_str());

	getline(*arquivo, aux);
	dados->polSubstituicao = atoi(aux.c_str());

	getline(*arquivo, aux);
	dados->polEscrita = atoi(aux.c_str());
}