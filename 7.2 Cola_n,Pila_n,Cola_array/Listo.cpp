#include <iostream>
using namespace std;

struct nodo {
	int val;
	nodo* next;
	nodo(int v, nodo* n = 0) {
		val = v;
		next = n;
	}
};

struct cola_n {
	nodo* head = nullptr;
	nodo* tail = nullptr;
	bool push(int val) {
		if (!tail) {
			head = new nodo(val);
			tail = head;
		}
		else {
			tail->next = new nodo(val);
			tail = tail->next;
		}
		return 1;
	}
	bool pop(int& val) {
		bool b = 0;
		if (head) {
			nodo* tmp = head;
			if (head->next) {
				head = head->next;
			}
			else {
				head = nullptr;
				tail = head;
			}
			val = tmp->val;
			delete tmp;
			b = 1;
		}
		return b;
	}
	void print() {
		for (nodo* tmp = head; tmp; tmp = tmp->next)
		{
			cout << tmp->val << " -> ";
		}
		cout << "Null" << endl;
	}
};

struct pila_n {
	nodo* top = nullptr;
	bool push(int val) {
		if (!top) {
			top = new nodo(val);
		}
		else {
			nodo* tmp = top;
			top = new nodo(val, tmp);
		}
		return 1;
	}
	bool pop(int& val) {
		bool b = 0;
		if (top) {
			val = top->val;
			nodo* tmp = top;
			top = top->next;
			delete tmp;
			b = 1;
		}
		return b;
	}
	void print() {
		for (nodo* i = top; i; i = i->next)
		{
			cout << " -> " << i->val;
		}
		cout << "-> Null" << endl;
	}
};

struct cola_arr {
	int arr[10];
	int* head = nullptr, * tail=nullptr;
	bool push(int v) {
		if (!tail) {
			head = arr;
			*head = v;
			tail = head;
		}
		else {
			if (tail != arr + 9) {
				if (tail + 1 == head) {
					cout << "Cola llena" << endl;
					return 0;
				}
				else {
					tail++;
				}
			}
			else {
				if (arr == head) {
					cout << "Cola llena" << endl;
					return 0;
				}
				else {
					tail = arr;
				}
			}
			*tail = v;
			return 1;
		}
	}
	bool pop(int& v) {
		if (head) {
			v = *head;
			if (head != arr + 9) {
				if (head != tail) {
					*head = 0;
					head++;
				}
				else {
					*head = 0;
					head = nullptr;
					tail = head;
				}
			}
			else {
				*head = 0;
				head = arr;
			}
			return 1;
		}
		return 0;
	}
	void print() {
		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	//COLA CON NODOS
	/*
	int val;
	cola_n owo;
	owo.push(4);
	owo.pop(val);
	owo.push(8);
	owo.push(65);
	owo.push(-8);
	owo.pop(val);
	owo.print();
	cout << val;
	*/
	//PILA CON NODOS
	/*
	int val;
	pila_n owo;
	owo.push(2);
	owo.pop(val);
	owo.push(6);
	owo.push(8);
	owo.push(14);
	owo.print();
	cout << val;
	*/
	//COLA ARRAY
	int uwu;
	cola_arr owo;
	for (int i = 1; i < 12; i++)
	{
		owo.push(i);
		owo.print();
	}
	owo.pop(uwu);
	owo.print();
	owo.push(-4);
	owo.print();
	owo.push(-4);
	for (int i = 0; i < 10; i++)
	{
		owo.pop(uwu);
		owo.print();
	}
	owo.push(-13);
	owo.print();
};