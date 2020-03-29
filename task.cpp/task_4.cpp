//����һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		// ����������ǵĿռ䣨ֻ�ǿ���������ռ䣩
		vector<vector<int>> data(numRows);

		// �������Ϊ0����ֱ�������
		if (numRows == 0)
		{
			return data;
		}
		int i, j;

		// ��������ǵĶ��˸�ֵΪ1
		data[0].push_back(1);

		// ����˼��:�ҳ�������ǵĹ��ɣ�����ÿһ��ͷβ����1���м��[j]����������һ��[j-1]+[j] 
		for (i = 1; i < numRows; i++)
		{
			//����������1
			data[i].push_back(1);
			for (j = 1; j < i; j++)
			{
				data[i].push_back(data[i - 1][j - 1] + data[i - 1][j]);
			}
			// ��ĩβ����1
			data[i].push_back(1);
		}

		return data;
	}
};

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		// ����������ǵĿռ䣨ֻ�ǿ���������ռ䣩
		vector<vector<int>> data(numRows);

		// �������Ϊ0����ֱ�������
		if (numRows == 0)
		{
			return data;
		}
		int i, j;

		// ��������ǵĶ��˸�ֵΪ1
		data[0].push_back(1);

		// ����˼��:�ҳ�������ǵĹ��ɣ�����ÿһ��ͷβ����1���м��[j]����������һ��[j-1]+[j] 
		for (i = 1; i < numRows; i++)
		{
			//����������1
			data[i].push_back(1);
			for (j = 1; j < i; j++)
			{
				data[i].push_back(data[i - 1][j - 1] + data[i - 1][j]);
			}
			// ��ĩβ����1
			data[i].push_back(1);
		}

		return data;
	}
};

