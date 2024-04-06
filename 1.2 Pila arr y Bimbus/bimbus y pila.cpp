#include <iostream>

struct pila {
    const int tam = 10;
    int elem[10];
    int* top = nullptr;
    bool push(int a) {
        int i = 0;
        if (!top) {
            top = elem;
            *top = a;
            i = 1;
        }
        else {
            if (top != elem + (tam-1)) {
                top++;
                *top = a;
                i = 1;
            }
            else {
                std::cout << "Pila llena"<<std::endl;
            }
        }
        return i;
    }
    bool pop(int& a) {
        int i = 0;
        if (top) {
            if (top != elem) {
                a = *top;
                *top = 0;
                top--;
            }
            else {
                a = *top;
                top = nullptr;
            }
            i = 1;
        }
        else {
            std::cout << "Pila vacia"<< std::endl;
        }
        return i;
    }
    void print() {
        if (top) {
            for (int i = 0; i < (tam); i++)
            {
                std::cout << elem[i] << " ";
            }
            std::cout << std::endl;
        }
    }
};

bool bimbus(int* ini, int* fin, int*& pos, int key) {
    pos = ini + ((fin - ini) / 2);
    while (*pos != key) {
        if (key < *pos) {
            fin = pos - 1;
            pos = ini + ((fin - ini) / 2);
        }
        else {
            ini = pos + 1;
            pos = ini + ((fin - ini) / 2);
        }
        if (pos == fin and *pos != key) {
            return 0;
        }
    }
    return(*pos = key);
}

int main()
{
    /*pila owo;
    int ewe;
    for (int i = 0; i < 12; i++)
    {
        owo.push(i);
        owo.print();
    }
    //owo.print();
    for (int i = 0; i < 12; i++)
    {
        owo.pop(ewe);
        owo.print();
    }*/

    const int a = 7;
    int* pos;
    int arr[a] = { 1,4,6,7,13,15,29 };
    bool e = bimbus(arr, arr + (a-1), pos, 1);
    std::cout << *pos << "  " << e<< std::endl;
    e = bimbus(arr, arr + (a - 1), pos, 29);
    std::cout << *pos << "  " << e << std::endl;
    e = bimbus(arr, arr + (a - 1), pos, 7);
    std::cout << *pos << "  " << e << std::endl;
    e = bimbus(arr, arr + (a - 1), pos, 79);
    std::cout << *pos << "  " << e << std::endl;
}