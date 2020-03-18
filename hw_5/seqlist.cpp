#include "seqlist.h"

int main(){
	SeqList<int> sl;

	sl.push_back(1);
	sl.push_back(2);
	sl.push_back(3);
	sl.pop_back();
	SeqList<double> s1;
	s1.push_back(3.1415);
	s1.push_back(1.618);
	for (int i = 0; i < sl.size(); ++i)
	{
		cout << sl[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	return 0;
}
