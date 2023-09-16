#include <iostream>
using namespace std;
bool palindromo(string pal, int n) {
	for (int i = 0, a = n - 1; i < a && pal[i] != pal[a]; i++, a--) {
		return 0;
	}
	return 1;
}

int main()
{	
	const int filas = 5;
	const int colum = 6;

	char** sopa = new char* [filas];
	for (char i = 0; i < filas; i++)
	{
		sopa[i] = new char[colum];
	}
	char valores[filas][colum] = {
		  {'a','j','p','a','t','o'},
		  {'m','l','o','t','a','p'},
		  {'n','t','t','h','l','o'},
		  {'k','h','a','t','o','l'},
		  {'t','i','p','o','j','m'} };

	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < colum; ++j) {
			sopa[i][j] = valores[i][j];
		}
	}
	string pal = "p";
	int tam = pal.size();

	int cont = 1;
	int find = 0;
	char* letras = sopa[0];


	for (int i = 0; i < filas; i++){
		for (int a = 0; a < colum; a++){
			cout<<sopa[i][a]<<" ";
			if (sopa[i][a] == pal[0]) 
			{
				if((a+tam)<=colum){
					for (int o = 1; o < tam; o++)
					{
						if (sopa[i][a + o] == pal[o]) {
							cont++;
						}
					}
					if (cont == tam) {
						find++;
					}
					cont = 1;
				}

				if (a >= tam-1) {
					for (int o = 1; o < tam; o++)
					{
						if (sopa[i][a - o] == pal[o]) {
							cont++;
						}
					}
					if (cont == tam) {
						find++;
					}
					cont = 1;
				}

				if ((i + tam) <= filas){
					for (int o = 1; o < tam; o++)
					{
						if (sopa[i + o][a] == pal[o]) {
							cont++;
						}
					}
					if (cont == tam) {
						find++;
					}
					cont = 1;
				}
				if (i >= tam - 1){
					for (int o = 1; o < tam; o++)
					{
						if (sopa[i-o][a] == pal[o]) {
							cont++;
						}
					}
					if (cont == tam) {
						find++;
					}
					cont = 1;
				}
			}
		}
		cout << endl;
	}
	if (palindromo(pal, tam)) {
		if (tam == 1) {
			find = find / 4;
		}
		else {
			find = find / 2;
		}
	}

	cout << find;

	/*for (char(*a)[6] = sopa; a < sopa + 5; a++) {
		for (char * i = *a; i < *a+6; i++){
			//cout<< *i << " ";
			if (*i==pal[0]) { //borrar
				//cout << *i << endl;
				string temp1 = "";
				string temp2 = "";
				string temp3 = "";
				string temp4 = "";
				for (int o = 0; o < tam; o++)
				{
					if (*(i + o) == pal[o]) {
						temp1 += (*(i + o));
						//cout << temp1 << endl;
						if (temp1 == pal)
							cont++;
					}
					if (*(i - o) == pal[o]) {
						temp2 += (*(i - o));
						//cout << temp2 << endl;
						if (temp2 == pal)
							cont++;
					}
					if (*(i - (o *6)) == pal[o]) {
						
						temp3 += (*(i - (o * 6)));
						//cout << temp3 << endl;
						if (temp3 == pal)
							cont++;
					}
					if (*(i + (o * 6)) == pal[o]) {

						temp4 += (*(i + (o * 6)));
						//cout << temp4 << endl;
						if (temp4 == pal)
							cont++;
					}
				}
				
				//cout << *i << endl;
			}
			
		}
		//cout << endl;
	}

	cout << cont << endl;
	*/
}