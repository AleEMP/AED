#include <iostream>
#include <stack>
using namespace std;
struct nodo {
	nodo* nodos[2];
	int val;
	nodo(int v,nodo *izq=nullptr,nodo*der=nullptr){
		nodos[0] = izq;
		nodos[1] = der;
		val = v;
	}
};
struct duo {
	int estado=0;
	nodo* punt;
	duo(nodo* p) {
		punt = p;
	}
};
struct tree {
	nodo* root = nullptr;
	stack<duo> stak;
	bool find(nodo**& p, int v) {
		p = &root;
		while (*p and (*p)->val != v)
		{
			
			p = &(*p)->nodos[(*p)->val < v];
		}
		return(*p and (*p)->val == v);
	}
	void push(int v) {
		nodo** p;
		if (find(p, v)) return;
		*p = new nodo(v);
	}
	void fondo(nodo ** &t) {
		t = &root;
		if (root->nodos[1]) {
			t = &(*t)->nodos[1];
		}
		while ((*t)->nodos[0])
		{
			t = &(*t)->nodos[0];
		}
	}
	void del(int v) {
		nodo** p;
		if (!find(p, v)) return;
		nodo* tmp = *p;
		if ((*p)->nodos[0] and (*p)->nodos[1]) {
			nodo** t;
			fondo(t);
			(*p)->val = (*t)->val;
			tmp = *t;
			p = t;
		}
		if ((*p)->nodos[0]) {
			*p = (*p)->nodos[0];
		}
		else {
			*p = (*p)->nodos[1];
		}
		delete tmp;
	}
	void print2() {
		for (nodo**p = &root; *p; p=&(*p)->nodos[0])
		{
			stak.push(*p);
			stak.top().estado = 1;
		}
		while (!stak.empty())
		{
			switch (stak.top().estado)
			{
				case 0:
				{
					stak.top().estado++;
					if(stak.top().punt->nodos[0])
					stak.push(stak.top().punt->nodos[0]);
					break;
				}
				case 1:
				{
					stak.top().estado++;
					cout << stak.top().punt->val << " ";
					break;
				}
				case 2: 
				{
					stak.top().estado++;
					if (stak.top().punt->nodos[1])
						stak.push(stak.top().punt->nodos[1]);
					break;
				}
				case 3: 
				{
					stak.pop();
					break;
				}
			}
		}
		cout << endl;
		
	}
	void preorden(nodo * r) {
		if (!r) {
			return;
		}
		preorden(r->nodos[0]);
		cout << r->val<<" ";
		preorden(r->nodos[1]);
	}
	void print() {
		preorden(root);
		cout << endl;
	}
};
int main()
{
	tree owo;
	owo.push(8); owo.push(10); owo.push(1);
	owo.print2();
	owo.del(8);
	owo.print2();
	owo.push(13);
	owo.print2();
	owo.push(5); owo.push(16); owo.push(3);
	owo.print2();
	
}