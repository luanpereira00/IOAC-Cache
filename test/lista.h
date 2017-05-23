/**
 * @file	lista.h
 * @brief	Definicao da classe lista para representar uma lista ligada ordenada duplamente encadeada de dados
 * @details Os atributos de uma lista sao as sentinelas de inicio e de fim
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	17/05/2017
 * @date	17/05/2017
 */
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

/** @brief Declaracao de template para o tipo T (int, float, double...)*/
template <typename T>

/** 
* struct node lista.h
* @brief Um struct para representar os nos de lista ligada
*/
struct node{
	T dado; /**< Elemento generico do no*/
	node* prox; /**< Apontador para o proximo no*/
	node* anter; /**< Apontador para o no anterior*/
};

/** 
 * @class 	lista lista.h
 * @brief 	Classe que representa uma lista ligada ordenada duplamente encadeada de dados
 * @details Os atributos de uma lista sao as sentinelas de inicio e de fim 
 */
template <typename T>
class lista{
private:
	node<T>* inicio; /**< Sentinela de inicio da lista*/
	node<T>* fim; /**< Sentinela de fim da lista*/

public:
	/** @brief Construtor padrao */
	lista(){
		inicio = new struct node<T>;
		fim = new struct node<T>;

		inicio->dado=0;
		inicio->prox=fim;
		inicio->anter=NULL;

		fim->dado=0;
		fim->prox=NULL;
		fim->anter=inicio;
	}
	/** @brief Destrutor padrao */
	~lista(){
		node<T>* tmp = new node<T>;
		node<T>* aux = inicio;
		tmp->prox=inicio->prox;
		while(tmp->prox->prox){
			delete aux;
			aux = tmp->prox;
			tmp->prox=tmp->prox->prox;
		}
		delete aux;
		delete tmp->prox;;
		delete tmp;
	}

	/** @return Retorna a sentinela de inicio da lista ligada*/
	node<T>* getInicio(){
		return inicio;
	}

	/** @return Retorna a sentinela de fim da lista ligada*/
	node<T>* getFim(){
		return fim;
	}

	/** 
	* @brief Insere um elemento ordenadamente na lista
	* @param el O elemento que sera inserido na lista 
	*/
	void inserir(T el){
		//cout << "Inserindo o elemento " << el << endl;
		node<T>* it = buscar(el);
		node<T>* tmp = new node<T>;
		tmp->dado=el;
		tmp->prox=it->prox;
		tmp->anter=it;

		it->prox->anter=tmp;
		it->prox=tmp;
	}

	void inserirFim(T el){
		//cout << "Inserindo o elemento " << el << endl;
		node<T>* it = buscar(fim->anter->dado);
		node<T>* tmp = new node<T>;
		tmp->dado=el;
		tmp->prox=it->prox;
		tmp->anter=it;

		it->prox->anter=tmp;
		it->prox=tmp;
	}

	/** 
	* @brief Remove um elemento da lista ligada. (Informa também caso o elemento nao exista)
	* @param el O elemento que sera removido da lista 
	*/
	void remover(T el){
		//cout << endl;
		//cout << "Removendo o elemento " << el << endl;
		node<T>* it = buscar(el);
		if(it->prox->dado==el){
			node<T>* tmp = new node<T>;
			tmp->prox=it->prox->prox;
			tmp->anter=it;

			delete it->prox; 

			it->prox=tmp->prox;
			it->prox->anter=tmp->anter;

			delete tmp; 
		}
		else cerr << "ERRO: Impossivel remover o elemento " << el << " (nao existe na lista)! ...Continuando operacoes" << endl;
	}

	/** @brief Imprime toda a lista ligada*/
	void imprimir(){
		node<T>* it = inicio;
		if(it->prox->prox){
			cout << "-----------------------" << endl;
			cout << "Lista: " << endl;
		}
		while(it->prox->prox){
			cout << it->prox->dado << endl;
			it=it->prox;
		}
		if(it->prox->prox) cout << "-----------------------" << endl;
	}

	void imprimirVetor(int tam){
		node<T>* it = inicio;
		if(it->prox->prox){
			cout << "-----------------------" << endl;
			cout << "Lista: " << endl;
		}
		while(it->prox->prox){
			for (int i=0; i<tam; i++) cout << (it->prox->dado)[i] << " ";
			cout << endl
			it=it->prox;
		}
		if(it->prox->prox) cout << "-----------------------" << endl;
	}

	/** 
	* @brief Busca na lista ligada (usado para inserir e remover apenas!)
	* @param el O elemento que sera removido da lista 
	*/
	node<T>* buscar(T el){
		node<T>* it = inicio;
		while(it->prox->prox && it->prox->dado<el){
			it=it->prox;
		}
		return it;
	}
};

#endif
