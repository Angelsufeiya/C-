// 洗牌
#if 0
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, n, k;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        int num = 2 * n;
        vector<int> a(num);
        for (int i = 0; i < num; ++i) {
            cin >> a[i];
        }

        // 洗k次牌
        while (k--) {
            vector<int> v(a.begin(), a.end());
            for (int i = 0; i < n; ++i) {
                a[2 * i] = v[i];
                a[2 * i + 1] = v[i + n];
            }
        }
        for (int i = 0; i < num - 1; ++i) {
            cout << a[i] << ' ';
        }
        cout << a[num - 1] << endl;
    }
    return 0;
}

#endif

// MP3光标位置
#if 0
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string order;
    while (cin >> n >> order) {
        int num = 1;
        int len = order.size();

        if (n <= 4) {
            for (int i = 0; i < len; i++) {
                if (order[i] == 'U' && num == 1) {
                    num = n;
                }
                else if (order[i] == 'U') {
                    --num;
                }
                else if (order[i] == 'D' && num == n) {
                    num = 1;
                }
                else if (order[i] == 'D') {
                    ++num;
                }
            }
            for (int i = 1; i < n; ++i) {
                cout << i << ' ';
            }
            cout << n << endl;
            cout << num << endl;
        }
        else {
            int start = 1;
            for (int i = 0; i < len; i++) {
                if (start == 1 && order[i] == 'U' && num == 1) {
                    num = n;
                    start = n - 3;
                }
                else if (start != 1 && order[i] == 'U' && num == start) {
                    --num;
                    --start;
                }
                else if (order[i] == 'U') {
                    --num;
                }
                else if (start == n - 3 && order[i] == 'D' && num == n) {
                    num = 1;
                    start = 1;
                }
                else if (start != n - 3 && order[i] == 'D' && num == start + 3) {
                    ++num;
                    ++start;
                }
                else if (order[i] == 'D') {
                    ++num;
                }
            }
            for (int i = 0; i < 3; ++i) {
                cout << start + i << ' ';
            }
            cout << start + 3 << endl;
            cout << num << endl;
        }
    }
    return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        int len1 = s1.size();
        int len2 = s2.size();

        if (len1 != len2 || len1 < 2 || len2 < 2) {
            cout << "false" << endl;
        }

        char tmp;
        int flag = 0;
        for (int i = 0; i < len1; i++) {
            if (s1[i] != s2[i] && !flag) {
                ++flag;
                tmp = s1[i];
            }
            else if (s1[i] != s2[i] && flag) {
                swap(tmp, s1[i]);
            }
        }
        for (int i = 0; i < len1; i++) {
            if (s1[i] != s2[i]) {
                flag = 0;
            }
        }
        if (flag)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}

#endif

#if 0
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    while (cin >> s1) {
        int len1 = s1.size(), flag = 0, j = 0;
        s2.resize(2 * len1);
        for (int i = 0; i < len1; i++) {
            if (s1[i] >= 'A' && s1[i] <= 'Z' && !flag) {
                s2[i + j] = s1[i] - 'A' + 'a';
                ++flag;
            }
            else if (s1[i] >= 'A' && s1[i] <= 'Z' && flag) {
                s2[i + j] = '_';
                j++;
                s2[i + j] = s1[i] - 'A' + 'a';
                j++;
            }
            else {
                s2[i + j] = s1[i];
            }
        }
        cout << s2 << endl;
    }
    return 0;
}
#endif

// 分苹果

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }

        if (sum % n) {
            cout << "-1" << endl;
            break;
        }

        int tmp = sum / n, flag = 0;
        for (auto i : v) {
            if ((i - tmp) % 2) {
                cout << "-1" << endl;
                flag = 1;
                break;
            }
        }

        if (!flag) {
            int count = 0;
            for (auto i : v) {
                if (i > tmp) {
                    count += (i - tmp) / 2;
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}
#endif

#if 0
// 小易爱回文

#include <iostream>
#include <string>
using namespace std;

bool isHuiWen(string s) {
    int len = s.size();

    for (int i = 0; i < len; i++, len--) {
        if (s[i] != s[len - 1])
            return false;
    }
    return true;
}

int main() {
    string s1;
    while (cin >> s1) {
        if (isHuiWen(s1)) {
            cout << s1 << endl;
            break;
        }

        int len = s1.size(), flag = 1, T;
        for (T = 1; T < len; T++) {
            for (int i = T; i < len; i++, len--) {
                if (s1[i] != s1[len - 1]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                break;
            }
            flag = 1;
        }

        string s2 = s1;
        len = s1.size();
        s2.resize(len + T);
        for (int i = T - 1, j = 0; i >= 0; i--, j++) {
            s2[len + j] = s1[i];
        }
        cout << s2 << endl;
    }
    return 0;
}

#endif

#if 0
// 平分物品
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a < b; //升序排列
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }

        sort(v.begin(), v.end(), compare);
        int tmp = 0, sum1 = 0, sum2 = 0;

        for (int i = 0; i < n; i++) {
            tmp += v[i];
            for (int j = i + 1; j < n; j++) {
                if (sum1 + v[j] <= (sum - tmp) / 2) {
                    sum1 += v[j];
                }
                else {
                    sum2 += v[j];
                }
            }

            if (sum1 == sum2) {
                cout << tmp << endl;
                break;
            }
        }
    }

    return 0;
}
#endif


#if 0
#include <iostream>
#include <string>
using namespace std;

string Reserve(string s) {
    char tmp;
    for (int start = 0, end = s.size() - 1; start <= end; start++, end--) {
        tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
    }
    return s;
}

string sub_strings(string num1, string num2) {
    string s;
    num1 = Reserve(num1);
    num2 = Reserve(num2);
    int len1 = num1.size(), len2 = num2.size(), sub = len1 - len2;
    num2.resize(len1);
    for (int i = 0; i < sub; i++) {
        num2[len2 + i] = '0';
    }

    s.resize(len1);
    for (int i = 0; i < len1; i++) {
        if ((num1[i] - num2[i]) >= 0) {
            s[i] = num1[i] - num2[i] + '0';
        }
        else {
            s[i] = num1[i] - num2[i] + 10 + '0';
            s[i + 1] = s[i + 1] - 1;
        }
    }
    s = Reserve(s);

    int count = 0;
    for (int i = 0; i < len1; i++) {
        if (s[i] == '0')
            ++count;
        else {
            break;
        }
    }
    
    s.substr(count);
    return s;
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        cout << sub_strings(s1, s2) << endl;
    }
    return 0;
}
#endif