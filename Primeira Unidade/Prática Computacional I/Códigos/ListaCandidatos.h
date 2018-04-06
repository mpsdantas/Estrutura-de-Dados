#ifndef LISTACANDIDATOS_H_INCLUDED
#define LISTACANDIDATOS_H_INCLUDED

#include "NoCandidato.h"
class ListaCandidatos{
public:
    NoCandidato *head;
    inline ListaCandidatos(){this->head = NULL;}
    ListaCandidatos(string nomeDoArquivo);
    inline bool estaVazia(){return head == NULL;}
    void adicioneComoHead(Candidato* novoCandidato);
    int tamanho();
    string toString();
    bool remove(string nome, string sobrenome);
    void filtrarCandidatos(int nota);
    void concatena(ListaCandidatos* novaLista);
};


#endif // LISTACANDIDATOS_H_INCLUDED
