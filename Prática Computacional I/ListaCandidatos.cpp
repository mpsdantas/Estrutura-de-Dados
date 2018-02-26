#include <cstring>
#include <fstream>
#include <iostream>
#include "ListaCandidatos.h"
#include "Candidato.h"
using namespace std;
ListaCandidatos::ListaCandidatos(string nomeDoArquivo){
    head = NULL;
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
    candidatoParaInsercao = new NoCandidato(novoCandidato,head);
    this->head = candidatoParaInsercao;
}
int ListaCandidatos::tamanho(){
    int contadorDeCandidatos = 1;
    NoCandidato *candidatoAtualDaLista;
    candidatoAtualDaLista = head;
    if(this->head==NULL) return 0;//Verificação se a lista é vazia
    while(candidatoAtualDaLista->next!=NULL){
        candidatoAtualDaLista = candidatoAtualDaLista->next;
        contadorDeCandidatos++;
    }
    return contadorDeCandidatos;
}
string ListaCandidatos::toString(){
    if(head==NULL) return "0";
    string nomes = "";
    NoCandidato* candidatoExibicao;
    candidatoExibicao = head;
    while(candidatoExibicao!=NULL){
        nomes += candidatoExibicao->conteudo->toString();
        nomes += " -> ";
        candidatoExibicao = candidatoExibicao->next;
    }
    nomes += " 0 ";
    return nomes;
}
bool ListaCandidatos::remove(string nome, string sobrenome){
    if(head==NULL) return false;
    NoCandidato *candidatoAtualDaLista;
    NoCandidato *candidatoAnteriorDaLista;
    candidatoAnteriorDaLista = NULL;
    candidatoAtualDaLista = head;
    while(candidatoAtualDaLista!=NULL){
        if(candidatoAtualDaLista->conteudo->igual(nome,sobrenome)){
            if(candidatoAnteriorDaLista==NULL){
                head = candidatoAtualDaLista->next;
                delete candidatoAtualDaLista;
                return true;
            }else{
                NoCandidato *candidatoLiberarMemoria = candidatoAtualDaLista->next;
                delete candidatoAtualDaLista;
                candidatoAtualDaLista = candidatoLiberarMemoria;
                candidatoAnteriorDaLista->next = candidatoAtualDaLista;
                return true;
            }
        }
        candidatoAnteriorDaLista = candidatoAtualDaLista;
        candidatoAtualDaLista = candidatoAtualDaLista->next;
    }
    return false;
}
void ListaCandidatos::filtrarCandidatos(int nota){
    NoCandidato *candidatoAtualDaLista;
    NoCandidato *candidatoAnteriorDaLista;
    candidatoAnteriorDaLista = NULL;
    candidatoAtualDaLista = head;
    while(candidatoAtualDaLista!=NULL){
        if(candidatoAtualDaLista->conteudo->nota < nota){
            if(candidatoAnteriorDaLista==NULL){
                cout << "Entrou IF" << endl;
                head = candidatoAtualDaLista->next;
                delete candidatoAtualDaLista;
            }else{
                cout << "Entrou ELSE" << endl;
                NoCandidato *candidatoLiberarMemoria = candidatoAtualDaLista->next;
                delete candidatoAtualDaLista;
                candidatoAtualDaLista = candidatoLiberarMemoria;
                candidatoAnteriorDaLista->next = candidatoAtualDaLista;
            }
        }
        candidatoAnteriorDaLista = candidatoAtualDaLista;
        candidatoAtualDaLista = candidatoAtualDaLista->next;
    }
}
