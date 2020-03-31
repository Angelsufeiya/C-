#include <iostream>
#include <list>

int main_50() {
	std::list<int> l1;			// 构造空的l1
	std::list<int> l2(4, 100);	// l2中放4个值为100的元素
	std::list<int> l3(l2.begin(), l2.end()); // 用l2的[begin(), end())左闭右开的区间构造l3
	std::list<int> l4(l3);		// 用l3拷贝构造l4

	// 以数组为迭代器区间构造l5
	int array[] = { 16, 2, 77, 29 };
	std::list<int> l5(array, array + sizeof(array) / sizeof(int));
	// 用迭代器方式打印l5中的元素
	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	// C++11范围for的方式遍历 
	for(auto& e : l5)
	std::cout << e << " ";
	std::cout << std::endl;

	return 0;
}

#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int>& l)
{
	// 注意这里调用的是list的 begin() const，返回list的const_iterator对象 
	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
	cout << *it << " ";
	// *it = 10; 编译不通过 
	}
	cout << endl;
}

int main() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0])); 
	
	// 使用正向迭代器正向list中的元素
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;
	
	// 使用反向迭代器逆向打印list中的元素
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}

