#include <iostream>
#include <list>

int main_50() {
	std::list<int> l1;			// ����յ�l1
	std::list<int> l2(4, 100);	// l2�з�4��ֵΪ100��Ԫ��
	std::list<int> l3(l2.begin(), l2.end()); // ��l2��[begin(), end())����ҿ������乹��l3
	std::list<int> l4(l3);		// ��l3��������l4

	// ������Ϊ���������乹��l5
	int array[] = { 16, 2, 77, 29 };
	std::list<int> l5(array, array + sizeof(array) / sizeof(int));
	// �õ�������ʽ��ӡl5�е�Ԫ��
	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	// C++11��Χfor�ķ�ʽ���� 
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
	// ע��������õ���list�� begin() const������list��const_iterator���� 
	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
	cout << *it << " ";
	// *it = 10; ���벻ͨ�� 
	}
	cout << endl;
}

int main_51() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0])); 
	
	// ʹ���������������list�е�Ԫ��
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;
	
	// ʹ�÷�������������ӡlist�е�Ԫ��
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

	// ��list��β������4��ͷ������0
	L.push_back(4); 
	L.push_front(0); 
	PrintList(L);

	// ɾ��listβ���ڵ��ͷ���ڵ� 
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

	// ��ȡ�����еڶ����ڵ� 
	auto pos = ++L.begin(); 
	cout << *pos << endl;

	// ��posǰ����ֵΪ4��Ԫ�� 
	L.insert(pos, 4); 
	PrintList(L);

	// ��posǰ����5��ֵΪ5��Ԫ�� 
	L.insert(pos, 5, 5); 
	PrintList(L);

	// ��posǰ����[v.begin(), v.end)�����е�Ԫ�� 
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end()); 
	PrintList(L);

	// ɾ��posλ���ϵ�Ԫ�� 
	L.erase(pos);
	PrintList(L);

	// ɾ��list��[begin, end)�����е�Ԫ�أ���ɾ��list�е�����Ԫ�� 
	L.erase(L.begin(), L.end());
	PrintList(L);
}
// resize/swap/clear
void TestList4()
{
	// ������������list
	int array1[] = { 1, 2, 3 };
	int array2[] = { 4, 5, 6 };
	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0])); 
	list<int> l2(array2, array2 + sizeof(array2) / sizeof(array2[0]));

	PrintList(l1);
	PrintList(l2);

	// ����l1��l2�е�Ԫ�� 
	l1.swap(l2); 
	PrintList(l1); 
	PrintList(l2);

	// ��l2�е�Ԫ����� 
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
		// erase()����ִ�к�it��ָ��Ľڵ��ѱ�ɾ�������it��Ч������һ��ʹ��itʱ�������ȸ��丳ֵ
		l.erase(it);
		++it;
	}
}

// ����
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