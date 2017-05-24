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

	cout << "Palavras por bloco: 	-> " << dados.getPalavras() << endl;
	cout << "Linhas da cache: 	-> " << dados.getLinhas() << endl;
	cout << "Blocos da principal: 	-> " << dados.getPrincipal() << endl;
	cout << "Mapeamento: 		-> " << dados.getMapeamento() << endl;
	cout << "Vias: 			-> " << dados.getVias() << endl;
	cout << "Substituicao: 		-> " << dados.getSubstituicao() << endl;
	cout << "Escrita: 		-> " << dados.getEscrita() << endl;

	int* v = new int[dados.getLinhas()];
	for(int i=0; i<dados.getLinhas(); i++) v[i]=-1;

	dados.setVetor(v);
	dados.mainCache();

	cout << "Hits:	-> " << dados.getHit() << endl;
	cout << "Miss: 	-> " << dados.getMiss() << endl;
	float porcentagem = (1.0*dados.getHit()/(1.0*dados.getHit()+1.0*dados.getMiss()));
	cout << "Porcentagem de acertos: " << porcentagem*100 << "%" << endl;



	cout << "Encerrando simulador..." << endl;
	return 0;
}