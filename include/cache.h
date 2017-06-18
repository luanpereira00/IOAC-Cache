/**
 * @file	cache.h
 * @brief	Definicao da classe Cache para representar uma memoria Cache
 * @details Os atributos de uma Cache sao a quantidade de palavras por bloco, a quantidade de linhas da cache,
 * a quantidade de blocos da memoria principal, o tipo de mapeamento, o tipo de substituicao, quantidade de hits,
 * quantidade de misses, o vetor de frequencia, o vetor de cache, a matriz N-way e a frequencia de matriz N-way.
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	01/06/2017
 * @date	01/06/2017
 */

#ifndef CACHE_H
#define CACHE_H
/** 
 * @class 	Cache cache.h
 * @brief 	Classe que representa uma memoria Cache
 * @details Os atributos de uma Cache sao a quantidade de palavras por bloco, a quantidade de linhas da cache,
 * a quantidade de blocos da memoria principal, o tipo de mapeamento, o tipo de substituicao, quantidade de hits,
 * quantidade de misses, o vetor de frequencia, o vetor de cache, a matriz N-way e a frequencia de matriz N-way.
 */
class Cache{ 
private:
	int qtdPalavras; /**< A quantidade de palavras por bloco*/
	int qtdLinhas; /**< A quantidade de linhas da cache*/
	int memPrincipal; /**< A quantidade de blocos da memoria principal*/
	int mapeamento; /**< O tipo de mapeamento*/
	int vias; /**< A quantidade de vias (quando houver)*/
	int polSubstituicao; /**< A politica de substituicao*/
	int hit; /**< A quantidade de hits*/
	int miss; /**< A quantidade de misses*/
	int* freq; /**< O vetor de frequencia*/
	int* vetor; /**< O vetor de cache */
	int** matriz; /**< A matriz de cache (N-way)*/
	int** freqMatriz; /**< A matriz de frequencia (N-way)*/

public:
	/** @brief Construtor padrao */
	Cache();

	/*@brief Destrutor padrao */
	~Cache();

	/**@return Retorna a quantidade de palavras por bloco*/
	int getPalavras();

	/**@return Retorna a quantidade de linhas da cache */
	int getLinhas();

	/**@return Retorna a quantidade de blocos da memoria principal */
	int getPrincipal();

	/**@return Retorna o tipo de mapeamento */
	int getMapeamento();

	/**@return Retorna a quantidade de vias (N-way) */
	int getVias();

	/**@return Retorna a politica de substituicao */
	int getSubstituicao();

	/**@return Retorna a quantidade de hits*/
	int getHit();

	/**@return Retorna a quantidade de misses */
	int getMiss();

	/**@return Retorna o vetor de frequencia*/
	int* getFreq();

	/**@return Retorna o vetor de cache */
	int* getVetor();

	/**@return Retorna matriz de cache (N-way)*/
	int** getMatriz();

	/**@return Retorna a matriz de frequencia (N-way)*/
	int** getFreqMatriz();

	/**@brief Atualiza a quantidade de palavras
	* @param p A nova quantidade de palavras */
	void setPalavras(int p);

	/**@brief Atualiza a quantidade de linhas
	* @param l A nova quantidade de linhas*/
	void setLinhas(int l);

	/**@brief Atualiza a quantidade de blocos da memoria principal
	* @param m A nova quantidade de blocos da memoria principal*/
	void setPrincipal(int m);

	/**@brief Atualiza a nova forma de mapeamento
	* @param mp A nova nova forma de mapeamento*/
	void setMapeamento(int mp);

	/**@brief Atualiza a quantidade de vias (N-way)
	* @param v A nova quantidade de vias (N-way)*/
	void setVias(int v);

	/**@brief Atualiza a politica de substituicao 
	* @param s A nova politica de substituicao */
	void setSubstituicao(int s);

	/**@brief Atualiza a quantidade de hits
	* @param h A nova quantidade de hits*/
	void setHit(int h);

	/**@brief Atualiza a quantidade de misses
	* @param ms A nova quantidade de misses*/
	void setMiss(int ms);

	/**@brief Atualiza o vetor de frequencia 
	* @param fr O novo vetor de frequencia */
	void setFreq(int* fr);

	/**@brief Atualiza o vetor de cache 
	* @param vt O novo vetor de cache */
	void setVetor(int* vt);

	/**@brief Atualiza a matriz de cache (N-way)
	* @param m A nova matriz de cache (N-way)*/
	void setMatriz(int **m);

	/**@brief Atualiza a matriz de frequencia (N-way) 
	* @param fm A nova matriz de frequencia (N-way) */
	void setFreqMatriz(int **fm);

	/**@brief Funcao principal que direciona a politica de substituicao, mapeamento, N-way etc. */
	void mainCache();

	/**@brief Funcao que imprime o vetor de cache */
	void exibirCache();

	/**@brief Funcao que imprime o vetor de frequencia */
	void exibirFreq();

	/**@brief Funcao que imprime a matriz de cache (N-way)*/
	void exibirCacheMatriz();

	/**@brief Funcao que a matriz de frequencia (N-way)*/
	void exibirFreqMatriz();

	/**@brief Funcao que realiza as alocacoes dinamicas necessarias e inicializa os vetores com valores default */
	void criar();

	/**@brief Funcao que solicita o endereco de memoria que sera buscado na cache 
	*@return Retorna o endereco */
	int solicitarEndereco();

	/**@brief Funcao que calcula a quantidade maxima de enderecos da memoria da principal
	*@return Retorna a quantidade maxima de enderecos*/
	int memPalavras();

	/**@brief Funcao que direciona para qual via o endereco deve ser substituido 
	*@param end O endereco 
	*@return Retorna o local de substituicao */
	int viasCache(int end);

	/**@brief Funcao que direciona para qual tipo de mapeamento deve ser executado
	*@param end O endereco 
	*@return Retorna o local de substituicao */
	int mapeamentoCache(int end);

	/**@brief Funcao que direciona para qual tipo de substituicao deve ser executada
	*@param v O vetor de cache
	*@param f O vetor de frequencia
	*@param end O endereco
	*@return Retorna o local de substituicao */
	int substituicaoCache(int *v, int *f, int end);

	/**@brief Funcao que atualiza o vetor de frequencia para FIFO
	*@param f O vetor de frequencia */
	void atualizarFrequenciaFIFO(int *f);


	/**@brief Funcao que calcula o bloco que o endereco esta na memoria principal
	*@param end O endereco
	*@return Retorna o bloco da principal */ 
	int calcBlocoPrincipal(int end);
};

#endif