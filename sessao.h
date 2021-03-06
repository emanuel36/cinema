#ifndef SESSAO_H
#define SESSAO_H

#include <vector>
#include <sstream>
#include "cliente.h"
#include "sala.h"
#include "filme.h"

using namespace std;

int idSessao = 0;
class Sessao{
public:
    Sala* sala;
    Filme* filme;
    vector<Cliente*> cadeiras;
    int hora;
    int id;

    Sessao(int hora){
        this->hora = hora;
        this->id = idSessao++;
    }

    void initCadeiras(){
        for(int i = 0; i < sala->capacidade; i++){
            cadeiras.push_back(nullptr);
        }
    }

    string search(string search){
        string temp = "";
        if(this->filme->nome == search){
            temp = this->toString();
            return temp;
        }
        return temp;
    }

    bool vender(Cliente* cli){
        for(auto elem: cadeiras){
            if(elem != nullptr){
                if(elem->cpf == cli->cpf){
                    throw string("erro | cliente já comprou");
                }
            }
        }
        for(int i = 0; i < sala->capacidade; i++){
            if(cadeiras[i] == nullptr){
                cadeiras[i] = cli;
                return true;
            }
        }
        return false;
    }

    string toString(){
        stringstream ss;
        int i = 0;
        ss << endl << "### Seção " << id << " ###" << endl;
        ss << "Sala: " << sala->id << endl;
        ss << "Filme: " << filme->nome << endl;
        ss << "Hora: " << hora << endl;
        for(auto elem: cadeiras){
            if(elem == nullptr){
                i++;
            }
        }
        ss << "Vagas: " << i << endl;
        return ss.str();
    }

    string toString2(){
        stringstream ss;
        ss << endl << "### Seção " << id << " ###" << endl;
        ss << "Sala: " << sala->id << endl;
        ss << "Filme: " << filme->nome << endl;
        ss << "Hora: " << hora << endl;
        for(auto elem: cadeiras){
            if(elem != nullptr){
                ss << "[" << elem->cpf << "]" << endl;
            }
        }
        return ss.str();
    }
};

#endif // SESSAO_H
