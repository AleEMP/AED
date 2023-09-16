
#include <iostream>
using namespace std;
template<class T>
struct nodo {
    T valor;
    nodo<T>* next;
    nodo(T v, nodo<T>* n) {
        valor = v;
        next = n;
    }
};
template <class t>
class pila {
    nodo <t>* top = 0;
public:
    void push(t v) {
        top = new nodo<t>(v, top);
    }
    t pop() {
        t tmp = 0;
        if (top) {
            tmp = top->valor;
            nodo<t>* aux = top;
            top = top->next;
            delete aux;
        }
        return tmp;
    }
    bool vacio() {
        return !top;
    }

};
template<class t>
class cola {
    nodo<t>* head = 0;
    nodo<t>* tail = 0;
public:
    void push(t v) {
        if (!head) {
            tail = new nodo <t>(v,nullptr);
            head = tail;
        }
        else {
            tail->next = new nodo <t>(v, nullptr);
            tail = tail->next;
        }
    }
    t pop() {
        t tmp = 0;
        if (head) {
            tmp = head->valor;
            nodo<t>* aux = head;
            head = head->next;
            delete aux;
        }
        return tmp;
    }
};

int main()
{
    cola<int> p;
    for (int i = 0; i < 4; i++)
    {
        p.push(i);
    }
    for (int i = 0; i < 4; i++)
    {
        cout << p.pop() << endl;
    }
}


