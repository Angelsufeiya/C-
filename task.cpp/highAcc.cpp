#include "highAcc.h"

string multiply(string num1, string num2) {
	HighAcc s1(num1);
	HighAcc s2(num2);

	return (string)(s1 * s2);
}

int main_000() {
	string s1("2020");
	string s2("202");

	HighAcc num1(s1);
	HighAcc num2(s2);

	cout << (string)(num1 + num2) << endl;
	cout << multiply(s1, s2);

	return 0;
}