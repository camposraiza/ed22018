#include <iostream>
#include <stdlib.h>
#include <math.h>
#ifdef WIN32
 #include <time.h>
#endif // WIN32
#include <fstream>
#include <string.h>
#include <string>
#include "ListaDupla.h"
#include "Hash.h"

using namespace std;

void imprimir (int v[], int n){

    cout << "Imprimindo vetor"<<endl;
    for(int i = 0; i< n; i++){
        cout << "V["<<i<<"] = "<< v[i]<< endl;
    }
    cout<<endl;
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

///Quicksort Recursivo

int particiona(int v[],int l, int r){

    int pivo = r;

    int i = l;
    int j = r-1;

    while(i<=j){
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
    int aux = v[i];
        v[i] = v[pivo];
        v[pivo] = aux;
    return i;
}

void quicksort_aux(int v[],int l, int r){

    if(r-l <= 0)
        return;
    int p = particiona(v,l,r);
    quicksort_aux(v,l,p-1);
    quicksort_aux(v,p+1,r);

}

void quicksort(int v[],int l, int r){

    cout <<"Ordenando com Quicksort"<<endl;
    quicksort_aux(v,l,r);
    cout <<endl;
}

///Quicksort_Lista

NoDuplo * particiona_lista(ListaDupla * lista,NoDuplo * l, NoDuplo * r){
    /*
    int pivo = r;

    int i = l;
    int j = r-1;

    while(i<=j){
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
    int aux = v[i];
        v[i] = v[pivo];
        v[pivo] = aux;
    return i;*/return r;
}

void quicksort_aux_lista(ListaDupla * lista,NoDuplo * l, NoDuplo * r){


    if(r=l)
        return;
    NoDuplo * p = particiona_lista(lista,l,r);
    quicksort_aux_lista(lista,l,r->getAnt());
    quicksort_aux_lista(lista,l->getProx(),r);

}

void quicksort_lista(ListaDupla * lista,NoDuplo * l, NoDuplo * r){

    cout <<"Ordenando com Quicksort"<<endl;
    quicksort_aux_lista(lista,l,r);
    cout <<endl;
}

///Quicksort Mediana  MUDAR FUNÇÃO MEDIANA

int mediana(int v[],int l, int r,int i){

    srand(time(NULL));//mediana aleatoria
    int j = rand()%(r+1);
    int k = rand()%(r+1);
    int f = rand()%(r+1);
    int aleatorio[i];
    for(int j = 0;j < i;j++){
        aleatorio[j] = rand()%(r+1);
    }

    if(v[j]>v[j]){
        int aux = v[k];
        v[k] = v[j];
        v[j] = aux;
    }
    if(v[j]>v[f]){
        int aux = v[f];
        v[f] = v[j];
        v[j] = aux;
    }
    if(v[k]>v[f]){
        int aux = v[k];
        v[k] = v[f];
        v[f] = aux;
    }
    int aux = v[r];
        v[r] = v[k];
        v[k] = aux;

    return r;
}

int particiona_mediana(int v[],int l, int r){

    int pivo = mediana(v,l,r,3);

    int i = l;
    int j = r-1;

    while(i<=j){
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
    int aux = v[i];
        v[i] = v[pivo];
        v[pivo] = aux;
    return i;
}

void quicksort_aux_mediana(int v[],int l, int r){

    if(r-l <= 0)
        return;
    int p = particiona(v,l,r);
    quicksort_aux_mediana(v,l,p-1);
    quicksort_aux_mediana(v,p+1,r);

}

void quicksort_mediana(int v[],int l, int r){

    cout <<"Ordenando com Quicksort Mediana"<<endl;
    quicksort_aux_mediana(v,l,r);
    cout <<endl;
}

///Quicksort insertion ARRUMANDO FUNÇÃO

void quicksort_aux_insertion(int v[],int l, int r){

    int tamanho = r-l+1;
    if( tamanho<= 10){
        insertion(v,tamanho);
        return;
    }
    int p = particiona(v,l,r);
    quicksort_aux_insertion(v,l,p-1);
    quicksort_aux_insertion(v,p+1,r);

}

void quicksort_insertion(int v[],int l, int r){

    cout <<"Ordenando com Quicksort Insertion"<<endl;
    quicksort_aux_insertion(v,l,r);
    cout <<endl;
}
/*
struct Lista_dados{

    int questionid;
    string userid;
    string score;
    string data;
    string title;
    string body;

};*/

int main()
{

    srand(time(NULL));

///Teste

    int tamanho = 10;
    int v[tamanho]={8,7,9,4,5,6,8,1,2,3};
    imprimir(v,tamanho);

    bubble(v,tamanho);
    imprimir(v,tamanho);

    int x[tamanho]={8,7,9,4,5,6,8,1,2,3};
    insertion(x,tamanho);
    imprimir(x,tamanho);

    int z[tamanho]={8,7,9,4,5,6,8,1,2,3};
    quicksort(z,0,tamanho-1);/// mudar para entrada_dados
    imprimir(z,tamanho);

    int w[tamanho]={8,7,9,4,5,6,8,1,2,3};
    quicksort_mediana(w,0,tamanho-1);
    imprimir(z,tamanho);

///Abre e carrega na memoria o arquivo Questions

    ifstream arquivo;

    arquivo.open("Questions.csv");

    ListaDupla l;

    NoDuplo * p = new NoDuplo;

    clock_t t0, tf;
    double tempo_gasto;
    t0 = clock();

    string linha;
    if(arquivo.is_open()){
        getline(arquivo,linha);//para não aparecer a linha 0
        for(int n = 0;n<2; n++){

            string converter;
            getline(arquivo,converter,',');
            p->questionid = atoi(converter.c_str());//converte string para inteiro
            //deletar
            getline(arquivo,p->userid,',');
            getline(arquivo,p->data,',');
            getline(arquivo,p->score,',');

            ///title

            int i = 0;
            string tratar;
            bool verifica = false;
            getline(arquivo,tratar,',');

            if(tratar[i] == '"' && tratar[i+1] != '"')
            {
                p->title = tratar;
                while(!verifica)
                {
                    getline(arquivo,tratar,',');
                    if(tratar[tratar.size()-1] == '"' && tratar[tratar.size()-2] !='"') //penultimo character e o anterior dele
                    {
                        verifica = true;
                    }
                    p->title = p->title + tratar;
                }
            }
            else
                p->title = tratar;

            /// body

            i = 0;
            verifica = false;
            getline(arquivo,tratar,'<');

            if(tratar[i] == '"'){
                p->body = tratar;
                while(!verifica)
                {
                    getline(arquivo,tratar);

                    if((tratar[tratar.size()-1] == '"') && (tratar[tratar.size()-2] !='"')){//final do <p>"
                        verifica = true;
                    }
                    p->body= p->body + tratar;
                }
            }
            else{
                verifica = false;
                p->body = tratar;
                while(!verifica)
                {
                    getline(arquivo,tratar);
                    if(tratar[tratar.size()-1] == '>' && tratar[tratar.size()-2] =='p')//final do <p>
                    {
                        verifica = true;
                    }
                    p->body= p->body + tratar;
                }
            }

            l.insere(p);
            l.imprime(n);
            p = new NoDuplo;
        }
        arquivo.close();
    }
    else{
        cout<<"Erro ao abrir o arquivo Questions!"<<endl;
    }

    tf = clock();
    tempo_gasto = ( (double) (tf - t0) ) / CLOCKS_PER_SEC;
    cout<<"tempo: "<<tempo_gasto<< endl;

///Endereçamento - Sondagem Linear (hash)

    int y = 10; ///Fazendo
    int a;
    Hash h(y);
    cout <<"cheguei 2";
    a=h.func_insere_hash_linear(y,8);
    cout << a;


///Lembrar de adicionar arquivo de saida

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
