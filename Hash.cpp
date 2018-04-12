#include "Hash.h"
#include <iostream>

using namespace std;

Hash::Hash(int tam)
{
    n = tam;
    v = new int[n];
}

Hash::~Hash()
{
    //dtor
}

int Hash::func_hash_linear(int k,int n){
    return k% n;
}

int Hash::func_insere_hash_linear (int n,int k){

    int i = 0;
    int f = func_hash_linear(k,i);

    while(i!=n){
        if(v[f] == 0){
           v[f] = k;
           cout << endl<<"cheguei"<<endl;
           return f;
        }
        else{
            i ++;
        }
        f = func_hash_linear(k,i);
    }
    cout<<"A hash esta cheia!"<<endl;

    return -1;
}
