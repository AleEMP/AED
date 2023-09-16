#include <iostream>
using namespace std;
template <class t>
struct nodo {
    t arr[5];
    nodo<t>* next;
    nodo(t v, nodo<t>* n = NULL) {
        for (int i = 0; i < 5; i++)
        {
            *(arr + i) = 0;
        }
        *arr = v;
        next = n;
    }
};
template <class t>
struct cola {
    nodo<t>* HEAD = NULL;
    t* head;
    t* tail;
    nodo<t>* TAIL = HEAD;
    void push(t v) {
        if (HEAD) {
            if (tail == TAIL->arr + 4) {
                TAIL->next = new nodo<t>(v);
                TAIL = TAIL->next;
                tail = TAIL->arr;
            }
            else {
                tail++;
                *tail = v;
            }
        }
        else {
            HEAD = new nodo<t>(v);
            TAIL = HEAD;
            head = HEAD->arr;
            tail = head;
        }
    }
    t pop() {
        t temp = 0;
        if (HEAD) {
            temp = *head;
            *head = 0;
            if (head == HEAD->arr+4) {
                nodo<t>* aux = HEAD;
                HEAD = HEAD->next;
                head = HEAD->arr;
                delete aux;
            }
            else {
                head++;
            }
        }
        return temp;
    }
    void imprimir() {
        cout << "HEAD -> ";
        for (nodo<t>* i = HEAD; i; i = i->next)
        {
            t *punterito = i->arr;
            cout << "{";
            for (; punterito != i->arr + 5; punterito++) {
                cout << *(punterito)<<",";
            }
            cout << "} -> ";
        }
        cout <<"NULL" << endl;
    }

};
int main()
{
    cola<int> owo;
    for (int i = 1; i < 11; i++)
    {
        owo.push(i);
    }
    owo.imprimir();
    for (int i = 0; i < 11; i++)
    {
        owo.pop();
    }
    
    owo.imprimir();
    for (int i = 7; i < 11; i++)
    {
        owo.push(i);
    }
    owo.imprimir();
}