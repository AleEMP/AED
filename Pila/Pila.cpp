
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

int main()
{
    pila<int> p;
    for (int i = 0; i < 10; i++)
    {
        p.push(i);
    }
    while (!p.vacio()) {
        cout << p.pop() << endl;
    }
}


