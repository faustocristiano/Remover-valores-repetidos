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

    // lê um par de valores por vez do arquivo
    // esse par é composto pelo nome do produto e de sua quantidade
    while (arq >> numero) {
    mat.insert(numero);
    }
    list <string>ordem;
    for (auto & item: mat) {
        ordem.push_front(item);
    }
    ordem.sort();
    //printa a lista ordenada//
    for (auto & x: ordem) {
        // mostra a chave (par.first) seguido do valor (par.second)
        cout <<x<<endl;
    }
}



