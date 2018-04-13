#include <iostream>

using namespace std;

void construirHeep(int vet[], int tamanhovet, int indice)
{
    int rami, val;
    val = vet[indice];
    while(indice<tamanhovet/2)
    {
        rami = 2 * indice + 1;
        if(rami < tamanhovet-1 && vet[rami] < vet[rami+1])
        {
            rami++;
        }
        if(val>vet[rami])
        {
            break;
        }
        vet[indice] = vet[rami];
        indice = rami;
    }
    vet[indice] = val;
}

void heapSort(int vet[], int t)
{
    int i, aux;
    for(i=t/2;i>=0;i--)
    {
        construirHeep(vet,t,i);
    }
    while(t>0)
    {
        aux = vet[0];
        vet[0] = vet[t-1];
        vet[t-1] = aux;
        construirHeep(vet,--t,0);
    }
}

void imprime(int vet[], int t)
{
    for(int i=0;i<t;++i)
    {
        cout << "[" << vet[i] << "] ";
    }
}


int main()
{
    int tam=12;
    //cout << "Digite o tamanho do vetor: ";
    //cin >> tam;
    int vetor[tam]={23, 32, 65, 7, 8, 98, 123, 34, 92, 54, 33, 45};
    /*for(int i=0;i<tam;++i)
    {
        cout << "Digite o valor de " << i << ": ";
        cin >> vetor[i];
    }*/
    cout << "Vetor digitado:" << endl;
    imprime(vetor, tam);
    heapSort(vetor, tam);
    cout << endl << "Vetor ordenado com HeapSort: " << endl;
    imprime(vetor, tam);
    return 0;
}
