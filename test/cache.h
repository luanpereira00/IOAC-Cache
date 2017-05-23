#ifndef CACHE_H
#define CACHE_H

class Cache{ 
private:
	unsigned short int qtdPalavras;
	unsigned short int qtdLinhas;
	unsigned short int memPrincipal;
	unsigned short int mapeamento;
	unsigned short int vias;
	unsigned short int polSubstituicao;
	unsigned short int polEscrita;

public:
	Cache();
	~Cache();

	unsigned short int getPalavras();
	unsigned short int getLinhas();
	unsigned short int getPrincipal();
	unsigned short int getMapeamento();
	unsigned short int getVias();
	unsigned short int getSubstituicao();
	unsigned short int getEscrita();

	void setPalavras(unsigned short int p);
	void setLinhas(unsigned short int l);
	void setPrincipal(unsigned short int m);
	void setMapeamento(unsigned short int mp);
	void setVias(unsigned short int v);
	void setSubstituicao(unsigned short int s);
	void setEscrita(unsigned short int e);


	
	void mainCache();

	short int solicitarEndereco();

	unsigned short int memPalavras();
	
	unsigned short int viasCache(unsigned short int end);
	unsigned short int mapeamentoCache(unsigned short int end);
	unsigned short int substituicaoCache(unsigned short int end);
	unsigned short int calcBlocoPrincipal(unsigned short int end);
};



#endif