#ifndef REMOVER_VALORES_OUTRA_FORMA_H
#define REMOVER_VALORES_OUTRA_FORMA_H

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

int main(int argc, char * argv[]) {
    // cria uma tabela conjunto: e o valor um int
    unordered_set<string> mat;

    // abre o arquivo de dados
    ifstream arq(argv[1]);
    if (!arq.is_open()) {
        perror("erro ao abrir arquivo ");
        return errno;
    }

    string numero;
    list <string>ordem;
    // lê um par de valores por vez do arquivo
    // esse par é composto pelo nome do produto e de sua quantidade
    while (arq >> numero) {
        if (numero.empty()) break;
        if(!mat.count(numero)){
            mat.insert(numero);
            ordem.push_front(numero);
        }
    }
    ordem.sort();
    for (auto & item: ordem) {
        cout<<item<<endl;
    }

}

#endif //REMOVER_VALORES_OUTRA_FORMA_H
