#ifndef HASH_H
#define HASH_H


class Hash
{
    public:
        Hash(int tam);
        ~Hash();
        int func_hash_linear(int k,int n);
        int func_insere_hash_linear (int n,int k);

    private:
        int n ;
        int *v;
};

#endif // HASH_H
