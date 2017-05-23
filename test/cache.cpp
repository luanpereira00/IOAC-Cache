#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::getline;
using std::endl;

#include <string>
using std::string;

#include "cache.h"

Cache::Cache(){
	/** Faz nada */
}
Cache::~Cache(){
	/** Faz nada */
}

unsigned short int Cache::getPalavras()	{ return qtdPalavras;	}
unsigned short int Cache::getLinhas()		{ return qtdLinhas;		}
unsigned short int Cache::getPrincipal()	{ return memPrincipal;	}
unsigned short int Cache::getMapeamento()	{ return mapeamento;	}
unsigned short int Cache::getVias()		{ return vias;			}
unsigned short int Cache::getSubstituicao(){ return polSubstituicao;}
unsigned short int Cache::getEscrita()		{ return polEscrita;	}

void Cache::setPalavras(unsigned short int p)		{ qtdPalavras = p; 	}
void Cache::setLinhas(unsigned short int l)		{ qtdLinhas = l; 	}
void Cache::setPrincipal(unsigned short int m)		{ memPrincipal = m; }
void Cache::setMapeamento(unsigned short int mp)	{ mapeamento = mp; 	}
void Cache::setVias(unsigned short int v)			{ vias = v; 		}
void Cache::setSubstituicao(unsigned short int s)	{ polSubstituicao = s; }
void Cache::setEscrita(unsigned short int e)		{ polEscrita = e; 	}


short int Cache::solicitarEndereco(){
	short int end;
	cout << endl << "--- Simulador de Cache ---" << endl;
	do{
		cout << "Enderecos validos: " << 0 << " - " << getPalavras()*getPrincipal()-1 << endl;
		cout << "Sair: -1" << endl;
		cout << "Digite a opcao: ";
		cin >> end;

		if((end<-1 or end >= getPalavras()*getPrincipal())){
			cerr << "Endereco errado! Tente novamente..." << endl;
		}
	}while(end<-1 or end >= getPalavras()*getPrincipal());
	return end;
}

void Cache::mainCache(){
	short int end=1;
	while(end>=0 and end<getPalavras()*getPrincipal()){ //MAX_ENDERECO_POSSIVEIS
		end = solicitarEndereco();
	}
}