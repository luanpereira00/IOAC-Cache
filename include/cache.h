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
	int* vetor;

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
	int* getVetor();

	void setPalavras(int p);
	void setLinhas(int l);
	void setPrincipal(int m);
	void setMapeamento(int mp);
	void setVias(int v);
	void setSubstituicao(int s);
	void setEscrita(int e);
	void setHit(int h);
	void setMiss(int ms);
	void setVetor(int* vt);

	
	void mainCache();

	int solicitarEndereco();

	int memPalavras();

	int viasCache(int end);
	int mapeamentoCache(int end);
	int substituicaoCache(int end);
	int calcBlocoPrincipal(int end);
};



#endif