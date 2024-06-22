#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct nodo {
	nodo* nodos[2];
	int h = 1;
	int val;
	int espacio = 0;
	int nivel = 0;
	int padre=0;
	bool dir;
	nodo(int v, nodo* izq = nullptr, nodo* der = nullptr) {
		nodos[0] = izq;
		nodos[1] = der;
		val = v;
	}
};
struct avl {
	nodo* root = nullptr;

	bool find(nodo**& p, int v, stack <nodo**>& stk) {
		for (p = &root; *p and (*p)->val != v; p = &(*p)->nodos[(*p)->val < v])
		{
			stk.push(p);
		}
		return (*p and (*p)->val == v);
	}
	int max(int a, int b) {
		return a < b ? b : a;
	}
	void g_d(nodo**& t) {
		nodo* tmp = *t;
		*t = tmp->nodos[0];
		tmp->nodos[0] = (*t)->nodos[1];
		(*t)->nodos[1] = tmp;
		tmp->h = max(tmp->nodos[0] ? tmp->nodos[0]->h : 0, tmp->nodos[1] ? tmp->nodos[1]->h : 0) + 1;
		(*t)->h = max((*t)->nodos[0] ? (*t)->nodos[0]->h : 0, tmp->h) + 1;
	}
	void g_i(nodo**& t) {
		nodo* tmp = *t;
		*t = tmp->nodos[1];
		tmp->nodos[1] = (*t)->nodos[0];
		(*t)->nodos[0] = tmp;
		tmp->h = max(tmp->nodos[0] ? tmp->nodos[0]->h : 0, tmp->nodos[1] ? tmp->nodos[1]->h : 0) + 1;
		(*t)->h = max((*t)->nodos[1] ? (*t)->nodos[1]->h : 0, tmp->h) + 1;
	}
	void balanceo(stack <nodo**>& stk) {
		int a = 0, b = 0, alt_iz, alt_der;
		while (!stk.empty()) {
			//actualizar altura
			if ((*stk.top())->nodos[0])
			{
				alt_iz = (*stk.top())->nodos[0]->h;
			}
			else {
				alt_iz = 0;
			}
			if ((*stk.top())->nodos[1]) {
				alt_der = (*stk.top())->nodos[1]->h;
			}
			else {
				alt_der = 0;
			}
			(*stk.top())->h = max(alt_iz, alt_der) + 1;

			//ver si hay desvalanceo
			if ((*stk.top())->nodos[0] and (*stk.top())->nodos[1]) {
				a = (*stk.top())->nodos[0]->h - (*stk.top())->nodos[1]->h;
			}
			else if (!(*stk.top())->nodos[0] and (*stk.top())->nodos[1]) {
				a = -(*stk.top())->nodos[1]->h;
			}
			else if ((*stk.top())->nodos[0] and !(*stk.top())->nodos[1]) {
				a = (*stk.top())->nodos[0]->h;
			}
			else {
				a = 0;
			}

			switch (a)
			{
			case 2:
				if (b == 1) {
					g_d(stk.top());
				}
				if (b == -1) {
					nodo* tmp = (*stk.top())->nodos[0];
					(*stk.top())->nodos[0] = (tmp)->nodos[1];
					tmp->nodos[1] = (*stk.top())->nodos[0]->nodos[0];
					(*stk.top())->nodos[0]->nodos[0] = tmp;
					g_d(stk.top());
				}
				break;
			case -2:
				if (b == 1) {
					nodo* tmp = (*stk.top())->nodos[1];
					(*stk.top())->nodos[1] = (tmp)->nodos[0];
					tmp->nodos[0] = (*stk.top())->nodos[1]->nodos[1];
					(*stk.top())->nodos[1]->nodos[1] = tmp;
					g_i(stk.top());
				}
				if (b == -1) {
					g_i(stk.top());
				}
				break;
			}
			b = a;
			stk.pop();
		}
	}
	void push(int v) {
		stack <nodo**> stk;
		nodo** p;
		if (find(p, v, stk)) return;
		(*p) = new nodo(v);
		balanceo(stk);
	}
	void inorder(nodo* root) {
		if (!root) {
			return;
		}
		inorder(root->nodos[0]);
		cout << root->val << "(" << root->h << ") ";
		inorder(root->nodos[1]);
	}
	int owo(nodo* r, int dib) {
		if (!r) return 0;

		r->espacio = dib + 1 + owo(r->nodos[0], dib);
		if (dib < r->espacio) {
			dib = r->espacio;
		}
		return dib + owo(r->nodos[1], dib/2);

	}
	//int ewe(nodo* r) {
	//	if (!r) return 0;
	//	r->espacio = 2 + max(ewe(r->nodos[0]), ewe(r->nodos[1]));
	//}
	void por_nivel() {
		queue <nodo*> ewe;
		int nivel = 1;
		root->nivel = nivel;
		ewe.push(root);
		while (!ewe.empty()) {
			if (ewe.front()->nodos[0]) {
				ewe.front()->nodos[0]->nivel = ewe.front()->nivel+1;
				ewe.push(ewe.front()->nodos[0]);
			}
			if (ewe.front()->nodos[1]) {
				ewe.front()->nodos[1]->nivel = ewe.front()->nivel + 1;
				ewe.push(ewe.front()->nodos[1]);
			}
			ewe.pop();
		}
	}

	void print_wonito() {
		owo(root,0);
		queue <nodo*> ewe;
		por_nivel();
		ewe.push(root);
		//root->espacio = (root->espacio * 2);
		while (!ewe.empty())
		{
			
			int nivel = ewe.front()->nivel;
			while (!ewe.empty() and nivel == ewe.front()->nivel) {
				/*if (ewe.front()->val > root->val) {
					ewe.front()->espacio = ewe.front()->espacio + root->espacio/2;
				}*/
				for (int i = 0; i < ewe.front()->espacio; i++)
				{
					cout << " ";
				}
				cout << ewe.front()->val<<"("<< ewe.front()->padre<<","<< ewe.front()->dir<<")";
				if (ewe.front()->nodos[0])
				{
					ewe.push(ewe.front()->nodos[0]);
					ewe.front()->nodos[0]->padre = ewe.front()->val;
					ewe.front()->nodos[0]->dir = 0;
				}
				if (ewe.front()->nodos[1])
				{
					ewe.push(ewe.front()->nodos[1]);
					ewe.front()->nodos[1]->padre = ewe.front()->val;
					ewe.front()->nodos[1]->dir = 1;
				}
				ewe.pop();
			}
			nivel++;
			cout << endl;
		}
		
	}
};
int main()
{
	avl owo;
	owo.push(1);
	owo.push(8);
	owo.push(9);
	owo.push(4);
	owo.push(7);
	owo.push(6);
	owo.push(5);
	owo.push(2);
	owo.push(3);
	owo.print_wonito();
}