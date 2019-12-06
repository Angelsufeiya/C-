#if 0

#include<iostream>
#include<cmath>
using namespace std;
const int N = 20;
float a[N][N];
int m;

int main()
{
	int i, j;
	int c, k, n, p, r;
	float x[N], l[N][N], s, d;
	cout << "下面请输入未知数的个数m=";
	cin >> m;
	cout << endl;
	cout << "请按顺序输入增广矩阵a:" << endl;
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<m + 1; j++)
			cin >> a[i][j];
	}
	for (i = 0; i<m; i++)
	{
		for (j = i; j<m; j++)
			c = (fabs(a[j][i])>fabs(a[i][i])) ? j : i;        /*找列最大元素*/
		for (n = 0; n<m + 1; n++)
		{
			s = a[i][n]; a[i][n] = a[c][n]; a[c][n] = s;
		}    /*将列最大数放在对角线上*/
		for (p = 0; p<m + 1; p++)
			cout << a[i][p] << "\t";
		cout << endl;
		for (k = i + 1; k<m; k++)
		{
			l[k][i] = a[k][i] / a[i][i];
			for (r = i; r<m + 1; r++)                    /*化成三角阵*/
				a[k][r] = a[k][r] - l[k][i] * a[i][r];
		}
	}
	x[m - 1] = a[m - 1][m] / a[m - 1][m - 1];
	for (i = m - 2; i >= 0; i--)
	{
		d = 0;
		for (j = i + 1; j<m; j++)
			d = d + a[i][j] * x[j];
		x[i] = (a[i][m] - d) / a[i][i];            /*求解*/
	}
	cout << "该方程组的解为:" << endl;
	for (i = 0; i<m; i++)
		cout << "x[" << i << "]=" << x[i] << "\t";

	return 0;
}
#endif

#if 0
#include<iostream>
#include<cmath>
#define N 2      //非线性方程组中方程的个数、未知量的个数
#define Epsilon 0.0001   //差向量的上限
#define Max 100   //最大迭代次数
using namespace std;
const int N2 = 2 * N;
int main()
{
	void ff(float xx[N], float yy[N]); //计算向量函数的因变量向量yy[N]
	void ffyakebi(float xx[N], float yy[N][N]);//计算雅可比矩阵yy[N][N]
	void inv_yakebi(float yy[N][N], float inv[N][N]);//计算雅可比矩阵的逆矩阵inv
	void newton(float x0[N], float inv[N][N], float y0[N], float x1[N]);//由近似解向量x0求近似解向量x1 
	float x0[N] = { 2.0, 0.25 }, y0[N], yakebi[N][N], invyakebi[N][N], x1[N], errornorm;
	int i, iter = 0;
	cout << "初始近似解向量:" << endl;
	for (i = 0; i<N; i++)
		cin >> x0[i];
	for (i = 0; i<N; i++)
		cout << x0[i] << " ";
	cout << endl;
	cout << endl;
	do
	{
		iter = iter + 1;
		cout << "第" << iter << "次迭代开始" << endl;
		ff(x0, y0);
		ffyakebi(x0, yakebi);
		inv_yakebi(yakebi, invyakebi);
		newton(x0, invyakebi, y0, x1);
		errornorm = 0;
		for (i = 0; i<N; i++)
			errornorm = errornorm + fabs(x1[i]);
		if (errornorm<Epsilon) break;
		for (i = 0; i<N; i++)
			x0[i] = x1[i];
	} while (iter<Max);
	return 0;
}
void ff(float xx[N], float yy[N])
{
	float x, y;
	int i;
	x = xx[0];
	y = yy[1];
	yy[0] = x*x - 2 * x - y + 0.5;
	yy[1] = x*x + 4 * y*y - 4;
	cout << "向量函数的因变量向量是:" << endl;
	for (i = 0; i<N; i++)
		cout << yy[i] << " ";
	cout << endl;
	cout << endl;
}
void ffyakebi(float xx[N], float yy[N][N])
{
	float x, y;
	int i, j;
	x = xx[0];
	y = xx[1];
	yy[0][0] = 2 * x - 2;
	yy[0][1] = -1;
	yy[1][0] = 2 * x;
	yy[1][1] = 8 * y;
	cout << "雅可比矩阵是:" << endl;
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
			cout << yy[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
void inv_yakebi(float yy[N][N], float inv[N][N])
{
	float aug[N][N2], L;
	int i, j, k;
	cout << "开始计算雅可比矩阵的逆矩阵:" << endl;
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
			aug[i][j] = yy[i][j];
		for (j = N; j<N2; j++)
		if (j == i + N)
			aug[i][j] = 1;
		else
			aug[i][j] = 0;
	}
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N2; j++)
			cout << aug[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (i = 0; i<N; i++)
	{
		for (k = i + 1; k<N; k++)
		{
			L = -aug[k][i] / aug[i][i];
			for (j = 1; j<N2; j++)
				aug[k][j] = aug[k][j] + L*aug[i][j];
		}
	}
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N2; j++)
			cout << aug[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (i = N - 1; i>0; i--)
	{
		for (k = i - 1; k >= 0; k--)
		{
			L = -aug[k][i] / aug[i][i];
			for (j = N2 - 1; j >= 0; j--)
				aug[k][j] = aug[k][j] + L*aug[i][j];
		}
	}
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N2; j++)
			cout << aug[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (i = N - 1; i >= 0; i--)
	for (j = N2 - 1; j >= 0; j--)
		aug[i][j] = aug[i][j] / aug[i][i];
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N2; j++)
			cout << aug[i][j] << " ";
		cout << endl;
		for (j = N; j<N2; j++)
			inv[i][j - N] = aug[i][j];
	}
	cout << endl;
	cout << "雅可比矩阵的逆矩阵是:" << endl;
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
			cout << inv[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
void newton(float x0[N], float inv[N][N], float y0[N], float x1[N])
{
	int i, j;
	float sum = 0;
	for (i = 0; i<N; i++)
	{
		sum = 0;
		for (j = 0; j<N; j++)
			sum = sum + inv[i][j] * y0[j];
		x1[i] = x0[i] - sum;
	}
	cout << "近似解向量:" << endl;
	for (i = 0; i<N; i++)
		cout << x1[i] << " ";
	cout << endl;
	cout << endl;
}

#endif

#if 1
#include<iostream>
#include<cmath>
#include<iomanip>
#define MAX 20
#define eps 0.00001
using namespace std;
double f(double x)
{
	return 1 + x - x*x / 4;
}
int main()
{
	double P[MAX] = { 0 }, err = 0.0, relerr = 0.0, tol = 0.0, p = 0.0, p0 = 0.0;
	int k = 0, max1 = 0, i = 0;
	cout << "不动点法解非线性方程f(x)=1+x-x*x/4" << endl;
	cout << "方程在[-2,2]上有解，初始值为p0=0" << endl;
	P[0] = p0 = 0;	//初始化
	max1 = 100;
	tol = 0.001;
	for (k = 2; k <= max1; k++)
	{
		P[k - 1] = f(P[k - 2]);
		err = fabs(P[k - 1] - P[k - 2]);
		relerr = err / (fabs(P[k - 1] + eps));
		p = P[k - 1];
		if ((err<tol) || (relerr<tol))
			break;
	}
	if (k == max1)
		cout << "迭代次数超过允许的最大迭代次数！" << endl;
	cout << "不动点的近似值为:" << p << endl;
	cout << "程序迭代次数为:" << k << endl;
	cout << "近似值的误差为:" << err << endl;
	cout << "求解不动点近似值的序列:" << endl;
	for (i = 0; i<k; i++)
	{
		cout << setw(10) << P[i];
	}
	cout << endl;
	return 0;
}
#endif