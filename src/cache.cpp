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
	miss=0;
	hit=0;
	/** Faz nada */
}
Cache::~Cache(){
	delete[] vetor;
	/** Faz nada */
}

int Cache::getPalavras()			{ return qtdPalavras;		}
int Cache::getLinhas()				{ return qtdLinhas;			}
int Cache::getPrincipal()			{ return memPrincipal;		}
int Cache::getMapeamento()			{ return mapeamento;		}
int Cache::getVias()				{ return vias;				}
int Cache::getSubstituicao()		{ return polSubstituicao;	}
int Cache::getEscrita()				{ return polEscrita;		}
int Cache::getHit()					{ return hit;				}
int Cache::getMiss()				{ return miss;				}
int* Cache::getVetor()				{ return vetor;				}

void Cache::setPalavras(int p)		{ qtdPalavras = p; 		}
void Cache::setLinhas(int l)		{ qtdLinhas = l; 		}
void Cache::setPrincipal(int m)		{ memPrincipal = m; 	}
void Cache::setMapeamento(int mp)	{ mapeamento = mp; 		}
void Cache::setVias(int v)			{ vias = v; 			}
void Cache::setSubstituicao(int s)	{ polSubstituicao = s; 	}
void Cache::setEscrita(int e)		{ polEscrita = e; 		}
void Cache::setHit(int h)			{ hit = h;				}
void Cache::setMiss(int ms)			{ miss = ms;			}
void Cache::setVetor(int* vt)		{ vetor = vt; 			}


int Cache::memPalavras(){
	return getPalavras()*getPrincipal();
} 

int Cache::solicitarEndereco(){
	int end;
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

int Cache::calcBlocoPrincipal(int end){
	return ((end - (end % getPalavras()))/getPalavras());
}

void Cache::mainCache(){
	short int end=1;
	while(end>=0 and end<getPalavras()*getPrincipal()){ //MAX_ENDERECO_POSSIVEIS
		end = solicitarEndereco();
		if(end==-1) return;
		
		cout << "Bloco da principal: " << calcBlocoPrincipal(end) << endl;
		cout << "Mapeado no bloco " << mapeamentoCache(calcBlocoPrincipal(end)) << " da memoria cache" << endl;
	}
}
//Mapeamento (1 – Direto; 2 – Totalmente Associativo; 3 – Parcialmente Associativo)
int Cache::mapeamentoCache(int end){
	int mapeado=-1;
	if(1==getMapeamento()){
		cout << "Mapeamento Direto" << endl;
		int* v = getVetor();

		if(v[end % getLinhas()]==end) {
			cout << "\tHit" << endl;
			setHit(getHit()+1);
		}
		else {
			cout << "\tMiss" << endl;
			setMiss(getMiss()+1);
			v[end % getLinhas()]=end;
		}
		mapeado=end % getLinhas();

		for (int i=0; i<getLinhas(); i++) {
			if(v[i]==-1) cout << "_ ";
			else cout << v[i] << " ";
		}
		cout << endl;

		setVetor(v);
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
	return mapeado;
}

//Política de substituição (1 – Aleatório; 2 – FIFO; 3 – LFU; 4 – LRU)
int Cache::substituicaoCache(int end){
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
int Cache::viasCache(int end){

	if(getVias()>0){
		cout << "Vias" << endl;

		//Sem Politica de Substituicao

	} else {
		cerr << "Quantidade de vias nao reconhecidas! Abortando operacoes..." << endl;
		exit(1);
	}
	return 0;
}