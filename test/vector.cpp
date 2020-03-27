// constructing vectors
#include <iostream>
#include <vector>

int main_40() {
	// constructors used in the same order as described above:
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second(4, 100);                       // four ints with value 100
	std::vector<int> third(second.begin(), second.end());  // iterating through second
	std::vector<int> fourth(third);                        // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = { 16,2,77,29 };
	std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	std::cout << "The contents of fifth are:";

	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << '\n';

	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v)
{
	// ʹ��const���������б�����ӡ 
	vector<int>::const_iterator it = v.cbegin();
	while (it != v.cend())

	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main_41() {
	// ʹ��push_back����4������ 
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	// ʹ�õ��������б�����ӡ 	��
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// ʹ�õ����������޸� 
	for (it = v.begin(); it != v.end(); ++it) {
		*it *= 2;
	}
	// ʹ�÷�����������б����ٴ�ӡ 
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	PrintVector(v);
	return 0;
}

// vector::capacity
#include <iostream>
#include <vector>

int main_42() {
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();	// capacity = size = 0

	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	return 0;
}

// vector::reserve
#include <iostream>
#include <vector>

int main_43() {
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();

	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i) {
		bar.push_back(i);
		if (sz != bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	return 0;
}


// vector::resize
#include <iostream>
#include <vector>

int main_44() {
	std::vector<int> myvector;
	// set some initial content:
	for (int i = 1; i < 10; i++) {
		myvector.push_back(i);
	}

	myvector.resize(5);
	myvector.resize(8, 100);
	myvector.resize(12);
	std::cout << "myvector contains:";
	for (int i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	return 0;
}

// push_back/pop_back
#include <iostream>
#include <vector>
using namespace std;

int main_45() {
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	v.pop_back();
	v.pop_back();
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}

// find / insert / erase
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main_46() {
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// ʹ��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	// ��posλ��֮ǰ����30 
	v.insert(pos, 30);

	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 3); // ɾ��posλ�õ�����
	v.erase(pos);
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}

// operator[]+index �� C++11��vector����ʽfor+auto�ı��� 
// vectorʹ�������ֱ�����ʽ�ǱȽϱ�ݵġ�
#include <iostream>
#include <vector>
using namespace std;

int main_47() {
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// ͨ��[]��д��0��λ�á� 
	v[0] = 10;
	cout << v[0] << endl;

	// ͨ��[i]�ķ�ʽ����vector
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int> swapv;
	swapv.swap(v);
	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "swapv data:";
	for (size_t i = 0; i < swapv.size(); ++i) {
		cout << swapv[i] << " ";
	}
	cout << endl;

	// C++11֧�ֵ���ʽ��Χfor���� 
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}

// insert/erase���µĵ�����ʧЧ 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main_48() {
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// ʹ��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	// ɾ��posλ�õ����ݣ�����pos������ʧЧ�� 
	v.erase(pos);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����

	// ��posλ�ò������ݣ�����pos������ʧЧ��
	// insert�ᵼ�µ�����ʧЧ������Ϊinsert���ܻᵼ�����ݣ�
	// ���ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ��ˡ� 
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
	return 0;
}


// �����ĵ�����ʧЧ�ĳ��� 
#include <iostream> 
#include <algorithm> 
#include <vector>
using namespace std;

int main_49() {
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// ʵ��ɾ��v�е�����ż��
	// ����ĳ����������������ż����erase����itʧЧ 
	// ��ʧЧ�ĵ���������++it���ᵼ�³������ 
	//vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//		v.erase(it);
	//	++it;
	//}

	// ���ϳ���Ҫ�ĳ�����������erase�᷵��ɾ��λ�õ���һ��λ�� 
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	return 0;
}