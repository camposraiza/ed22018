#ifndef LISTADUPLA_H
#define LISTADUPLA_H
#include "NoDuplo.h"


class ListaDupla
{
    public:
        ListaDupla();
        ~ListaDupla();
        void imprime(int i);
        void insere(NoDuplo * p);
        int getn(){return n;}
        void setPrimeiro (NoDuplo * p){ primeiro = p;}
        NoDuplo * getprimeiro(){ return primeiro;}
        NoDuplo * getultimo(){ return ultimo;}
    private:
        NoDuplo *primeiro;
        int n;
        NoDuplo *ultimo;
};

#endif // LISTADUPLA_H
