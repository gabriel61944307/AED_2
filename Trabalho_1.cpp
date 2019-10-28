// Informações do estudante
// Nome: Gabriel Rodrigues Malaquias
// Curso: Bacharelado em Ciência da Computação
// RA:  758906

#include <iostream>
#include <map>

using namespace std;

int main()
{
    string OP;
    string nome;
    int numero;
    map<string, int> contatinho;
    map<string, int>::iterator cont;

    while(OP != "S" && OP != "0"){
        cin >> OP;

        //Insere
        if(OP == "I"){
            cin >> nome;
            cin >> numero;
            if(contatinho.find(nome) == contatinho.end()){
                contatinho.insert({nome,numero});
            }
            else{
                cout << "Contatinho ja inserido" << endl;
            }
        }

        //Procura
        else if(OP == "P"){
            cin >> nome;
            cont = contatinho.find(nome);
            if(cont != contatinho.end()){
                cout << "Contatinho encontrado: telefone " << cont->second << endl;
            }
            else{
                cout << "Contatinho nao encontrado" << endl;
            }
        }

        //Remove
        else if(OP == "R"){
            cin >> nome;
            if(contatinho.erase(nome));
            else{
                cout << "Operacao invalida: contatinho nao encontrado" << endl;
            }
        }

        //Alterar
        else if(OP == "A"){
            cin >> nome;
            cin >> numero;
            cont = contatinho.find(nome);
            if(cont != contatinho.end()){
                cont->second = numero;
            }
            else
                cout << "Operacao invalida: contatinho nao encontrado" << endl;
        }
    }

    return 0;
}
