#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    primeiro = NULL;
    n = 0;
    ultimo = NULL;
}

ListaDupla::~ListaDupla()
{
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaDupla::insere(NoDuplo * p)
{
    NoDuplo *novo = p;

    if(primeiro != NULL){
        novo->setAnt(ultimo);
        novo->setProx(NULL);
        ultimo->setProx(novo);
    }
    else{
        novo->setAnt(NULL);
        novo->setProx(NULL);
        primeiro = novo;
    }
    ultimo = novo;
    n++;
}

void ListaDupla::imprime(int i)
{
    NoDuplo * p = primeiro;
    if(i<=n){
        for(int j = 0; j!= i; j++){
            p = p->getProx();
        }
        cout<<endl<<"No "<<i<<endl;
        cout<<"Questionid  "<<p->questionid<<endl;
        cout<<"Userid  "<<p->userid<<endl;
        cout<<"data  "<<p->data<<endl;
        cout<<"score  "<<p->score<<endl;
        cout<<"title  "<<p->title<<endl;
        cout<<"body  "<<p->body<<endl;
    }
    else{
        cout<<endl<<"indice invalido"<<endl;
    }
}
