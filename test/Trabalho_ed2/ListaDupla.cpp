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

void ListaDupla::insereInicio(float val)
{
    NoDuplo *novo = new NoDuplo();
    novo->setInfo(val);
    novo->setAnt(NULL);
    novo->setProx(primeiro);

    if(primeiro != NULL)
        primeiro->setAnt(novo);
    else
        ultimo = novo;

    primeiro = novo;
    n++;
}

void ListaDupla::imprime()
{
    cout << "LISTA DUPLA: ";
    if(n == 0) cout << "Vazia!" << endl;
    for(NoDuplo *p = primeiro; p != NULL; p = p->getProx())
        cout << p->getInfo() << " ";
    cout << endl;
}
