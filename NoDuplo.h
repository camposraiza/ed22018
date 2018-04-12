#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#ifndef NODUPLO_H_INCLUDED
#define NODUPLO_H_INCLUDED


using namespace std;


class NoDuplo
{
    public:
        NoDuplo() {}
        ~NoDuplo() {}
        NoDuplo* getProx() { return prox; }
        NoDuplo* getAnt() { return ant; }
        void setProx(NoDuplo *p) { prox = p; }
        void setAnt(NoDuplo *p) { ant = p; }

        int questionid;
        string userid;
        string score;
        string data;
        string title;
        string body;

    private:

        NoDuplo *prox;
        NoDuplo *ant;
};

#endif // NODUPLO_H_INCLUDED
