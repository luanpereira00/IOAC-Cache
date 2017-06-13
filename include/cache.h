#ifndef CACHE_H
#define CACHE_H

class Cache{ 
private:
	int qtdPalavras;
	int qtdLinhas;
	int memPrincipal;
	int mapeamento;
	int vias;
	int polSubstituicao;
	int polEscrita;
	int hit;
	int miss;
	int* freq;
	int* vetor;
	int** matriz;
	int** freqMatriz;

public:
	Cache();
	~Cache();

	int getPalavras();
	int getLinhas();
	int getPrincipal();
	int getMapeamento();
	int getVias();
	int getSubstituicao();
	int getEscrita();
	int getHit();
	int getMiss();
	int* getFreq();
	int* getVetor();
	int** getMatriz();
	int** getFreqMatriz();

	void setPalavras(int p);
	void setLinhas(int l);
	void setPrincipal(int m);
	void setMapeamento(int mp);
	void setVias(int v);
	void setSubstituicao(int s);
	void setEscrita(int e);
	void setHit(int h);
	void setMiss(int ms);
	void setFreq(int* fr);
	void setVetor(int* vt);
	void setMatriz(int **m);
	void setFreqMatriz(int **fm);

	
	void mainCache();
	void exibirCache();
	void exibirFreq();
	void exibirCacheMatriz();
	void exibirFreqMatriz();
	void criar();

	int solicitarEndereco();

	int memPalavras();

	int viasCache(int end);
	int mapeamentoCache(int end);
	int substituicaoCache(int end);
	int substituicaoMatrizCache(int end, int via);
	int calcBlocoPrincipal(int end);
};



#endif