# Makefile, separando os diferentes elementos da aplicacao
# como codigo (src), cabecalhos (include), executaveis (build), bibliotecas (lib), etc.
# Cada elemento e alocado em uma pasta especifica, organizando melhor seu codigo fonte.
#
# Algumas variaveis sao usadas com significado especial:
#
# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito
#

# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC=g++ 

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
DAT_DIR=./data
TEST_DIR=./test

# Opcoes de compilacao
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all init clean doxy debug doc 

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: init cache
debug: CFLAGS += -g -O0
debug: pilha lista turmas

init:
	@mkdir -p $(BIN_DIR)/
	@mkdir -p $(OBJ_DIR)/

# Alvo (target) para a construcao do executavel
# Define os arquivos pilha.o, tratarString.o como dependencia
cache: $(OBJ_DIR)/main.o $(OBJ_DIR)/cache.o $(OBJ_DIR)/arquivo.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'cache' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto matrizes.o
# Define os arquivos main.cpp, cache.cpp, arquivo.cpp, cache.h e arquivo.h como dependencias.
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(SRC_DIR)/cache.cpp $(SRC_DIR)/arquivo.cpp $(INC_DIR)/arquivo.h $(INC_DIR)/cache.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto matrizes.o
# Define os arquivos arquivo.cpp, arquivo.h, cache.cpp e cache.h como dependencias.
$(OBJ_DIR)/arquivo.o: $(SRC_DIR)/arquivo.cpp $(SRC_DIR)/cache.cpp $(INC_DIR)/arquivo.h $(INC_DIR)/cache.h
	$(CC) -c $(CFLAGS) -o $@ $<		

# Alvo (target) para a construcao do objeto matrizes.o
# Define os arquivos cache.cpp e cache.h como dependencias.
$(OBJ_DIR)/cache.o: $(SRC_DIR)/cache.cpp $(INC_DIR)/cache.h
	$(CC) -c $(CFLAGS) -o $@ $<				

# Alvo (target) para a construcao do executavel
# Define o arquivo lista.o como dependencia
lista: $(OBJ_DIR)/lista.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'lista' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto matrizes.o
# Define os arquivos lista.cpp e lista.h como dependencias.
$(OBJ_DIR)/lista.o: $(SRC_DIR)/lista.cpp $(INC_DIR)/lista.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do executavel
# Define o arquivo turmas.o como dependencia
turmas: $(OBJ_DIR)/turmas.o $(OBJ_DIR)/menu.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'turmas' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto matrizes.o
# Define os arquivos turmas.cpp, menu.cpp, menu.h, turma.h, aluno.h e pilha.h como dependencias.
$(OBJ_DIR)/turmas.o: $(SRC_DIR)/turmas.cpp $(SRC_DIR)/menu.cpp $(INC_DIR)/menu.h $(INC_DIR)/turma.h $(INC_DIR)/aluno.h $(INC_DIR)/pilha.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto matrizes.o
# Define os arquivos menu.cpp e menu.h como dependencias.
$(OBJ_DIR)/menu.o: $(SRC_DIR)/menu.cpp $(INC_DIR)/menu.h
	$(CC) -c $(CFLAGS) -o $@ $<				

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen -g

doc:
	doxygen

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/* 
	$(RM) $(OBJ_DIR)/*	
	$(RM) $(DOC_DIR)/*	