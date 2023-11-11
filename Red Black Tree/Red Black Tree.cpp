#include <iostream>

struct nodo {
    int val;
    nodo* nodes[2] = { 0,0 };
    bool rojo=1;
    nodo * up;
    nodo(int v,nodo *u=0) {
        val = v;
        up = u;
    }
    int owo() {
        if (!up) return 0;
        return up->val;
    }
};

struct RBTree {
    nodo* root=0;
    bool find(int val,nodo**&p, nodo*& q)
    {
        p = &root;
        q = 0;
        while (*p and val != (*p)->val)
        {
            q = *p;
            p = &((*p)->nodes[val > (*p)->val]);
        }
        return !!(*p);
    }
    void tio_rojo(nodo*& q, bool tio) {
        cambio(q);
        cambio(q->up);
        cambio(q->up->nodes[tio]);
    }

    void linea_der(nodo*& q) {
        if (q->up->up) { // bisawelo?
            if (q->up->up->val < q->up->val) { // awelo der?
                q->up->up->nodes[1] = q; //movemo enlace
                nodo* tmp = q->up->up;
                q->up->nodes[1] = q->nodes[0];//awelo der -> P izq
                if (q->nodes[0]) {
                    q->nodes[0]->up = q->up; //P izq. up -> awelo
                }
                q->up->up = q;
                q->nodes[0] = q->up;// P izq -> awelo
                q->up = tmp; // P up -> bisawelo;
            }
            else {// awelo izq?
                q->up->up->nodes[0] = q; //movemo enlace
            }
        }
        else {
            root = q;
            q->up->nodes[1] = q->nodes[0];//awelo der -> P izq
            if (q->nodes[0]) {
                q->nodes[0]->up = q->up; //P izq. up -> awelo
            }
            q->up->up = q;
            q->nodes[0] = q->up;// P izq -> awelo
            q->up = 0; // P up -> bisawelo;
        }
        cambio(q);
        cambio(q->nodes[0]);
    }
    void linea_izq(nodo*& q)
    {
        if (q->up->up) { // bisawelo?
            if (q->up->up->val < q->up->val) { // awelo der?
                q->up->up->nodes[1] = q; //movemo enlace
                nodo* tmp = q->up->up;
                q->up->nodes[0] = q->nodes[1];//awelo der -> P izq
                if (q->nodes[1]) {
                    q->nodes[1]->up = q->up; //P izq. up -> awelo
                }
                q->up->up = q;
                q->nodes[1] = q->up;// P izq -> awelo
                q->up = tmp; // P up -> bisawelo;
            }
            else {// awelo izq?
                q->up->up->nodes[0] = q; //movemo enlace
            }
        }
        else {
            root = q;
            q->up->nodes[0] = q->nodes[1];//awelo der -> P izq
            if (q->nodes[1]) {
                q->nodes[1]->up = q->up; //P izq. up -> awelo
            }
            q->up->up = q;
            q->nodes[1] = q->up;// P izq -> awelo
            q->up = 0; // P up -> bisawelo;
        }
        cambio(q);
        cambio(q->nodes[1]);
    }

    void tio_negro(nodo*& q, int c) {

            if (c==1)//linea derecha
            {
                linea_der(q);
            }
            if (c== 2) //linea izq
            {
                linea_izq(q);
            }
            if (c == 3) // triangulo der
            {
                q->nodes[0]->up = q->up;//hijo up -> abuelo
                q->up->nodes[1] = q->nodes[0];// abuelo der -> hijo
                q->nodes[0] = q->up->nodes[1]->nodes[1];//padre der -> hijo der
                q->up = q->up->nodes[1];//padre up-> hijo
                q->up->nodes[1] = q;// hijo der -> padre
                if (q->nodes[0]) {
                    q->nodes[0]->up = q;
                }
                q = q->up;
                linea_der(q);
            }
            if (c == 4)
            {
                q->nodes[1]->up = q->up;//hijo up -> abuelo
                q->up->nodes[0] = q->nodes[1];// abuelo der -> hijo
                q->nodes[1] = q->up->nodes[0]->nodes[0];//padre der -> hijo der
                q->up = q->up->nodes[0];//padre up-> hijo
                q->up->nodes[0] = q;// hijo der -> padre
                if (q->nodes[1]) {
                    q->nodes[1]->up = q;
                }
                q = q->up;
                linea_izq(q);
            }

    }
    void cambio(nodo * p) {
        if (p->rojo) {
            p->rojo = 0;
        }
        else {
            p->rojo = 1;
        }
    }
    void supervisor(nodo *&q) {
        root->rojo = 0; //root -> negro 
        while (q and q->up) 
        {
            /*if (q) //popa?
            { */
                if (q->rojo) //popa rojo?
                { 
                    if (q->up) //awelo?
                    {
                        if (q->val < q->up->val) // popa izq? owo
                        { 
                            if (q->nodes[0]) // tu hijo es izq?
                            { 
                                if (q->nodes[0]->rojo) //tu hijo es rojo?
                                {
                                    if (q->up->nodes[1]) //tio der?
                                    {
                                        if (q->up->nodes[1]->rojo)//tio rojo? 
                                        {
                                            tio_rojo(q, 1);
                                        }
                                        else
                                        {
                                            tio_negro(q,2);
                                            //linea izq
                                        }
                                    }
                                    else //nay tio -> tio negro
                                    {
                                        tio_negro(q,2);
                                        //linea izq
                                    }
                                }
                            }
                            else // tu hijo es der?
                            {
                                if (q->nodes[1]) 
                                {
                                    if (q->nodes[1]->rojo)
                                    {
                                        if (q->up->nodes[1]) //tio der?
                                        {
                                            if (q->up->nodes[1]->rojo)//tio rojo? 
                                            {
                                                tio_rojo(q, 1);
                                            }
                                            else
                                            {
                                                tio_negro(q,4);
                                                //triangulo izq
                                            }
                                        }
                                        else //nay tio -> tio negro
                                        {
                                            tio_negro(q,4);
                                            //triangulo izq
                                        }
                                    }
                                }
                            }
                                
                        }
                        else //popa es der
                        {
                            if (q->nodes[0]) // tu hijo es izq?
                            {
                                if (q->nodes[0]->rojo) //tu hijo es rojo?
                                {
                                    if (q->up->nodes[0]) //tio izq? 
                                    { 
                                        if (q->up->nodes[0]->rojo) // tio rojo?
                                        {
                                            tio_rojo(q,0);
                                        }
                                        else
                                        {
                                            tio_negro(q,3);
                                            //caso triangulo derecha
                                        }

                                    }
                                    else // null es negro :3
                                    {
                                        tio_negro(q,3);
                                        //caso triangulo derecha
                                    }
                                }
                            }
                            else //hijo derecha 
                            {
                                if (q->nodes[1])
                                {
                                    if (q->nodes[1]->rojo) // hijoo es rojo?
                                    {
                                        if (q->up->nodes[0]) //tio der?
                                        {
                                            if (q->up->nodes[0]->rojo)//tio rojo? 
                                            {
                                                tio_rojo(q, 1);
                                            }
                                            else
                                            {
                                                tio_negro(q,1);
                                                //linea derecha
                                            }
                                        }
                                        else //nay tio -> tio negro
                                        {
                                            tio_negro(q,1);
                                            //linea derecha
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            q = q->up;
        }
        root->rojo = 0; //root -> negro
    }
    void insert(int val) 
    {
        nodo** p;
        nodo* q;
        if (find(val, p, q)) return;
        (*p) = new nodo(val,q);
        supervisor(q);
    }
    void print() {
        inOrder(root);
    }
    void inOrder(nodo* r) {
        if (!r) return;
        inOrder(r->nodes[0]);
        if (r->rojo)
            std::cout << r->val << "-" << r->owo() << "-R  ";
        else
            std::cout << r->val << "-" << r->owo() << "-B  ";
        inOrder(r->nodes[1]);
    }
};

int main()
{
    RBTree owo;
    owo.insert(50);
    owo.insert(40);
    owo.insert(48);
    owo.print();
    return 0;
}
