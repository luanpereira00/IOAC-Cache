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

public:

	int getPalavras();
	int getLinhas();
	int getPrincipal();
	int getMapeamento();
	int getVias();
	int getSubstituicao();
	int getEscrita();

	void setPalavras(int p);
	void setLinhas(int l);
	void setPrincipal(int m);
	void setMapeamento(int mp);
	void setVias(int v);
	void setSubstituicao(int s);
	void setEscrita(int e);


	int solicitarEndereco();
	void initCache();
};



#endif