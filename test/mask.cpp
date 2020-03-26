// 计算字符串最后一个单词的长度，单词以空格隔开。

#include <iostream>
#include <string>
using namespace std;

int main_30() {
    string str;
    getline(cin, str);
    int len = str.rfind(' ');
    if (len == 0) {
        cout << str.size() - 1 << endl;
    }
    else
        cout << str.size() - len - 1 << endl;

    return 0;
}

//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。

bool IsNumber(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

class Solution1 {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;

        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            while (start != end) {
                if (IsNumber(s[start])) {
                    if ((s[start] >= 'A' && s[start] <= 'Z')) {
                        s[start] += 32;
                    }
                    break;
                }

                ++start;
            }

            while (start != end) {
                if (IsNumber(s[end])) {
                    if ((s[end] >= 'A' && s[end] <= 'Z')) {
                        s[end] += 32;
                    }
                    break;
                }

                --end;
            }

            if (s[start] == s[end]) {
                ++start;
                --end;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

//验证代码
int main_31() {
    Solution1 S;
    string str;
    getline(cin, str);
    if (S.isPalindrome(str))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}



//编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

class Solution2 {
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        }
        return false;
        //return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
        //    || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
public:
    string reverseVowels(string s) {
        int begin = 0;
        int end = s.size() - 1;

        while (begin < end) {
            while (begin != end) {
                if (isVowel(s[begin]))
                    break;

                ++begin;
            }
            while (begin != end) {
                if (isVowel(s[end]))
                    break;

                --end;
            }
            if (begin < end) {
                swap(s[begin], s[end]);

                ++begin;
                --end;
            }
        }

        return s;
    }
};

int main_32() {
    Solution2 S;
    string str;
    getline(cin, str);
    cout << S.reverseVowels(str) <<endl;
    return 0;
}

//给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。
//如果剩余少于 k 个字符，则将剩余的所有全部反转。
//如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。

class Solution3 {
    void reverse(string& s, int begin, int end) {
        while (begin < end) {
            swap(s[begin++], s[end--]);
        }
    }
public:
    string reverseStr(string& s, int k) {
        int n = s.size();
        int start = 0;

        while (n >= 2 * k) {
            reverse(s, start, start + k - 1);
            start += 2 * k;
            n -= 2 * k;
        }

        if (n >= k&& n < 2 * k) {
            reverse(s, start, start + k - 1);
        }
        else if (n < k) {
            reverse(s, start, start + n - 1);
        }
        return s;
    }
};

int main_33() {
    Solution3 S;
    string str;
    int k;

    getline(cin, str);
    cin >> k;
    cout << S.reverseStr(str, k) << endl;
    return 0;
}


class Solution {
    void reverse(string& s, int begin, int end) {
        while (begin < end) {
            swap(s[begin++], s[end--]);
        }
    }
public:
    string reverseWords(string s) {
        int len = s.size();
        int start = 0;
        int end = 0;
        do
        {
            end = s.find(' ', end + 1);
            if (end > 0) {
                reverse(s, start, end - 1);
                start = end + 1;
            }
            else {
                reverse(s, start, len - 1);
                break;
            }
        } while (start < len);
        return s;
    }
};

int main_30() {
    Solution S;
    string str;
    getline(cin, str);
    cout << S.reverseWords(str) << endl;
    return 0;
}