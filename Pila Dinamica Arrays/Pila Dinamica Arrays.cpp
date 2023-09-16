#include <iostream>
using namespace std;
template <class t>
struct nodo {
    t arr[5];
    nodo<t>* next;
    nodo(t v, nodo<t>* t = NULL) {
        for (int i = 0; i < 5; i++)
        {
            *(arr + i) = 0;
        }
        *arr = v;
        next = t;
    }
};
template <typename t>
struct pila {
    nodo<t>* TOP = 0;
    t* top;
    void push(t v) {
        if (TOP) {
            if (top == TOP->arr + 4) {
                TOP = new nodo<t>(v, TOP);
                top = TOP->arr;
            }
            else {
                top++;
                *top = v;
            }
        }
        else {
            TOP = new nodo<t>(v, TOP);
            top = TOP->arr;
        }
    }
    t pop() {
        t temp = 0;
        if (TOP) {
            temp = *top;
            *top = 0;
            if (top == TOP->arr) {
                nodo<t>* ewe = TOP;
                TOP = TOP->next;
                top = TOP->arr+4;
                delete ewe;

            }
            else {
                top--;
            }
        }
        return temp;
    }
    void imprimir() {
        cout << "HEAD -> ";
        for (nodo<t>* i = TOP; i; i = i->next)
        {
            t* punterito = i->arr;
            cout << "{";
            for (; punterito != i->arr + 5; punterito++) {
                cout << *(punterito) << ",";
            }
            cout << "} -> ";
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
    for (int i = 0; i < 4; i++){
        owo.pop();
    }

    owo.imprimir();

}