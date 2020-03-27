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
	// 使用const迭代器进行遍历打印 
	vector<int>::const_iterator it = v.cbegin();
	while (it != v.cend())

	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main_41() {
	// 使用push_back插入4个数据 
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	// 使用迭代器进行遍历打印 	、
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// 使用迭代器进行修改 
	for (it = v.begin(); it != v.end(); ++it) {
		*it *= 2;
	}
	// 使用反向迭代器进行遍历再打印 
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

	// 使用find查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	// 在pos位置之前插入30 
	v.insert(pos, 30);

	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 3); // 删除pos位置的数据
	v.erase(pos);
	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}

// operator[]+index 和 C++11中vector的新式for+auto的遍历 
// vector使用这两种遍历方式是比较便捷的。
#include <iostream>
#include <vector>
using namespace std;

int main_47() {
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// 通过[]读写第0个位置。 
	v[0] = 10;
	cout << v[0] << endl;

	// 通过[i]的方式遍历vector
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

	// C++11支持的新式范围for遍历 
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}

// insert/erase导致的迭代器失效 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main_48() {
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// 使用find查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	// 删除pos位置的数据，导致pos迭代器失效。 
	v.erase(pos);
	cout << *pos << endl; // 此处会导致非法访问

	// 在pos位置插入数据，导致pos迭代器失效。
	// insert会导致迭代器失效，是因为insert可能会导致增容，
	// 增容后pos还指向原来的空间，而原来的空间已经释放了。 
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl; // 此处会导致非法访问
	return 0;
}


// 常见的迭代器失效的场景 
#include <iostream> 
#include <algorithm> 
#include <vector>
using namespace std;

int main_49() {
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// 实现删除v中的所有偶数
	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效 
	// 对失效的迭代器进行++it，会导致程序崩溃 
	//vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//		v.erase(it);
	//	++it;
	//}

	// 以上程序要改成下面这样，erase会返回删除位置的下一个位置 
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