//#include <iostream>
//#include <vector>
//using namespace std;
//
//// ʹ��RAII˼����Ƶ�SmartPtr�� 
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
//    // ��tmpָ��ί�и���sp�����൱��tmpָ������һ�����µ�Ů����!��������㣬ֱ����go die^^
//    SmartPtr<int> sp(tmp);
//    // _MergeSort(a, 0, n - 1, tmp);
//    
//    // ������账����һЩ�����߼� 
//    vector<int> v(1000000000, 10); 
//    // ...
//}
//
//int main() {
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
//// C++���е�����ָ�붼������memory���ͷ�ļ��� 
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
//    // һ�������������ͽ�ap����Դת�Ƶ���ǰ�����У�Ȼ����ap������������Դ�Ͽ���ϵ�� 
//    // �����ͽ����һ��ռ䱻�������ʹ�ö���ɳ���������
//    AutoPtr(AutoPtr<T>& ap)
//        : _ptr(ap._ptr)
//    {
//        ap._ptr = NULL;
//    }
//
//    AutoPtr<T>& operator=(AutoPtr<T>& ap)
//    {
//        // ����Ƿ�Ϊ�Լ����Լ���ֵ 
//        if(this != &ap)
//        {
//            // �ͷŵ�ǰ��������Դ            
//            if(_ptr)
//                delete _ptr;
//            // ת��ap����Դ����ǰ������ 
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
//	// C++98�������ķ�ʽ:ֻ������ʵ��+������˽�� 
//	//UniquePtr(UniquePtr<T> const &);
//	//UniquePtr & operator=(UniquePtr<T> const&);
//
//	// C++11�������ķ�ʽ:delete
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
//	// shared_ptrͨ�����ü���֧������ָ�����Ŀ��� 
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
//// �������:�����ü����ĳ����£��ѽڵ��е�_prev��_next�ĳ�weak_ptr�Ϳ�����
//// ԭ����ǣ�node1->_next = node2;��node2->_prev = node1;ʱ
//// weak_ptr��_next��_prev�������� node1��node2�����ü�����
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

//#include <iostream>
//using namespace std;
//
//// �º�����ɾ���� 
//template<class T> 
//struct FreeFunc {
//    void operator()(T* ptr)
//    {
//        cout << "free:" << ptr << endl;
//        free(ptr);
//    }
//};
//template<class T>
//struct DeleteArrayFunc {
//    void operator()(T* ptr)
//    {
//        cout << "delete[]" << ptr << endl;
//        delete[] ptr;
//    }
//};
//
//int main_s3() {
//    FreeFunc<int> freeFunc;
//    shared_ptr<int> sp1((int*)malloc(4), freeFunc);
//    DeleteArrayFunc<int> deleteArrayFunc;
//    shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);
//
//    return 0;
//}

//delete[]007904D0
//free : 00795108

//#include <iostream>
//using namespace std;
//
//double Division(int a, int b)
//{
//    // ��b == 0ʱ�׳��쳣 
//    if (b == 0)
//        throw "Division by zero condition!";
//    else
//        return ((double)a / (double)b);
//}
//
//void Func() {
//    // ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš� 
//    // �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ�����������׳�ȥ��
//    int* array = new int[10];
//    try {
//        int len, time;
//        cin >> len >> time;
//        cout << Division(len, time) << endl;
//    }
//    catch (...) {
//        cout << "delete []��" << array << endl;  // ������ Ȼ������ȥ��ջ���catch
//        delete[] array;
//        //throw;
//    }
//    // ...
//    cout << "delete []" << array << endl;
//    delete[] array;
//}
//
//int main() {
//    try {
//        Func();
//    }
//    catch (const char* errmsg) {
//        cout << errmsg << endl; // Division by zero condition!
//    }
//
//    return 0;
//}

//#include <iostream>
//using namespace std;

// ������������ͨ��ʹ�õ��쳣�̳���ϵ 
//class Exception
//{
//protected:
//    string _errmsg;
//    int _id;
//    //list<StackInfo> _traceStack;
//    // ...
//};
//
//class SqlException : public Exception
//{};
//class CacheException : public Exception
//{};
//class HttpServerException : public Exception
//{};
//
//int main() {
//    try {
//        // server.Start();
//        // �׳����������������
//    }
//
//    catch (const Exception& e) // ���ﲶ�������Ϳ��� 
//    {
//    }  
//    catch (...)
//    {
//        cout << "Unkown Exception" << endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

// 1.�������α�������ǿ��Կ���ConnnectSql�г����ˣ��ȷ��ظ�ServerStart
// ServerStart�ٷ��� ��main������main������������⴦�����Ĵ���
// 2.������쳣��ϵ��������ConnnectSql����ServerStart�����ú�������
// �����ü�飬��Ϊ�׳��� �쳣�쳣��ֱ������main������catch����ĵط���main����ֱ�Ӵ������
//int ConnnectSql()
//{
//    // �û���������� 
//    if (...)
//        return 1;
//    // Ȩ�޲��� 
//    if (...)
//        return 2;
//}
//int ServerStart() {
//    if (int ret = ConnnectSql() < 0)
//        return ret; 
//    int fd = socket(); 
//    if (fd < 0)
//        return errno;
//}
//int main() {
//    if (ServerStart() < 0)
//        ...
//
//    return 0;
//}

int main_SP() {
    try {
        vector<int> v(10, 5);
        // �������ϵͳ�ڴ治��Ҳ�����쳣 
        v.reserve(1000000000);
        // ����Խ������쳣
        v.at(10) = 100;
    }
    catch (const exception& e) // ���ﲶ�������Ϳ��� 
    {
        cout << e.what() << endl;   // bad allocation
    }
    catch (...) {
        cout << "Unkown Exception" << endl;
    }

    return 0; 
}