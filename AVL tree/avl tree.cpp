#include <stack>
#include <iostream>
using namespace std;

struct nodo 
{
    int altura;
    int val;
    nodo* nodes[2] = { 0,0 };
    nodo(int v, int h=1)
    {
        val = v;
        altura = h;
    }
};

struct arbol 
{
    nodo* root=0;
    bool random = 0;
    bool find(int v,nodo **& p, stack<nodo**> &stack)
    {
        p = &root;
        
        while ((*p) and (*p)->val != v )
        {
            stack.push(p);
            p = &((*p)->nodes[v > (*p)->val]);
            
        }
        return *p && (*p)->val == v;
    }
    void balanced(stack<nodo**> *pila)
    {
        int a, b, c;
        int ant=0;
        while (!(*pila).empty()) 
        {
            nodo** q = (*pila).top();
            if ((*q)->nodes[0]) 
            {
                a = (*q)->nodes[0]->altura;
            }
            else a = 0;
            if ((*q)->nodes[1])
            {
                b = (*q)->nodes[1]->altura;
            }
            else b = 0;
            (*q)->altura = max(a, b) + 1;

            

            if ((*q)->nodes[0] and (*q)->nodes[1]) {
                c = (*q)->nodes[1]->altura - (*q)->nodes[1]->altura;
            }
            else if(!(*q)->nodes[0] and (*q)->nodes[1]) {
                c = (*q)->nodes[1]->altura;
            }
            else if (!(*q)->nodes[1] and (*q)->nodes[0]) {
                c= -((*q)->nodes[0]->altura);
            }
            else {
                c = 0;
            }
            
            switch (c)
            {
            case 2:
                if (ant == 1) {
                    nodo* temp = (*q); //temp -> c
                    (*q) = temp->nodes[1];// *q->b
                    temp->nodes[1] = (*q)->nodes[0]; //c der -> br
                    (*q)->nodes[0] = temp; // b izq ->c
                }
                if (ant == -1) {
                    nodo* temp = (*q);//temp -> a
                    (*q) = temp->nodes[1]->nodes[0]; //*q->b
                    temp->nodes[1]->nodes[0] = (*q)->nodes[1]; //c izq-> br
                    (*q)->nodes[1] = temp->nodes[1];// b der -> c
                    temp->nodes[1] = (*q)->nodes[0];//a der -> bl
                    (*q)->nodes[0] = temp; //b izq -> a
                }
            case -2:
                if (ant == 1) {
                    nodo* temp = (*q);//temp -> c
                    (*q) = temp->nodes[0]->nodes[1]; //*q->b
                    temp->nodes[0]->nodes[1] = (*q)->nodes[0]; //a der-> bl
                    (*q)->nodes[0] = temp->nodes[0];// b izq -> a
                    temp->nodes[0] = (*q)->nodes[1];//c izq -> br
                    (*q)->nodes[1] = temp; //b der -> c
                }
                if (ant == -1) {
                    nodo* temp = (*q); //temp -> c
                    (*q) = temp->nodes[0];// *q->b
                    temp->nodes[0] = (*q)->nodes[1]; //c iz -> br
                    (*q)->nodes[1] = temp; // b der ->c
                }
            }
            ant = c;
            (*pila).pop();
        }  
    }
    int max(int x, int y)
    {
        if (x > y) return x;
        else return y;
    }
    void push(int v)
    {
        stack<nodo**> pila;
        stack <nodo**> *pnt_pila=&pila;
        nodo** p;
        if (find(v, p, pila)) return;
        (*p) = new nodo(v);
        balanced(pnt_pila);
    }
    nodo** major(int v, nodo **q) {
        random = !random;
        q = &((*q)->nodes[!random]);
        while ((*q)->nodes[random])
            q = &((*q)->nodes[random]);
        return q;
    }
    /*void remove(int v)
    {
        stack<nodo**> stack;
        nodo** p;
        if (!find(v, p, stack)) return;
        if((*p)->nodes[0] and (*p)->nodes[1])
        {
            nodo** q = major(v, p);
            (*p)->val = (*q)->val;
            p = q;
        }
        nodo* tmp = (*p);
        (*p) = (*p)->nodes[(*p)->nodes[0] == 0];
        delete tmp;
    }*/
    void InOrder(nodo* n)
    {
        if (!n) return;
        InOrder(n->nodes[0]);
        cout << n->val << "";
        cout << "(" << n->altura << ") ";
        InOrder(n->nodes[1]);
    }

    void Print()
    {
        InOrder(root);
        cout << endl;
    }
};

int main()
{
    arbol t;
    t.push(50); t.push(30); t.push(20);
    t.push(80); t.push(55); t.push(11);
    t.push(35); t.push(5);  t.push(14);


    t.Print();
}

