/**
 * @file	cache.cpp
 * @brief	Implementacao da classe Cache para representar uma memoria Cache
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */
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

#include <iomanip>
using std::setw;

#include "cache.h"

/** @brief Construtor padrao */
Cache::Cache(){
	miss=0;
	hit=0;
	/** Faz nada */
}

/*@brief Destrutor padrao */
Cache::~Cache(){
	if(getMapeamento()==3){
		for(int i=0; i<getVias(); i++) delete[] matriz[i];
		delete[] matriz;
		for(int i=0; i<getVias(); i++) delete[] freqMatriz[i];
		delete[] freqMatriz;
	}
	else {
		delete[] vetor;
		delete[] freq;
	}

	/** Faz nada */
}

/**@return Retorna a quantidade de palavras por bloco*/
int Cache::getPalavras()			{ return qtdPalavras;		}

/**@return Retorna a quantidade de linhas da cache */
int Cache::getLinhas()				{ return qtdLinhas;			}

/**@return Retorna a quantidade de blocos da memoria principal */
int Cache::getPrincipal()			{ return memPrincipal;		}

/**@return Retorna o tipo de mapeamento */
int Cache::getMapeamento()			{ return mapeamento;		}

/**@return Retorna a quantidade de vias (N-way) */
int Cache::getVias()				{ return vias;				}

/**@return Retorna a politica de substituicao */
int Cache::getSubstituicao()		{ return polSubstituicao;	}

/**@return Retorna a quantidade de hits*/
int Cache::getHit()					{ return hit;				}

/**@return Retorna a quantidade de misses */
int Cache::getMiss()				{ return miss;				}

/**@return Retorna o vetor de frequencia*/
int* Cache::getFreq()				{ return freq;				}

/**@return Retorna o vetor de cache */
int* Cache::getVetor()				{ return vetor;				}

/**@return Retorna matriz de cache (N-way)*/
int** Cache::getMatriz()			{ return matriz;			}

/**@return Retorna a matriz de frequencia (N-way)*/
int** Cache::getFreqMatriz()		{ return freqMatriz;		}

/**@brief Atualiza a quantidade de palavras
* @param p A nova quantidade de palavras */
void Cache::setPalavras(int p)		{ qtdPalavras = p; 		}

/**@brief Atualiza a quantidade de linhas
	* @param l A nova quantidade de linhas*/
void Cache::setLinhas(int l)		{ qtdLinhas = l; 		}

/**@brief Atualiza a quantidade de blocos da memoria principal
	* @param m A nova quantidade de blocos da memoria principal*/
void Cache::setPrincipal(int m)		{ memPrincipal = m; 	}

/**@brief Atualiza a nova forma de mapeamento
	* @param mp A nova nova forma de mapeamento*/
void Cache::setMapeamento(int mp)	{ mapeamento = mp; 		}

/**@brief Atualiza a quantidade de vias (N-way)
	* @param v A nova quantidade de vias (N-way)*/
void Cache::setVias(int v)			{ vias = v; 			}

/**@brief Atualiza a politica de substituicao 
	* @param s A nova politica de substituicao */
void Cache::setSubstituicao(int s)	{ polSubstituicao = s; 	}

/**@brief Atualiza a quantidade de hits
	* @param h A nova quantidade de hits*/
void Cache::setHit(int h)			{ hit = h;				}

/**@brief Atualiza a quantidade de misses
	* @param ms A nova quantidade de misses*/
void Cache::setMiss(int ms)			{ miss = ms;			}

/**@brief Atualiza o vetor de frequencia 
	* @param fr O novo vetor de frequencia */
void Cache::setFreq(int* fr)		{ freq = fr; 			}

/**@brief Atualiza o vetor de cache 
	* @param vt O novo vetor de cache */
void Cache::setVetor(int* vt)		{ vetor = vt; 			}

/**@brief Atualiza a matriz de cache (N-way)
	* @param m A nova matriz de cache (N-way)*/
void Cache::setMatriz(int** m)		{ matriz = m;			}

/**@brief Atualiza a matriz de frequencia (N-way) 
	* @param fm A nova matriz de frequencia (N-way) */
void Cache::setFreqMatriz(int** fm)	{ freqMatriz = fm;		}

/**@brief Funcao que calcula a quantidade maxima de enderecos da memoria da principal
	*@return Retorna a quantidade maxima de enderecos*/
int Cache::memPalavras(){
	return getPalavras()*getPrincipal();
} 

/**@brief Funcao que solicita o endereco de memoria que sera buscado na cache 
	*@return Retorna o endereco */
int Cache::solicitarEndereco(){
	int end;
	cout << "===========================================" << endl;
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

/**@brief Funcao que calcula o bloco que o endereco esta na memoria principal
	*@param end O endereco
	*@return Retorna o bloco da principal */ 
int Cache::calcBlocoPrincipal(int end){
	return ((end - (end % getPalavras()))/getPalavras());
}

/**@brief Funcao principal que direciona a politica de substituicao, mapeamento, N-way etc. */
void Cache::mainCache(){
	short int end=1;
	while(end>=0 and end<getPalavras()*getPrincipal()){ //MAX_ENDERECO_POSSIVEIS
		end = solicitarEndereco();
		if(end==-1) return;

		cout << "Bloco da principal: " << calcBlocoPrincipal(end) << endl;
		if(getMapeamento()==3){
			cout << mapeamentoCache(calcBlocoPrincipal(end)) << endl;
		} else {
			
			cout << "Mapeado no bloco " << mapeamentoCache(calcBlocoPrincipal(end)) << " da memoria cache" << endl;
		}
	}
}
/**@brief Funcao que direciona para qual tipo de mapeamento deve ser executado
	*@param end O endereco 
	*@return Retorna o local de substituicao */
int Cache::mapeamentoCache(int end){
	int mapeado=-1;
	if(1==getMapeamento()){
		cout << "Mapeamento Direto" << endl;
		int* v = getVetor();
		cout << "Buscando o bloco " << end;
		if(v[end % getLinhas()]==end) {
			cout << endl << endl << " -> --- HIT ---" << endl << endl;
			setHit(getHit()+1);
		}
		else {
			cout << endl << endl << " -> --- MISS ---" << endl << endl;
			setMiss(getMiss()+1);
			v[end % getLinhas()]=end;
		}
		mapeado = end % getLinhas();
		exibirCache();
		setVetor(v);
		//Sem Politica de Substituicao
	} else if (2==getMapeamento()){
		cout << "Mapeamento Totalmente Associativo" << endl;
		mapeado = substituicaoCache(getVetor(), getFreq(), end);
		exibirCache();
		if(1!=getSubstituicao()) exibirFreq();

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

/**@brief Funcao que atualiza o vetor de frequencia para FIFO
	*@param f O vetor de frequencia */
void Cache::atualizarFrequenciaFIFO(int *f){	
	for (int i=0; i<getLinhas(); i++) {
		f[i]--;
	}
}

/**@brief Funcao que direciona para qual tipo de substituicao deve ser executada
	*@param v O vetor de cache
	*@param f O vetor de frequencia
	*@param end O endereco
	*@return Retorna o local de substituicao */
int Cache::substituicaoCache(int *v, int *f, int end){
	//cout << "Substituicao FIFO" << endl;
	//Comum a todos
	if(1==getSubstituicao()) cout << "Substituicao Aleatoria" << endl;
	if(2==getSubstituicao()) cout << "Substituicao FIFO" << endl;
	if(3==getSubstituicao()) cout << "Substituicao LFU" << endl;
	if(4==getSubstituicao()) cout << "Substituicao LRU" << endl;
	cout << "Buscando o bloco " << end;
	//int* v = getVetor();
	//int* f = getFreq();
	bool freeFlag=false;
	int aux=-1;

	if(4==getSubstituicao()){
		for (int i=0; i<getLinhas(); i++) {
			f[i]--;
			if(f[i]<0) f[i]=0;
		}
	}	

	for(int i=0; i<getLinhas(); i++){
		if(v[i]==end){
			cout << endl << endl << " -> --- HIT ---" << endl << endl;
			setHit(getHit()+1);
			if(3==getSubstituicao()){
				f[i]++;
			}
			if(4==getSubstituicao()){
				f[i]=getLinhas();
			}
			return i;
		}
		if(!freeFlag and v[i]==-1) {
			freeFlag=true;
			aux=i;
		}
	}
	cout << endl << endl << " -> --- MISS ---" << endl << endl;
	setMiss(getMiss()+1);

	if(freeFlag) {
		v[aux]=end;
		if(2==getSubstituicao()){
			f[aux]=getLinhas();
			atualizarFrequenciaFIFO(f);
		}
		if(3==getSubstituicao()){
			f[aux]=1;
		}
		if(4==getSubstituicao()){
			f[aux]=getLinhas();
		}
		return aux;
	} 
	else {
		if(1==getSubstituicao()){
			//RANDOM
			aux = rand() % getLinhas();
			v[aux]=end;
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
			atualizarFrequenciaFIFO(f);
			cout << endl;
		
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
			return auxI;
			//Com politica de substituicao e Escrita

		} else if (4==getSubstituicao()){
			//cout << "Substituicao LRU" << endl;
			aux=f[0];
			int auxI=0;
			for(int i=1; i<getLinhas(); i++){
				if(aux > f[i]) {
					aux=f[i];
					auxI=i;
				}
			}
			v[auxI]=end;
			f[auxI]=getLinhas();
			return auxI;
			//Com politica de substituicao e Escrita

		}else {
			cerr << "Politica de substituicao nao reconhecida! Abortando operacoes..." << endl;
			exit(1);
		}
	}
	
	return -1;
}


/**@brief Funcao que realiza as alocacoes dinamicas necessarias e inicializa os vetores com valores default */
void Cache::criar(){
	if(getMapeamento()==3){
		int **m = new int*[getVias()];
		for(int i=0; i<getVias(); i++) m[i]=new int[getLinhas()];

		int **fm = new int*[getVias()];
		for(int i=0; i<getVias(); i++) fm[i]=new int[getLinhas()];

		for(int i=0; i<getVias(); i++){
			for(int j=0; j<getLinhas(); j++){
				m[i][j]=-1;
				fm[i][j]=0;
			}
		}
		setMatriz(m);
		setFreqMatriz(fm);

	} else {
		int* v = new int[getLinhas()];
		int* f = new int[getLinhas()];
		for(int i=0; i<getLinhas(); i++) {
			v[i]=-1;
			f[i]=0;
		}
		if(getSubstituicao()==4) {
			for(int i=0; i<getLinhas(); i++) {
				f[i]=getSubstituicao();
			}
		}
		setVetor(v);
		setFreq(f);
	}
}

/**@brief Funcao que direciona para qual via o endereco deve ser substituido 
	*@param end O endereco 
	*@return Retorna o local de substituicao */
int Cache::viasCache(int end){
	int **m = getMatriz();
	int **fm = getFreqMatriz();
	if(getVias()>0){
		cout << "Vias" << endl;
		cout << "Mapeado no bloco " << substituicaoCache(m[end%getVias()], fm[end%getVias()], end) << " da via " << end%getVias() << endl;
		exibirCacheMatriz();
		if(getSubstituicao()==3 or getSubstituicao()==2 or getSubstituicao()==4) exibirFreqMatriz();
		
		//cout << end << "  " << end % getLinhas() << endl;;
		//matriz
		//bloco da principal indica a via e o bloco

		//Sem Politica de Substituicao
	} else {
		cerr << "Quantidade de vias nao reconhecidas! Abortando operacoes..." << endl;
		exit(1);
	}
	return 0;
}

/**@brief Funcao que imprime o vetor de cache */
void Cache::exibirCache(){
	int *v = getVetor();
	cout << "------- Cache -------" <<endl;
	cout << "[ ";
	for (int i=0; i<getLinhas(); i++) {
		if(v[i]==-1) cout << "__";
		else cout << setw(2) << v[i];

		cout << " ";
	}
	cout << "] -> Blocos da memoria principal na cache"<< endl;
	cout << "[ ";
	for (int i=0; i<getLinhas(); i++) {
		cout << setw(2) << i << " ";
	}
	cout << "] -> Blocos da cache"<< endl << endl;
}

/**@brief Funcao que imprime o vetor de frequencia */
void Cache::exibirFreq(){
	int *f = getFreq();
	int *v = getVetor();
	cout << "------- Frequencia -------" <<endl;
	cout << "[ ";
	for (int i=0; i<getLinhas(); i++) {
		if(v[i]>=0)cout << setw(2) << f[i] << " ";
		else cout << "__ ";
	}
	cout << "] -> Vetor de frequencia dos blocos na cache" << endl;
	cout << "[ ";
	for (int i=0; i<getLinhas(); i++) {
		cout << setw(2) << i << " ";
	}
	cout << "] -> Numero do bloco da cache" << endl << endl;
}

/**@brief Funcao que imprime a matriz de cache (N-way)*/
void Cache::exibirCacheMatriz(){
	int **m = getMatriz();
	cout << "------- Cache -------" <<endl;
	for(int i=0; i<getVias(); i++){
		cout << "[ ";
		for (int j=0; j<getLinhas(); j++) {
			if(m[i][j]==-1) cout << "__";
			else cout << setw(2) << m[i][j];

			cout << " ";
		}
		cout << "] -> Via "<< i << endl;
	}
	
	cout << "[ ";
	for (int i=0; i<getLinhas(); i++) {
		cout << setw(2) << i << " ";
	}
	cout << "] -> Numero de blocos da cache"<< endl << endl;
}

/**@brief Funcao que a matriz de frequencia (N-way)*/
void Cache::exibirFreqMatriz(){
	int **m = getMatriz();
	int **fm = getFreqMatriz();
	cout << "------- Frequencia -------" <<endl;
	for(int i=0; i<getVias(); i++){
		cout << "[ ";
		for (int j=0; j<getLinhas(); j++) {
			if(m[i][j]>=0)cout << setw(2) << fm[i][j] << " ";
			else cout << "__ ";
		}
		cout << "] -> Via "<< i << endl;
	}

	cout << "[ ";
	for (int i=0; i<getLinhas(); i++) {
		cout << setw(2) << i << " ";
	}
	cout << "] -> Numero de blocos da cache"<< endl << endl;
}