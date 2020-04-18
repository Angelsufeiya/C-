//#include <iostream>
//#include <vector>
//using namespace std;
//
//// 使用RAII思想设计的SmartPtr类 
//template<class T>
//class SmartPtr {
//public:
//    SmartPtr(T* ptr = nullptr)
//        : _ptr(ptr)
//    {}
//    ~SmartPtr()
//    {
//        if (_ptr)
//            delete _ptr;
//    }
//private:
//    T* _ptr;
//};
//
//void MergeSort(int* a, int n)
//{
//    int* tmp = (int*)malloc(sizeof(int) * n);
//
//    // 将tmp指针委托给了sp对象，相当给tmp指针找了一个可怕的女朋友!天天管着你，直到你go die^^
//    SmartPtr<int> sp(tmp);
//    // _MergeSort(a, 0, n - 1, tmp);
//    
//    // 这里假设处理了一些其他逻辑 
//    vector<int> v(1000000000, 10); 
//    // ...
//}
//
//int main_1() {
//    try {
//        int a[5] = { 4, 5, 2, 3, 1 };
//        MergeSort(a, 5);
//    }
//    catch (const exception& e)
//    {
//        cout << e.what() << endl;
//    }
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//template <class T>
//class smart_ptr
//{
//	T* m_ptr;
//public:
//	smart_ptr(const smart_ptr& o) = delete;
//	smart_ptr& operator = (const smart_ptr& o) = delete;
//
//	smart_ptr(T* ptr = nullptr) :
//		m_ptr(ptr)
//	{
//	}
//
//	~smart_ptr()
//	{
//		if (m_ptr)
//		{
//			delete[] m_ptr;
//			m_ptr = nullptr;
//		}
//	}
//
//	T& operator *()
//	{
//		return *m_ptr;
//	}
//	T* operator ->()
//	{
//		return m_ptr;
//	}
//	T& operator [](int i)
//	{
//		return m_ptr[i];
//	}
//};
//
//class Test
//{
//public:
//	int m_a;
//};
//
//int main_21()
//{
//	smart_ptr<Test> sp(new Test);
//	sp->m_a = 5;
//	cout << sp->m_a;
//	smart_ptr<Test> sp2;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//// C++库中的智能指针都定义在memory这个头文件中 
//#include <memory>
//
//class Test
//{
//public:
//	int m_a;
//};
//
//int main()
//{
//	auto_ptr<int> ap(new int);
//	auto_ptr<Test> apt(new Test);
//
//	*ap = 5;
//	apt->m_a = 6;
//
//	cout << *ap << ' ' << apt->m_a << endl;
//
//	auto_ptr<int> ap2 = ap;
//
//	cout << *ap2 << ' ' << apt->m_a << endl;
//	return 0;
//}
//
//template<class T>
//class AutoPtr
//{
//public:
//    AutoPtr(T* ptr = NULL)
//        : _ptr(ptr)
//    {}
//    ~AutoPtr() {
//        if (_ptr)
//            delete _ptr;
//    }
//
//    // 一旦发生拷贝，就将ap中资源转移到当前对象中，然后另ap与其所管理资源断开联系， 
//    // 这样就解决了一块空间被多个对象使用而造成程序奔溃问题
//    AutoPtr(AutoPtr<T>& ap)
//        : _ptr(ap._ptr)
//    {
//        ap._ptr = NULL;
//    }
//
//    AutoPtr<T>& operator=(AutoPtr<T>& ap)
//    {
//        // 检测是否为自己给自己赋值 
//        if(this != &ap)
//        {
//            // 释放当前对象中资源            
//            if(_ptr)
//                delete _ptr;
//            // 转移ap中资源到当前对象中 
//            _ptr = ap._ptr;
//            ap._ptr = NULL;
//        }
//        return *this;
//    }
//
//    T& operator*() { return *_ptr; }
//    T* operator->() { return _ptr; }
//private:
//    T* _ptr;
//};

//#include <iostream>
//#include <memory>
//using namespace std;
//
//class Test
//{
//public:
//	int m_a;
//};
//
//int main()
//{
//	unique_ptr<int> ap(new int);
//	unique_ptr<Test> apt(new Test);
//
//	*ap = 5;
//	apt->m_a = 6;
//
//	cout << *ap << ' ' << apt->m_a << endl;
//
//	//unique_ptr<int> ap2 = ap;
//
//	//cout << *ap2 << ' ' << apt->m_a << endl;
//	return 0;
//}
//
//template<class T>
//class UniquePtr
//{
//public:
//	UniquePtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//	~UniquePtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//private:
//	// C++98防拷贝的方式:只声明不实现+声明成私有 
//	//UniquePtr(UniquePtr<T> const &);
//	//UniquePtr & operator=(UniquePtr<T> const&);
//
//	// C++11防拷贝的方式:delete
//	UniquePtr(UniquePtr<T> const&) = delete;
//	UniquePtr& operator=(UniquePtr<T> const&) = delete;
//
//	T* _ptr;
//};

//#include <iostream>
//#include <memory>
//using namespace std;
//
//class Date
//{
//public:
//	Date() { cout << "Date()" << endl; }
//	~Date() { cout << "~Date()" << endl; }
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main() {
//	// shared_ptr通过引用计数支持智能指针对象的拷贝 
//	shared_ptr<Date> sp(new Date); 
//	shared_ptr<Date> copy(sp);
//
//	cout << "ref count:" << sp.use_count() << endl;
//	cout << "ref count:" << copy.use_count() << endl;
//	return 0;
//}

//Date()
//ref count : 2
//ref count : 2
//~Date()

//#include <iostream>
//#include <memory>
//using namespace std;
//
//struct ListNode
//{
//	int _data;
//	shared_ptr<ListNode> _prev;
//	shared_ptr<ListNode> _next;
//
//	~ListNode() { cout << "~ListNode()" << endl; }
//};
//
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;	// 1
//	cout << node2.use_count() << endl;	// 1
//
//	node1->_next = node2;
//	node2->_prev = node1;
//
//	cout << node1.use_count() << endl;	// 2
//	cout << node2.use_count() << endl;	// 2
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//// 解决方案:在引用计数的场景下，把节点中的_prev和_next改成weak_ptr就可以了
//// 原理就是，node1->_next = node2;和node2->_prev = node1;时
//// weak_ptr的_next和_prev不会增加 node1和node2的引用计数。
//struct ListNode
//{
//    int _data;
//    weak_ptr<ListNode> _prev;
//    weak_ptr<ListNode> _next;
//    ~ListNode() { cout << "~ListNode()" << endl; }
//};
//int main() {
//    shared_ptr<ListNode> node1(new ListNode);
//    shared_ptr<ListNode> node2(new ListNode);
//    cout << node1.use_count() << endl;
//    cout << node2.use_count() << endl;
//
//    node1->_next = node2;
//    node2->_prev = node1;
//    cout << node1.use_count() << endl;
//    cout << node2.use_count() << endl;
//    return 0;
//}

//1
//1
//1
//1
//~ListNode()
//~ListNode()

#include <iostream>
using namespace std;

// 仿函数的删除器 
template<class T> 
struct FreeFunc {
    void operator()(T* ptr)
    {
        cout << "free:" << ptr << endl;
        free(ptr);
    }
};
template<class T>
struct DeleteArrayFunc {
    void operator()(T* ptr)
    {
        cout << "delete[]" << ptr << endl;
        delete[] ptr;
    }
};

int main() {
    FreeFunc<int> freeFunc;
    shared_ptr<int> sp1((int*)malloc(4), freeFunc);
    DeleteArrayFunc<int> deleteArrayFunc;
    shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);

    return 0;
}

//delete[]007904D0
//free : 00795108
