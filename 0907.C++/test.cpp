#include <iostream>
using namespace std;

template <class T>
void swapArgs(T &a, T &b){
	T tmp;

	cout << typeid(tmp).name() << endl;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
int findArgs(T * src, size_t n, T f){
	int i;
	for (i = 0; i < n; i++){
		if£¨src[i] == f){
			return i;
		}
	}
	return -1;
}

int main(){
	//int ia = 5, ib = 7;
	//double da = 3.14, db = 1.618;

	//swapArgs(ia, ib);
	//cout << ia << ' ' << ib << endl;
	//swapArgs(da, db);
	//cout << da << ' ' << db << endl;

	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	cout << findArgs(arr, 7, 5);

	return 0;
}