#include <iostream>
using namespace std;

class Person
{
public:
    void Print()
    {
        cout << "name:" << _name << endl;
        cout << "age:" << _age << endl;
    }
protected:
    string _name = "peter"; // ���� 
    int _age = 18; // ����
};

// �̳к����Person�ĳ�Ա(��Ա����+��Ա����)�����������һ���֡�
// �������ֳ���Student�� Teacher������Person�ĳ�Ա��
// ��������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�
// ���� Print���Կ�����Ա�����ĸ��á�
class Student : public Person
{
protected:
    int _stuid; // ѧ�� 
};

class Teacher : public Person
{
protected:
    int _jobid; // ���� 
};

int main() {
    Student s;
    Teacher t;
    s.Print();
    t.Print();

    return 0;
}

// ʵ����ʾ���ּ̳й�ϵ�»����Ա�ĸ����ͳ�Ա���ʹ�ϵ�ı仯 
class Person
{
public:
    void Print()
    {
        cout << _name << endl;
    }
protected:
    string _name; // ����
private:
    int _age; // ����
};

//class Student : protected Person
//class Student : private Person
class Student : public Person
{
protected:
    int _stunum; // ѧ��
};

class Person
{
protected:
    string _name; // ���� 
    string _sex; // �Ա� 
    int _age; // ����
};
class Student : public Person
{
public:
    int _No; // ѧ�� 
};
void Test() {
    Student sobj;
    // 1.���������Ը�ֵ���������/ָ��/���� 
    Person pobj = sobj ;
    Person* pp = &sobj;
    Person& rp = sobj;
    //2.��������ܸ�ֵ����������� 
    //sobj = pobj;
    // 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
    pp = &sobj;
    Student * ps1 = (Student*)pp; // �������ת��ʱ���Եġ� 
    ps1->_No = 10;
    pp = &pobj;
    Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
    ps2->_No = 10;
}