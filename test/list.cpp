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

int main_51() {
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

#include <list>
#include <vector>
void PrintList(list<int>& l)
{
	for (auto& e : l)
		cout << e << " ";
	cout << endl;
}
//=========================================================================================
// push_back/pop_back/push_front/pop_front
void TestList()
{
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));

	// 在list的尾部插入4，头部插入0
	L.push_back(4); 
	L.push_front(0); 
	PrintList(L);

	// 删除list尾部节点和头部节点 
	L.pop_back(); 
	L.pop_front(); 
	PrintList(L);
}
//=========================================================================================
// insert /erase
void TestList3()
{
	int array1[] = { 1, 2, 3 };
	list<int> L(array1, array1 + sizeof(array1) / sizeof(array1[0]));

	// 获取链表中第二个节点 
	auto pos = ++L.begin(); 
	cout << *pos << endl;

	// 在pos前插入值为4的元素 
	L.insert(pos, 4); 
	PrintList(L);

	// 在pos前插入5个值为5的元素 
	L.insert(pos, 5, 5); 
	PrintList(L);

	// 在pos前插入[v.begin(), v.end)区间中的元素 
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end()); 
	PrintList(L);

	// 删除pos位置上的元素 
	L.erase(pos);
	PrintList(L);

	// 删除list中[begin, end)区间中的元素，即删除list中的所有元素 
	L.erase(L.begin(), L.end());
	PrintList(L);
}
// resize/swap/clear
void TestList4()
{
	// 用数组来构造list
	int array1[] = { 1, 2, 3 };
	int array2[] = { 4, 5, 6 };
	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0])); 
	list<int> l2(array2, array2 + sizeof(array2) / sizeof(array2[0]));

	PrintList(l1);
	PrintList(l2);

	// 交换l1和l2中的元素 
	l1.swap(l2); 
	PrintList(l1); 
	PrintList(l2);

	// 将l2中的元素清空 
	l2.clear(); 
	
	cout<<l2.size()<<endl;
}

void TestListIterator1()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto it = l.begin();
	while (it != l.end())
	{
		// erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给其赋值
		l.erase(it);
		++it;
	}
}

// 改正
void main_58() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto it = l.begin();
	while (it != l.end())
	{
		l.erase(it++);
		// it = l.erase(it);
	}
}