#include <iostream>

struct pila {
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
            if (top != elem + 9) {
                top++;
                *top = a;
                i = 1;
            }
        }
        return i;
    }
    bool pop(int& a) {
        int i = 0;
        if (top) {
            if (top != elem) {
                a = *top;
                top--;
            }
            else {
                a = *top;
                top = nullptr;
            }
            i = 1;
        }
        return i;
    }
};

bool bimbus(int* ini, int* fin, int*& pos, int key) {
    pos = ini+((fin-ini)/2);
    while(*pos!=key){
        if(key<*pos){
            fin = pos - 1;
            pos = ini + ((fin - ini) / 2);
        }
        else{
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
    std:: cout << owo.push(8)<<std::endl;
    int ewe;
    owo.pop(ewe);
    std::cout << ewe;*/
    const int a = 7;
    int* pos;
    int arr[a] = { 1,4,6,7,9,13,15 };
    bool e=bimbus(arr, arr + a, pos, 29);
    std::cout << e;
}