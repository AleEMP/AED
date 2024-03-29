#include <iostream>
using namespace std;

template <class t>
struct vect {
	int tam = 5;
	t* punt = new t[tam];
	int count = 0;
	t* top = 0;
	void push_front(t val) {
		count++;
		if (!top) {
			top = punt;
			*top = val;
		}
		else
		{
			if (top == punt + (tam - 1))
			{
				t* tmp = new t[tam * 2];
				for (int i = 0; i < tam; i++)
				{
					tmp[i] = punt[i];
				}
				tam = tam * 2;
				delete[] punt;
				punt = tmp;
				top = punt + (count - 2);
			}

			for (int i = count - 1; i > 0; i--) {
				punt[i] = punt[i - 1];
			}
			punt[0] = val;
			top++;
		}
	}
	void push(t val)
	{
		count++;
		if (!top) top = punt;
		else
		{
			if (top == punt + (tam - 1))
			{
				t* tmp = new t[tam * 2];
				//int i = 0;
				for (int i = 0; i < tam; i++)
				{
					tmp[i] = punt[i];
				}
				tam = tam * 2;
				delete[] punt;
				punt = tmp;
				top = punt + (count - 1);
				//delete tmp;
			}
			else top++;
		}
		*top = val;
	}
	void pop() {
		if (top) {
			if (count == tam / 2) {
				tam = tam / 2;
				t* tmp = new t[tam];
				for (int i = 0; i < count; i++)
				{
					tmp[i] = punt[i];
				}
				delete punt;
				punt = tmp;
				top = punt + (count - 1);
			}
			if (top == punt) {
				*top = 0;
				top = nullptr;
			}
			else {
				*top = 0;
				top--;
			}
			count--;
		}

	}
	void pop_front() {
		if (top) {
			if (count == tam / 2) {
				tam = tam / 2;
				t* tmp = new t[tam];
				for (int i = 0; i < count; i++)
				{
					tmp[i] = punt[i];
				}
				delete punt;
				punt = tmp;
				top = punt + (count - 1);
			}
			t* temp = punt + 1;
			for (int i = 0; temp < punt + count; i++)
			{
				punt[i] = *temp;
				temp++;
			}
			top--;
		}
		count--;
	}
	t& operator [](int d) {
		if (punt + d <= top)
			return *(punt + d);
	}	
};

template <class t>
struct nodo {
	nodo<t>* punt[2];
	t val;
	nodo(t valor, nodo<t>* ptr_atras = nullptr, nodo<t>* ptr_delante = nullptr) {
		val = valor;
		punt[0] = ptr_atras;
		punt[1] = ptr_delante;
	}

};
template <class t>
struct lista {
	nodo <t>* head = nullptr;
	nodo <t>* fin = nullptr;
	void push_back(t val) {
		if (!fin) {
			head = new nodo <t>(val);
			fin = head;
		}
		else {
			fin->punt[1] = new nodo<t>(val, fin);
			fin = fin->punt[1];
		}
	}
	void push_front(t val) {
		if (!fin) {
			head = new nodo <t>(val);
			fin = head;
		}
		else {
			head->punt[0] = new nodo<t>(val, 0, head);
			head = head->punt[0];
		}
	}
	void pop_back()
	{
		if (fin)
		{
			if (fin != head)
			{
				fin = fin->punt[0];
				delete fin->punt[1];
				fin->punt[1] = nullptr;
			}
			else
			{
				delete fin;
				fin = nullptr;
				head = nullptr;
			}
		}
	}
	void pop_front() {
		if (head)
		{
			if (head != fin)
			{
				head = head->punt[1];
				delete head->punt[0];
				head->punt[0] = nullptr;
			}
			else
			{
				delete head;
				fin = nullptr;
				head = nullptr;
			}
		}
	}
	t& operator [](int id) {
		nodo <t>* i = head;
		for (int o = 0; o<id ; i=i->punt[1],o++)
		{
		}
		return (i->val);
	}
};

int main()
{
	/*vect<int> owo;
	owo.push_front(4);
	owo.push_front(9);
	owo.push(8);
	owo.push(3);
	owo.push(9);
	owo.push(17);
	owo.push(45);
	owo.pop();
	owo.pop_front();
	owo.push(31);
	owo.push(68);
	owo.pop_front();
	owo.push(35);

	cout <<"Tamano del array: " << owo.tam << endl;
	for (int i = 0; i < owo.tam; i++)
	{
		cout << owo.punt[i] << " ";
	}
	cout << endl;
	owo[3] = 8;

	cout << "Tamano del array: " << owo.tam << endl;
	for (int i = 0; i < owo.tam; i++)
	{
		cout << owo.punt[i] << " ";
	}*/
	
	lista <int> uwu;
	uwu.push_front(-8);
	uwu.push_back(9);
	uwu.push_back(17);
	uwu.push_back(5);
	uwu.push_back(1);
	uwu.push_back(7);
	uwu.push_back(12);
	for (nodo<int>* i = uwu.head; i; i = i->punt[1])
	{
		cout << i->val << " ";
	}
	cout <<endl<< uwu[3];
}