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
int* Cache::getFreq()				{ return freq;				}
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
void Cache::setFreq(int* fr)		{ freq = fr; 			}
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
		cout << "Buscando " << end;
		if(v[end % getLinhas()]==end) {
			cout << " -> Hit" << endl;
			setHit(getHit()+1);
		}
		else {
			cout << " -> Miss" << endl;
			setMiss(getMiss()+1);
			v[end % getLinhas()]=end;
		}
		mapeado = end % getLinhas();

		for (int i=0; i<getLinhas(); i++) {
			if(v[i]==-1) cout << "_ ";
			else cout << v[i] << " ";
		}
		cout << endl;

		setVetor(v);
		//Sem Politica de Substituicao

	} else if (2==getMapeamento()){
		cout << "Mapeamento Totalmente Associativo" << endl;
		mapeado = substituicaoCache(end);
		int* v = getVetor();
		for (int i=0; i<getLinhas(); i++) {
			if(v[i]==-1) cout << "_ ";
			else cout << v[i] << " ";
		}
		cout << endl;

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
	//cout << "Substituicao FIFO" << endl;
	//Comum a todos
	cout << "Buscando " << end;
	int* v = getVetor();
	int* f = getFreq();
	bool freeFlag=false;
	int aux=-1;

	for(int i=0; i<getLinhas(); i++){
		if(v[i]==end){
			cout << " -> Hit" << endl;
			setHit(getHit()+1);
			if(3==getSubstituicao()){
				f[i]++;
				setFreq(f);
			}
			return i;
		}
		if(!freeFlag and v[i]==-1) {
			freeFlag=true;
			aux=i;
		}
	}
	cout << " -> Miss" << endl;
	setMiss(getMiss()+1);
	if(freeFlag) {
		v[aux]=end;
		setVetor(v);
		if(2==getSubstituicao()){
			f[aux]=getLinhas();
			for (int i=0; i<getLinhas(); i++) {
				f[i]--;
			}
			setFreq(f);
		}
		if(3==getSubstituicao()){
			f[aux]++;
			setFreq(f);
		}	
		return aux;
	} 
	else {
		if(1==getSubstituicao()){
			//RANDOM
			aux = rand() % getLinhas();
			v[aux]=end;
			setVetor(v);
			return aux;		
			//Com Politica de Escrita
		} else if (2==getSubstituicao()){
			//FIFO		
			aux=f[0];
			int auxI=0;
			for(int i=1; i<getLinhas(); i++){
				if(f[i]<aux) {
					aux=f[i];
					auxI=i;
				}
			}
			v[auxI]=end;
			f[auxI]=getLinhas();
			cout << "Ordem de entrada: ";
			for (int i=0; i<getLinhas(); i++) {
				f[i]--;
				cout << f[i] << " ";
			}
			cout << endl;
			setVetor(v);
			setFreq(f);
			return auxI;
			//Com politica de substituicao e Escrita

		} else if (3==getSubstituicao()){
			//cout << "Substituicao LFU" << endl;
			aux=f[0];
			int auxI=0;
			for(int i=1; i<getLinhas(); i++){
				if(aux>f[i]) {
					aux=f[i];
					auxI=i;
				}
			}
			v[auxI]=end;
			f[auxI]=1;
			cout << "Frequencia de acesso: ";
			for (int i=0; i<getLinhas(); i++) {
				cout << f[i] << " ";
			}
			cout << endl;
			setVetor(v);
			setFreq(f);
			return auxI;
			//Com politica de substituicao e Escrita

		} else if (4==getSubstituicao()){
			cout << "Substituicao LRU" << endl;
			//Com politica de substituicao e Escrita

		}else {
			cerr << "Politica de substituicao nao reconhecida! Abortando operacoes..." << endl;
			exit(1);
		}
	}
	
	return -1;
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