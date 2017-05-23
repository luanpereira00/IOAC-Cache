#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::getline;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;

#include "cache.h"



Cache::Cache(){
	/** Faz nada */
}
Cache::~Cache(){
	/** Faz nada */
}

unsigned short int Cache::getPalavras()			{ return qtdPalavras;		}
unsigned short int Cache::getLinhas()			{ return qtdLinhas;			}
unsigned short int Cache::getPrincipal()		{ return memPrincipal;		}
unsigned short int Cache::getMapeamento()		{ return mapeamento;		}
unsigned short int Cache::getVias()				{ return vias;				}
unsigned short int Cache::getSubstituicao()		{ return polSubstituicao;	}
unsigned short int Cache::getEscrita()			{ return polEscrita;		}

void Cache::setPalavras(unsigned short int p)		{ qtdPalavras = p; 		}
void Cache::setLinhas(unsigned short int l)			{ qtdLinhas = l; 		}
void Cache::setPrincipal(unsigned short int m)		{ memPrincipal = m; 	}
void Cache::setMapeamento(unsigned short int mp)	{ mapeamento = mp; 		}
void Cache::setVias(unsigned short int v)			{ vias = v; 			}
void Cache::setSubstituicao(unsigned short int s)	{ polSubstituicao = s; 	}
void Cache::setEscrita(unsigned short int e)		{ polEscrita = e; 		}


unsigned short int Cache::memPalavras(){
	return getPalavras()*getPrincipal();
} 

short int Cache::solicitarEndereco(){
	short int end;
	cout << endl << "--- Simulador de Cache ---" << endl;
	do{
		cout << "Enderecos validos: " << 0 << " - " << memPalavras()-1 << endl;
		cout << "Sair: -1" << endl;
		cout << "Digite a opcao: ";
		cin >> end;

		if((end<-1 or end >= memPalavras())){
			cerr << endl << "Endereco errado! Tente novamente..." << endl;
		}
	}while(end<-1 or end >= memPalavras());
	return end;
}

unsigned short int Cache::calcBlocoPrincipal(unsigned short int end){
	return ((end - (end % getPalavras()))/getPalavras());
}

void Cache::mainCache(){
	short int end=1;
	while(end>=0 and end<getPalavras()*getPrincipal()){ //MAX_ENDERECO_POSSIVEIS
		end = solicitarEndereco();
		cout << "Bloco da principal: " << calcBlocoPrincipal(end) << endl;

		cout << "Mapeado em: " << mapeamentoCache(calcBlocoPrincipal(end)) << endl;
	}
}
//Mapeamento (1 – Direto; 2 – Totalmente Associativo; 3 – Parcialmente Associativo)
unsigned short int Cache::mapeamentoCache(unsigned short int end){
	if(1==getMapeamento()){
		cout << "Mapeamento Direto" << endl;

		//Sem Politica de Substituicao

	} else if (2==getMapeamento()){
		cout << "Mapeamento Totalmente Associativo" << endl;
		cout << "Substituido em: " << substituicaoCache(end) << endl;
		//Com politica de substituicao

	} else if (3==getMapeamento()){
		cout << "Mapeamento Parcialmente Associativo" << endl;
		cout << "Substituido em: " << viasCache(end) << endl;
		//Com politica de substituicao

	} else {
		cerr << "Mapeamento nao reconhecido! Abortando operacoes..." << endl;
		exit(1);
	}
	return 0;
}

//Política de substituição (1 – Aleatório; 2 – FIFO; 3 – LFU; 4 – LRU)
unsigned short int Cache::substituicaoCache(unsigned short int end){
	if(1==getSubstituicao()){
		cout << "Substituicao Aleatoria" << endl;
		//Sem Politica de Substituicao

	} else if (2==getSubstituicao()){
		cout << "Substituicao FIFO" << endl;
		//Com politica de substituicao

	} else if (3==getSubstituicao()){
		cout << "Substituicao LFU" << endl;
		//Com politica de substituicao

	} else if (4==getSubstituicao()){
		cout << "Substituicao LRU" << endl;
		//Com politica de substituicao

	}else {
		cerr << "Politica de substituicao nao reconhecida! Abortando operacoes..." << endl;
		exit(1);
	}
	return 0;
}

//Num de conjuntos
unsigned short int Cache::viasCache(unsigned short int end){

	if(getVias()>0){
		cout << "Vias" << endl;

		//Sem Politica de Substituicao

	} else {
		cerr << "Quantidade de vias nao reconhecidas! Abortando operacoes..." << endl;
		exit(1);
	}
	return 0;
}