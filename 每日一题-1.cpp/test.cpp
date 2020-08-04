
//题目描述：
//给出你n条长度不一的边，请你从中选择四条边，组成一个最大的平行四边形。
//
//请你输出最大的平行四边形的面积。



//输入描述
//输入第一行包含一个正整数n，表示边的数量。(4 <= n <= 50000)
//
//输入第二行包含n个正整数，表示n条边的长度，边的长度不会超过10 ^ 9。
//
//输出描述
//输出仅包含一个正整数，即最大的平行四边形的面积，无解则输出 - 1。

//#include <iostream>
//#include <vector>
//using namespace std;

//void getMaxArea(vector<int> v) {
//	int len = 0, wid = 0, flag = 0;
//	
//	for (int i = v.size() - 1; i > 0; i--) {
//		if (flag && v[i] == v[i - 1]) {
//			wid = v[i];
//			break;
//		}
//		if (v[i] == v[i - 1] && flag == 0) {
//			len = v[i];
//			flag = 1;
//		}
//	}
//	cout << wid * len;
//}
//
//void quicksort(vector<int> a, int left, int right) {
//	int i, j, t, temp;
//	if (left > right)
//		return;
//	temp = a[left]; //temp中存的就是基准数
//	i = left;
//	j = right;
//
//	while (i != j) { //顺序很重要，要先从右边开始找
//		while (a[j] >= temp && i < j)//符合条件，往左继续找
//			j--;
//		while (a[i] <= temp && i < j)//符合条件，往右继续找
//			i++;
//		if (i < j)//交换两个数在数组中的位置
//		{
//			t = a[i];
//			a[i] = a[j];
//			a[j] = t;
//		}
//	}
//	//最终将基准数归位
//	a[left] = a[i];
//	a[i] = temp;
//	quicksort(a, left, i - 1);//继续处理左边的，这里是一个递归的过程
//	quicksort(a, i + 1, right);//继续处理右边的 ，这里是一个递归的过程
//}

//题目描述：
//有一种排序算法定义如下，该排序算法每次只能把一个元素提到序列的开头，例如2，1，3，4，只需要一次操作把1提到序列起始位置就可以使得原序列从小到大有序。
//
//现在给你个乱序的1 - n的排列，请你计算最少需要多少次操作才可以使得原序列从小到大有序。



/*输入描述
输入第一行包含一个正整数n ，表示序列的长度。(1 <= n <= 100000)

接下来一行有n个正整数，表示序列中的n个元素，中间用空格隔开。(1 <= a_i <= n)

输出描述
输出仅包含一个整数，表示最少的操作次数。*/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void getCount(vector<int> v) {
//	int count = 0;
//	while (1) {
//		int flag = 1;
//		for (int i = 0; i < v.size() - 1; i++) {
//			if (v[i] > v[i + 1]) {
//				int tmp = v[0];
//				v[0] = v[i + 1];
//				v[i + 1] = tmp;
//				count++;
//				flag = 0;
//				break;
//			}
//		}
//		if (flag)
//			break;
//	}
//	cout << count;
//}
//
//int main() {
//	int n;
//	while (cin >> n) {
//		vector<int> v;
//		v.resize(n);
//		int num;
//		for (int i = 0; i < n; i++) {
//			cin >> num;
//			v[i] = num;
//		}
//		getCount(v);
//	}
//
//	return 0;
//}

//题目描述：
//在一个2D横版游戏中，所有的怪物都是在X轴上的，每个怪物有两个属性X和HP，分别代表怪物的位置和生命值。
//
//玩家控制的角色有一个AOE（范围攻击）技能，玩家每次释放技能可以选择一个位置x，技能会对[x - y, x + y]范围内的所有怪物造成1点伤害，请问，玩家最少需要使用多少次技能，才能杀死所有怪物，怪物血量清0即视为被杀死。
//
//输入描述
//输入第一行包含一个两个正整数n和y，分别表示怪物的数量和技能的范围。（1 <= n <= 100000）
//
//接下来有n行，每行有两个正整数x和hp分别表示一只怪物的位置和血量。(1 <= x, hp <= 10 ^ 9)
//
//输出描述
//输出仅包含一个整数，表示最少使用的技能次数。
//
//
//样例输入
//3 5
//1 10
//10 5
//22 3
//样例输出
//13