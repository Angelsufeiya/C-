#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7, 4, 4 , 5, 6, 7 };
    // ע��:multiset�ڵײ�ʵ�ʴ洢����<int, int>�ļ�ֵ�� 
    multiset<int> s(array, array + sizeof(array)/sizeof(array[0])); 
    for (auto& e : s)
        cout << e << " ";
    cout << endl;
    // 0 1 2 3 4 4 4 5 5 6 6 7 7 8 9

    return 0;
}

#include <map>

void TestSet()
{
    // ������array�е�Ԫ�ع���set
    int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 }; 
    set<int> s(array, array + sizeof(array) / sizeof(array[0]));
    cout << s.size() << endl;   // 10
    // �����ӡset�е�Ԫ�أ��Ӵ�ӡ����п��Կ���:set��ȥ�� 
    for (auto& e : s)
        cout << e << " ";
    cout << endl;
    // 0 1 2 3 4 5 6 7 8 9

    // ʹ�õ����������ӡset�е�Ԫ��
    for (auto it = s.rbegin(); it != s.rend(); ++it)
        cout << *it << " ";
    cout << endl;
    // 9 8 7 6 5 4 3 2 1 0

    // set��ֵΪ3��Ԫ�س����˼���
    cout << s.count(3) << endl;
    // 1

}




int TestMap()
{
    map<string, string> m;
    // ��map�в���Ԫ�صķ�ʽ:
    // ����ֵ��<"peach","����">����map�У���pairֱ���������ֵ�� 
    m.insert(pair<string, string>("peach", "����"));

    // ����ֵ��<"banan", "�㽶">����map�У���make_pair�����������ֵ��
    m.insert(make_pair("banan", "�㽶"));

    // ����operator[]��map�в���Ԫ�� 
    /*
    operator[]��ԭ����:
        ��<key, T()>����һ����ֵ�ԣ�Ȼ�����insert()�������ü�ֵ�Բ��뵽map�� 
        ���key�Ѿ����ڣ�����ʧ�ܣ�insert�������ظ�key����λ�õĵ����� 
        ���key�����ڣ�����ɹ���insert���������²���Ԫ������λ�õĵ����� 
        operator[]�������insert����ֵ��ֵ���е�value����
    */
    // ��<"apple", "">����map�У�����ɹ�������value�����ã�����ƻ������ֵ�������ý����
    //m.insert(pair<string, string>("apple", ""));
    m["apple"] = "ƻ��";
        
    // key������ʱ���쳣 
    //m.at("waterme") = "ˮ����"; 
    cout << m.size() << endl;   // 3

    // �õ�����ȥ����map�е�Ԫ�أ����Եõ�һ������key��������� 
    for (auto& e : m)
        cout << e.first << "--->" << e.second << endl;
    cout << endl;
    //apple--->ƻ��
    //banan--->�㽶
    //peach--->����

    
    // map�еļ�ֵ��keyһ����Ψһ�ģ����key���ڽ�����ʧ�� 
    auto ret = m.insert(make_pair("peach", "��ɫ")); 
    if (ret.second)
        cout << "<peach, ��ɫ>����map��, �Ѿ�����" << endl; 
    else
        cout << "��ֵΪpeach��Ԫ���Ѿ�����:" << ret.first->first << "--->" 
        << ret.first->second << " ����ʧ��" << endl;
    //��ֵΪpeach��Ԫ���Ѿ����� : peach--->���� ����ʧ��
    
    // ɾ��keyΪ"apple"��Ԫ�� 
    m.erase("apple");
    if (m.count("apple"))
        cout << "apple����" << endl;
    else
        cout << "apple������" << endl;
    // apple������

    return 0;
}