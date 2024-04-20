#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct nodo {
	int val;
	nodo* next;
	nodo(int v, nodo* n = 0) {
		val = v;
		next = n;
	}
};

struct forward_list {
	nodo* head=nullptr;
	bool find(int val, nodo**& p) {
		for (p = &head;*p and (*p)->val<val;p=&(*p)->next){}
		return(*p and (*p)->val == val);
	}
	void push(int val) {
		nodo** p;
		if (!find(val, p)) {
			*p = new nodo(val,*p);
		}
	}
	void del(int val) {
		nodo** p;
		if (find(val, p)) {
			nodo* tmp = *p;
			(*p) = (*p)->next;
			delete tmp;
		}
	}
	void print() {
		cout << "Head";
		for (nodo ** i =&head;*i;i=&(*i)->next)
		{
			cout <<" -> "<<(*i)->val ;
		}
		cout << " -> Null"<<endl;
	}
};

int main() {

	forward_list owo;
	srand(time(NULL));
	for (int i = 0; i < 9; i++)
	{
		int a = 1 + rand() % 100;
		owo.push(a);
		cout << a << endl;
		owo.print();
		
	}
	//owo.print();
};