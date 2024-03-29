#include <iostream>
using namespace std;

struct deque {
	int tam_map = 5;
	int tam_arr = 5;
	int** mapa;
	int** map_ini;
	int** map_end;
	int* ini;
	int* fin;
	deque() {
		mapa = new int* [tam_map];
		ini = 0;
		fin = 0;
	}
	void push_front(int val) {
		if (fin) {
			if (ini != *map_ini) {
				ini--;
				*ini = val;
			}
			else {
				if (map_ini != mapa) {
					map_ini--;
					*map_ini = new int [tam_arr];
					ini = *map_ini + (tam_arr - 1);
					*ini = val;
				}
				else {
					//agrandamiento de mapa
				}
			}
		}
		else {
			map_ini = (mapa + (tam_map / 2));
			map_end = map_ini;
			*map_ini = new int[tam_arr];
			ini = *map_ini + (tam_arr / 2);
			*ini = val;
			fin = ini;
		}
	}
	void push_back(int val) {
		if (fin) {
			if (fin != *map_end + (tam_map -1)) {
				fin++;
				*fin = val;
			}
			else {
				if (map_end != mapa+(tam_map -1)) {
					map_end++;
					*map_end = new int[tam_arr];
					fin = *map_end;
					*fin = val;
				}
				else {
					//agrandamiento de mapa
				}
			}
		}
		else {
			map_ini = (mapa + (tam_map / 2));
			map_end = map_ini;
			*map_ini = new int[tam_arr];
			ini = *map_ini + (tam_arr / 2);
			*ini = val;
			fin = ini;
		}
	}
	void pop_front() {
		if (fin) {
			if (ini == fin) {
				*ini = 0;
				fin = 0;
				delete map_ini;
			}
			else if (ini != *map_ini + (tam_arr - 1)) {
				*ini = 0;
				ini++;
			}
			else {
				int* temp = *map_ini;
				map_ini++;
				delete temp;
				ini = *map_ini;
			}
		}
	}
	void pop_back() {
		if (fin) {
			if (fin == ini) {
				*fin = 0;
				fin = 0;
				delete map_ini;
			}
			else if (fin != *map_end) {
				*fin = 0;
				fin--;
			}
			else {
				int* temp = *map_end;
				map_end--;
				delete temp;
				fin = *map_end+(tam_arr-1);
			}
		}
	}
	int& operator[](int key) {
		int vacios = ini - (*map_ini);
		int index_map = (key+vacios)/ tam_arr;
		int** tmp = map_ini; 
		tmp = tmp + index_map;
		if (index_map == 0) {
			return *(ini + key);
		}
		return *((*tmp) + ((vacios + key)-(tam_arr * index_map)));
	}
};

int main()
{
	deque owo;
	owo.push_front(1);
	owo.push_back(8);
	owo.push_front(-1);
	owo.push_front(-4);
	owo.push_front(-7);
	owo.push_back(10);
	owo.push_back(29);
	owo.push_front(-4);
	owo.push_front(-5);
	owo.push_front(-15);
	owo.push_front(-8);
	owo.push_front(-79);
	owo.push_back(78);
	owo.push_back(98);
	owo.push_back(108);
	owo.push_back(118);
	owo.push_back(128);
	owo.pop_front();
	owo.pop_front();
	owo.pop_front();
	owo.pop_front();
	owo.pop_back();
	owo.pop_back();
	
	owo[0] = 5;
	cout << owo[0] << endl;

	for (int **i=owo.map_ini;i<=owo.map_end;i++)
	{
		for (int o=0; o<owo.tam_arr;o++)
		{
			cout<<(*i)[o]<< " ";
		}
		cout << "    ";
	}
	
}