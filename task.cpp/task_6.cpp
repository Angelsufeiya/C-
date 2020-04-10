#include <iostream>
using namespace std;

class test {
public:
	static int s_m_tmp;
	static int s_m_sum;

	test() {
		s_m_tmp++;
		s_m_sum += s_m_tmp;
	}
};

int test::s_m_tmp = 0;
int test::s_m_sum = 0;

int main() {
	test* t = new test[10];
	cout << test::s_m_sum;

	delete[] t;
	return 0;
}