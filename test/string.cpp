#include <iostream>
using namespace std;

//int main() {
//    // string�����֧��ֱ����cin��cout������������ 
//    string s("hello, bit!!!");
//    cout << s.length() << endl;     // 13
//    cout << s.size() << endl;       // 13
//    cout << s.capacity() << endl;   // 15
//    cout << s << endl;              // hello, bit!!!
//
//    // ��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С 
//    s.clear();
//    cout << s.size() << endl;       // 0
//    cout << s.capacity() << endl;   // 15
//
//    // ��s����Ч�ַ��������ӵ�10�������λ����'a'������� // ��aaaaaaaaaa��
//    s.resize(10, 'a');
//    cout << s.size() << endl;       // 10
//    cout << s.capacity() << endl;   // 15
//
//    // ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'������� 
//    // "aaaaaaaaaa\0\0\0\0\0"
//    // ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
//    s.resize(15);
//    cout << s.size() << endl;       // 15
//    cout << s.capacity() << endl;   // 15
//    cout << s << endl;              // aaaaaaaaaa
//
//    // ��s����Ч�ַ�������С��5�� 
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
//	str.push_back(' '); // ��str�����ո� 
//	str.append("hello"); // ��str��׷��һ���ַ�"hello" 
//	str += 'b'; // ��str��׷��һ���ַ�'b'
//	str += "it"; // ��str��׷��һ���ַ���"it" 
//	cout<<str<<endl;
//	cout << str.c_str() << endl; // ��C���Եķ�ʽ��ӡ�ַ���
//
//	cout << str.find('l') << endl;
//	int pos = str.find('l');
//	cout << str.find('l', pos + 1) << endl;	//	ȱʡ��������������ǣ���pos+1λ�ÿ�ʼ�ҵĵ�һ��
//	cout << str.find("llgg", 0, 3) << endl;	//	�ڶ���ȱʡ�������Ƶ���ǰ���ַ����ĳ���
//
//	cout << str.rfind('b') << endl;
//	cout << str.rfind('b', 5) << endl;	//����4294967295
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
//    //s2[0] = 'h'; //�������ʧ�ܣ���Ϊconst���Ͷ������޸� 
//
//    return 0;
//}

int main_1() {
	string s;
	// ����reserve�Ƿ��ı�string����ЧԪ�ظ��� 
	s.reserve(100);
	cout << s.size() << endl;		// 0
	cout << s.capacity() << endl;	// 111(16n - 1)
	// ����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С 
	s.reserve(50);
	cout << s.size() << endl;		// 0
	cout << s.capacity() << endl;	// 111

	return 0;
}
