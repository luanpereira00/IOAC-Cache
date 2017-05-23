#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include "arquivo.h"
#include "cache.h"

int main (){
	ifstream arquivo;
	Cache dados;
	abrirArquivo(&arquivo);

	loadData(&dados, &arquivo);

	arquivo.close();

	cout << dados.getPalavras() << endl;
	cout << dados.getLinhas() << endl;
	cout << dados.getPrincipal() << endl;
	cout << dados.getMapeamento() << endl;
	cout << dados.getVias() << endl;
	cout << dados.getSubstituicao() << endl;
	cout << dados.getEscrita() << endl;

	int* v = new int[dados.getLinhas()];
	for(int i=0; i<dados.getLinhas(); i++) v[i]=-1;

	dados.setVetor(v);
	dados.mainCache();

	cout << "Encerrando simulador..." << endl;
	return 0;
}