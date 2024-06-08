
// CicrcularLinkedList.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;
};

class CircularLinkedList
{
    node* head = nullptr;
    node* tail = nullptr;
public:
    bool find(node**&p,int v) {
        for (p = &head; *p and (*p)->data < v; p=&(*p)->next)
        {
            if (*p == tail and (*p)->data < v) {
                p = &tail->next;
                return 0;
            }
        }
        return (*p and (*p)->data == v);
    }
    void add(int value)
    {
        node** p;
        if (find(p, value)) return;
        if (!head) {
            head = new node;
            head->data = value;
            head->next = head;
            tail = head;
        }
        else if (tail == head) {
            (*p) = new node;
            (*p)->data = value;
            (*p)->next = head;
            tail = (*p);
        }
        else if (p==&head) {
            node* tmp = *p;
            (*p) = new node;
            (*p)->data = value;
            (*p)->next = tmp;
            head = *p;
            tail->next = head;
        }
        else if (p == &tail->next) {
            node* tmp = *p;
            (*p) = new node;
            (*p)->data = value;
            (*p)->next = tmp;
            tail = *p;
        }
        else {
            node* tmp = *p;
            (*p) = new node;
            (*p)->data = value;
            (*p)->next = tmp;
        }
    }

    void del(int value)
    {
        node** p;
        if (!find(p, value)) return;
        if (tail == head) {
            node* tmp = *p;
            delete tmp;
            head = nullptr;
            tail = nullptr;
        }
        else if (p == &head) {
            node* tmp = *p;
            *p = (*p)->next;
            delete tmp;
            head=*p;
            tail->next = head;
        }
        else if (*p == tail) {
            node* tmp = *p;
            node* i = head;
            for (; i->next!=tail ; i=i->next)
            {
            }
            delete tmp;
            (*p) = head;
            tail = i;
        }
        else {
            node* tmp = *p;
            (*p) = (*p)->next;
            delete tmp;
        }
    }

    void print()
    {
        int cont = 0;
        node* ptr = head;
        cout << "head->";
        while (head && cont < 1)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
            if (ptr == head) cont++;
        }
        if (head) cout << ptr->data;
        cout << " <- head \n ";

    }
};

int main()
{
    int ADD[10] = { 2,4,6,8,10,1,3,5,7,9 };
    int DEL[10] = { 9,7,5,3,1,10,8,6,4,2 };
    CircularLinkedList CLL;
    for (int i = 0; i < 10; i++)
    {
        cout << "ADD " << ADD[i] << endl;
        CLL.add(ADD[i]);
        CLL.print();
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "DEL " << DEL[i] << endl;
        CLL.del(DEL[i]);
        CLL.print();
    }
}