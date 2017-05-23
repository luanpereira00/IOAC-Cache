#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::getline;
using std::endl;

#include <string>
using std::string;

#include "cache.h"

int Cache::getPalavras(){
	return qtdPalavras;
}
int Cache::getLinhas(){
	return qtdLinhas;
}
int Cache::getPrincipal(){
	return memPrincipal;
}
int Cache::getMapeamento(){
	return mapeamento;
}
int Cache::getVias(){
	return vias;
}
int Cache::getSubstituicao(){
	return polSubstituicao;
}
int Cache::getEscrita(){
	return polEscrita;
}

void Cache::setPalavras(int p){ 
	qtdPalavras = p; 
}
void Cache::setLinhas(int l){ 
	qtdLinhas = l; 
}
void Cache::setPrincipal(int m){ 
	memPrincipal = m; 
}
void Cache::setMapeamento(int mp){ 
	mapeamento = mp; 
}
void Cache::setVias(int v){ 
	vias = v; 
}
void Cache::setSubstituicao(int s){ 
	polSubstituicao = s; 	
}
void Cache::setEscrita(int e){ 
	polEscrita = e; 
}


int Cache::solicitarEndereco(){
	int end;
	cout << "Digite o endereco a ser buscado: ";
	cin >> end;
	return end;
}

void Cache::initCache(){
	int end;
	while(end>0){ //MAX_ENDERECO_POSSIVEIS
		end = solicitarEndereco();
	}
}