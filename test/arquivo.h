#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <fstream>
using std::ifstream;

#include "cache.h"

void abrirArquivo(ifstream *arquivo);

void loadData(Cache* dados, ifstream *arquivo);

#endif
