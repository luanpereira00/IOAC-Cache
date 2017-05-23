#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include "arquivo.h"

int main (){
	ifstream arquivo;
	struct Data dados;
	abrirArquivo(&arquivo);

	loadData(&dados, &arquivo);

	arquivo.close();

	cout << dados.qtdPalavras << endl;
	cout << dados.qtdLinhas << endl;
	cout << dados.memPrincipal << endl;
	cout << dados.mapeamento << endl;
	cout << dados.vias << endl;
	cout << dados.polSubstituicao << endl;
	cout << dados.polEscrita << endl;

	return 0;
}