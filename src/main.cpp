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
	srand(time(NULL));
	ifstream arquivo;
	Cache dados;
	abrirArquivo(&arquivo);

	loadData(&dados, &arquivo);

	arquivo.close();
	cout << "===========================================" << endl;
	cout << "Palavras por bloco: 	-> " << dados.getPalavras() << endl;
	cout << "Linhas da cache: 	-> " << dados.getLinhas() << endl;
	cout << "Blocos da principal: 	-> " << dados.getPrincipal() << endl;
	cout << "Mapeamento: 		-> " << dados.getMapeamento() << endl;
	cout << "Vias: 			-> " << dados.getVias() << endl;
	cout << "Substituicao: 		-> " << dados.getSubstituicao() << endl;
	cout << "Escrita: 		-> " << dados.getEscrita() << endl;

	int* v = new int[dados.getLinhas()];
	int* f = new int[dados.getLinhas()];
	for(int i=0; i<dados.getLinhas(); i++) {
		v[i]=-1;
		f[i]=0;
	}
	dados.setVetor(v);
	dados.setFreq(f);

	dados.mainCache();
	cout << "===========================================" << endl;

	cout << "Hits:	-> " << dados.getHit() << endl;
	cout << "Miss: 	-> " << dados.getMiss() << endl;
	cout << "Total:  -> " << dados.getHit()+dados.getMiss() << endl;
	if(dados.getHit()+dados.getMiss()>0) {
		float porcentagem = (1.0*dados.getHit()/(1.0*dados.getHit()+1.0*dados.getMiss()));
		cout << "Porcentagem de acertos: " << porcentagem*100 << "%" << endl;
	}

	cout << "Encerrando simulador..." << endl;
	return 0;
}