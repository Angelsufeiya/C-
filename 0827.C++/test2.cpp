#include <iostream>
using namespace std;

int main_40() {
	int arr[] = { 1, 2, 3, 4, 5 };

	for (auto& i : arr) {
		i *= 2;
	}
	for (auto i : arr) {
		cout << i << endl;
	}
	return 0;
}