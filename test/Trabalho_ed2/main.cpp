#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <string>
#include "ListaDupla.h"

using namespace std;


void imprimir (int v[], int n){

    cout << "Imprimindo vetor"<<endl;
    for(int i = 0; i< n; i++){
        cout << "V["<<i<<"] = "<< v[i]<< endl;
    }
    cout <<endl;
}

void insertion (int v[], int n){

    cout << "Ordenando com InsetionSort" <<endl;

    int j;
    int pivo;

    for(int i = 0; i < n; i++){

        pivo = v[i];
        j=i-1;

        while( j >= 0 && v[j] > pivo){
            v[j+1] = v[j];
            j--;
        }
        v[j+1]= pivo;
    }
    cout <<endl;
}


void bubble (int v[], int n){

    cout <<"Ordenando com BubbleSort"<<endl;

    int aux;

    for(int i = 0; i < n; i++){

        for(int j = 0; j< n-1; j++){

            if(v[j] > v[j+1]){
                aux = v[j];
                v[j]= v[j+1];
                v[j+1] = aux;
            }
        }
    }
    cout <<endl;
}

int particiona(int v[],int l, int r){

    int pivo = (r+l)/2;

    int i = l;
    int j = r;

    while((i < pivo && j > pivo)){  ///embora o j pode estar < j o i pode não estar

        if(v[i] > v[pivo]){
            if(v[j] < v[pivo]){
                int aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
            else
                j--;
        }
        else
            i++;
    }
    return i;
}

void quicksort(int v[],int l, int r){

    if(r-l <= 0)
        return;
    int p = particiona(v,l,r);
    quicksort(v,l,p-1);
    quicksort(v,p+1,r);

}

/*
NoDuplo * mediana(ListaDupla *l){

}

NoDuplo * particiona(ListaDupla *l, NoDuplo * ini, NoDuplo * fim){

    NoDuplo * pivo;



}

void Quicksort (ListaDupla *l, NoDuplo * ini, NoDuplo * fim){


    NoDuplo * p = particiona(l,ini,fim);
    Quicksort (l,ini ,p->getAnt());
    Quicksort (l,p->getProx(),fim );

}
*/

int main()
{

     srand(time(NULL));

///Teste

    int tamanho = 10;
    int v[tamanho]={8,7,9,4,5,6,8,1,2,3};

    imprimir(v,tamanho);
    //bubble(v,tamanho);
    //insertion(v,tamanho);
    quicksort(v,0,tamanho-1);/// mudar para entrada_dados
    imprimir(v,tamanho);




/* ignorar
    ListaDupla l;
    l.insereInicio(3);
    l.insereInicio(2);
    l.insereInicio(4);
    l.insereInicio(1);
    l.insereInicio(5);
    NoDuplo * ini = l->primeiro;
    NoDuplo * fim = l->ultimo;
    Quicksort(&l,ini,fim);
*/

///Abre e carrega o na memoria arquivo Tags

    ifstream tags;

    tags.open("Tags.csv");

    string all_tags[2][100000];

    if(tags.is_open()){
        getline(tags,all_tags[0][0]);//para não aparecer a linha 0
        for(int i = 0;tags.eof(); i++){
            getline(tags,all_tags[0][i],',');
            getline(tags,all_tags[1][i]);
        }
        tags.close();
    }
    else{
        cout<<"Erro ao abrir o arquivo!"<<endl;
        exit(1);
    }


///Abre o arquivo de entrada

    ifstream entrada;

    entrada.open("entrada");

    int quant_dados;
    string dados;

    if(entrada.is_open()){
        getline(entrada,dados);
        quant_dados = atoi(dados.c_str());
        cout << "Valor de N usado: " << quant_dados<<endl<<endl;
    }
    else{
        cout<<"Erro ao abrir o arquivo entrada.txt!"<<endl;
        exit(1);
    }
    entrada.close();

///Teste do buffer
    /*
    int x;
    string buffer [2][quant_dados];
    cout << "Id | Tags" << endl;
    for(int i = 0; i<quant_dados; i++){
        x = rand()%(quant_dados+1);
        cout << buffer[0][x]<<" | ";
        cout << buffer[1][x]<< endl;
    }

    cout << endl;
    cout << "Programa encerrado!"<< endl;
    */

    return 0;
}
