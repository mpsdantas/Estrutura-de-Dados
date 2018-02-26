#include <cstring>
#include <fstream>
#include <iostream>
#include "ListaCandidatos.h"
#include "Candidato.h"
using namespace std;
ListaCandidatos::ListaCandidatos(string nomeDoArquivo){
    Candidato* novoCandidato;
    ifstream fcin(nomeDoArquivo.c_str());
    string dados;
    getline(fcin,dados);
    cout << "nome da regiao: " << dados << endl;
    while(getline(fcin,dados)){
        novoCandidato = new Candidato(dados);
        adicioneComoHead(novoCandidato);
        cout << "criacao do candidato: " << novoCandidato->toString() << endl;
    }
}
void ListaCandidatos::adicioneComoHead(Candidato* novoCandidato){
    NoCandidato* candidatoParaInsercao;
    if(estaVazia()){
        candidatoParaInsercao = new NoCandidato(novoCandidato,NULL);
        head = candidatoParaInsercao;
    }
    candidatoParaInsercao = new NoCandidato(novoCandidato,head);
    this->head = candidatoParaInsercao;
}
int ListaCandidatos::tamanho(){
    int contadorDeCandidatos = 0;
    NoCandidato *candidatoAtualDaLista;
    candidatoAtualDaLista = head;
    if(this->head==NULL) return 0;//Verificação se a lista é vazia
    while(candidatoAtualDaLista->next!=NULL){
        contadorDeCandidatos++;
        candidatoAtualDaLista = candidatoAtualDaLista->next;
    }
    return contadorDeCandidatos;
}
string ListaCandidatos::toString(){
    if(tamanho()==0) return "0";
    return head->toString();
}
bool ListaCandidatos::remover(string nome, string sobrenome){
    if(estaVazia()) return false;
    NoCandidato *candidatoAtualDaLista;
    NoCandidato *candidatoAnteriorDaLista;
    candidatoAnteriorDaLista = NULL;
    candidatoAtualDaLista = head;
    if(this->head==NULL) return 0;//Verificação se a lista é vazia
    while(candidatoAtualDaLista->next!=NULL){
        if(candidatoAtualDaLista->conteudo->igual(nome,sobrenome)){
            //Fazer tratamentos
        }
        candidatoAnteriorDaLista = candidatoAtualDaLista;
        candidatoAtualDaLista = candidatoAtualDaLista->next;
    }
}
