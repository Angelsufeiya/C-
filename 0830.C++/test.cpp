#include <iostream>
using namespace std;

class Test{
public:
	const int i;
	int &ri;

	Test(int &a) : i(3), ri(a)	//³õÊ¼»¯
	{
	
	}
};

int main(){

	return 0;
}