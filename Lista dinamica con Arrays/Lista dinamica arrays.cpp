#include <iostream>
using namespace std;
template <class t>
struct nodo {
    t array[5];
    t* h_interno = array;
    nodo<t>* next;
    nodo(t v, nodo<t>* t=NULL) {
        for (int i = 0; i < 5; i++)
        {
            *(array + i) = 0;
        }
        *array = v;
        next = t;
    }
};
template <typename t>
struct pila {
    nodo<t>* h_total = 0;
    void push(t v) {
        if (h_total) {
            if (h_total->h_interno == h_total->array + 4) {
                h_total = new nodo<t>(v, h_total);
            }
            else {
                h_total->h_interno++;
                *(h_total->h_interno) = v;
            }
        }
        else {
            h_total = new nodo<t>(v, h_total);
        }
    }
    t pop() {
        t temp = 0;
        if (h_total) {
            temp = *(h_total->h_interno);
            *(h_total->h_interno) = 0;
            if (h_total->h_interno == h_total->array) {
                nodo<t>* ewe = h_total;
                h_total = h_total->next;
                delete ewe;
                
            }
            else {
                h_total->h_interno--;
            } 
        }
        return temp;
    }
    void imprimir() {
        nodo<t>* aux = h_total;
        cout << "HEAD ->";
        while (aux) {
            cout << "{ ";
            for (int i = 0; i < 5; i++)
            {
                cout << aux->array[i] << ", ";
            }
            cout << "} -> ";
            aux = aux->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    pila<int> owo;

    /*
    cout<<owo.pop()<<endl;
    owo.imprimir();
    */
    
    for (int i = 1; i < 13; i++)
    {
        owo.push(i);
    }
    owo.imprimir();
    for (int i = 0; i < 8; i++)
    {
        cout << owo.pop() << endl;
    }
    
    owo.imprimir();
    
}
