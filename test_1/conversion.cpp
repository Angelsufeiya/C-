#include <iostream>
using namespace std;

int main_00() {
	int a = 10;
	int b = 3;
	double result = static_cast<double> (a) / static_cast<double> (b);	
	//其实写一个 static_cast<double> 就行

	cout << result << endl;	// 3.33333

	return 0;
}

int main_01()
{
    const int a = 10;
    const int* p = &a;
    int* q = const_cast<int*>(p);
    *q = 20;    //fine

    cout << "a=" << a << " " << "&a = " << &a << endl;
    cout << "*p=" << *p << " " << "p = " << p << endl;
    cout << "*q=" << *q << " " << "q = " << q << endl;

    return 0;
}

//a = 10 & a = 012FFC10
//* p = 20 p = 012FFC10
//* q = 20 q = 012FFC10

int main_02() {
    int c = 11;
    const int a = c;
    const int* p = &a;
    int* q = const_cast<int*>(p);
    *q = 20;    //fine

    cout << "a=" << a << " " << "&a = " << &a << endl;
    cout << "*p=" << *p << " " << "p = " << p << endl;
    cout << "*q=" << *q << " " << "q = " << q << endl;

    return 0;
}

//a = 20 & a = 007BFD64
//* p = 20 p = 007BFD64
//* q = 20 q = 007BFD64

int main_03() {
    const int c = 11;
    const int a = c;
    const int* p = &a;
    int* q = const_cast<int*>(p);
    *q = 20;    //fine

    cout << "a=" << a << " " << "&a = " << &a << endl;
    cout << "*p=" << *p << " " << "p = " << p << endl;
    cout << "*q=" << *q << " " << "q = " << q << endl;

    return 0;
}

//a = 11 & a = 00EFFB44
//* p = 20 p = 00EFFB44
//* q = 20 q = 00EFFB44

int main_04() {
    int* a = new int;
    double* d = reinterpret_cast<double*>(a);

    return 0;
}

class base {
public:
    void print1() { cout << "in class base" << endl; }
};

class derived : public base {
public:
    void print2() { cout << "in class derived" << endl; }
};

int main_05() {
    derived* p, * q;
    // p = new base;	//  Compilr Error: 无法从 "base * " 转换为 "derived * "

    // Compile Error: Cannot cast from 'base*' to 'derived*' via dynamic_cast: expression type is not polymorphic(多态的)
    // p = dynamic_cast<derived *>(new base);

    q = static_cast<derived*>(new base);	// ok, but not recommended

    q->print1();	// in class base
    q->print2();	// in class derived
    
    return 0;
}

