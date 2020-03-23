#include <iostream>
using namespace std;

//int main() {
//    // string类对象支持直接用cin和cout进行输入和输出 
//    string s("hello, bit!!!");
//    cout << s.length() << endl;     // 13
//    cout << s.size() << endl;       // 13
//    cout << s.capacity() << endl;   // 15
//    cout << s << endl;              // hello, bit!!!
//
//    // 将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小 
//    s.clear();
//    cout << s.size() << endl;       // 0
//    cout << s.capacity() << endl;   // 15
//
//    // 将s中有效字符个数增加到10个，多出位置用'a'进行填充 // “aaaaaaaaaa”
//    s.resize(10, 'a');
//    cout << s.size() << endl;       // 10
//    cout << s.capacity() << endl;   // 15
//
//    // 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充 
//    // "aaaaaaaaaa\0\0\0\0\0"
//    // 注意此时s中有效字符个数已经增加到15个
//    s.resize(15);
//    cout << s.size() << endl;       // 15
//    cout << s.capacity() << endl;   // 15
//    cout << s << endl;              // aaaaaaaaaa
//
//    // 将s中有效字符个数缩小到5个 
//    s.resize(5);
//    cout << s.size() << endl;       // 5
//    cout << s.capacity() << endl;   // 15
//    cout << s << endl;              // aaaaa
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main() {
//	string str;
//	str.push_back(' '); // 在str后插入空格 
//	str.append("hello"); // 在str后追加一个字符"hello" 
//	str += 'b'; // 在str后追加一个字符'b'
//	str += "it"; // 在str后追加一个字符串"it" 
//	cout<<str<<endl;
//	cout << str.c_str() << endl; // 以C语言的方式打印字符串
//
//	cout << str.find('l') << endl;
//	int pos = str.find('l');
//	cout << str.find('l', pos + 1) << endl;	//	缺省参数在这的作用是，从pos+1位置开始找的第一个
//	cout << str.find("llgg", 0, 3) << endl;	//	第二个缺省参数限制的是前面字符串的长度
//
//	cout << str.rfind('b') << endl;
//	cout << str.rfind('b', 5) << endl;	//返回4294967295
//	cout << str.substr(1, 5) << endl;
//
//	return 0;
//}

//int main()
//{
//    string s1("hello Bit");
//    const string s2("Hello Bit");
//    cout << s1 << " " << s2 << endl;    //hello Bit Hello Bit
//    cout << s1[0] << " " << s2[0] << endl;//h H
//    s1[0] = 'H';
//    cout << s1 << endl;     //Hello Bit
//    for (size_t i = 0; i < s1.size(); ++i)
//    {
//          cout << s1[i];    //Hello Bit
//    }
//    //s2[0] = 'h'; //代码编译失败，因为const类型对象不能修改 
//
//    return 0;
//}

int main_1() {
	string s;
	// 测试reserve是否会改变string中有效元素个数 
	s.reserve(100);
	cout << s.size() << endl;		// 0
	cout << s.capacity() << endl;	// 111(16n - 1)
	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小 
	s.reserve(50);
	cout << s.size() << endl;		// 0
	cout << s.capacity() << endl;	// 111

	return 0;
}
