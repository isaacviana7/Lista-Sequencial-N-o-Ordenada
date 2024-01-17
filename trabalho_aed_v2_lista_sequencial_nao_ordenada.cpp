#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct tpNo {
    int numReg;
};

struct tpNo L[7];
int m = 7;
int n = 0;

int Buscar(int x){
    int I = 1;
    int returnBusca = 0;

    while (I <= n)
    {
        if (L[I].numReg == x){
            returnBusca = I;
            return I;
        }else {
            I++;
        }
    }
    return 0;
}

void Inserir(){
    int chave;
    cout << "Digite o registro a ser inserido: ";
    cin >> chave;

    if(n < m - 1){
        if (Buscar(chave) != 0)
        {
            cout << "Registro já existente." << endl;
        } else {
            L[n+1].numReg = chave;
            n++;
            cout << "Registro: " << L[n].numReg << " inserido com sucesso." << endl;
        }
        
    } else {
        cout << "Lista cheia." << endl;
    }
    
}

void Excluir(){
    int chave1; int posLista;
    cout << "Digite o registro a ser excluído: ";
    cin >> chave1;

    if (n < 1){
        cout << "Lista vazia." << endl;
    } else {
        posLista = Buscar(chave1);
        if (posLista < 1){
            cout << "Não existe esse registro.";
        } else {
            while (posLista < n){
                L[posLista].numReg = L[posLista + 1].numReg;
                posLista--;
            }
            n = n - 1;
            cout << "Regsitro excluído com sucesso.";
        }
    }
}

void Alterar(){
    int numRegAlt; int indiceNum; int newNumReg;

    if (n < 1){
        cout << "A lista está vazia." << endl;
    } else {
        cout << "Digite o número do registro que deseja alterar:";
        cin >> numRegAlt;

        
        indiceNum = Buscar(numRegAlt);
        if (indiceNum < 1){
            cout << "A lista está vazia.";
        } else {
            cout << "Insira o novo registro a ser inserido: ";
            cin >> newNumReg;
            L[numRegAlt].numReg = newNumReg;
            cout << "Registro alterado com sucesso.";
        }
    }

}

void Listar(){
    int z = 1;
    if (n < 1){
        cout << "A lista está vazia.";
    } else {
        cout << "LISTA DE REGISTRO DE FUNCIONÁRIOS:" << endl;
        while (z <= n)
        {
            cout << "Funcionário Nº " << z << " - " << "Registro: " << L[z].numReg << endl;
            z++;
        }
        cout << endl;
    }

}

int main(int argc, char** argv){
    
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    int numOption;
    
    cout << "1- Inserir novo funcionário" << endl;
    cout << "2- Buscar registro do funcionário" << endl;
    cout << "3- Alterar registro" << endl;
    cout << "4- Excluir funcionário" << endl;
    cout << "5- Listar todos os funcionários" << endl;
    cout << "6- Sair" << endl; 
    
    cin >> numOption;
    
    while (numOption != 6)
    {            
        switch (numOption)
        {
        case 1:
            cout << "Novo Funcionário - ";
            Inserir();
            break;

        case 2 :
            int numBusca;
            cout << "Número de registro: ";
            cin >> numBusca;
            if (Buscar(numBusca) == 0)
            {
                cout << "Registro inexistente." << endl;
                }
            else {
                cout << "Funcionário de registro - Nº " << Buscar(numBusca) << "encontrado." << endl;
                }
            break;
        case 3 :
            Alterar();
            break;
        case 4 :
            cout << "Número de registro a ser excluído: ";
            Excluir();      
            break;
        case 5 :
            Listar();
            break;
        case 6 :
            break;
        }
        
        cout << "1- Inserir novo funcionário" << endl;
        cout << "2- Buscar registro do funcionário" << endl;
        cout << "3- Alterar registro" << endl;
        cout << "4- Excluir funcionário" << endl;
        cout << "5- Listar todos os funcionários" << endl;
        cout << "6- Sair" << endl;
        cin >> numOption;
        
    }
    return 0;
}
