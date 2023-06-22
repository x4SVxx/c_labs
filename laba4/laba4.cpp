#include <iostream>
#include <stdlib.h>
using namespace std;

class matr
{
private:

	double** matrica;
	int size;

public:

	matr(int n)
	{
		size = n;
		matrica  = new double* [size];
		for (int i = 0; i < size; i++)
		matrica[i] = new double[size];
	}
	~matr()
	{
		for (int i = 0; i < size; i++)
		delete[] matrica[i];
		delete[] matrica;
		size = 0;
	}

	double get(int i, int j)
	{
		return matrica[i][j];
	}

	void set(int i, int j, double num)
	{
		matrica[i][j] = num;
	}

	void input()
	{
		cout << "Input matrix" << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << " elem " << i + 1 << "=" << endl;
				//cin >> mas[i];
				matrica[i][j] = rand();
			}
		}
	}

	void print()
	{
		cout << endl;
		cout << "Matrix=" << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				cout << matrica[i][j] << "\t";
			cout << endl;
		}
	}

	int resh1(double num)
	{
		int kol = 0;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (matrica[i][j] > num)
				{
					kol += 1;
				}               
			}
		}
		return kol;
	}

	void resh2(int k, int s)
	{
		for (int i = 0; i < size; i++)
		{
			double temp = matrica[k][i];
			matrica[k][i] = matrica[i][s];
			matrica[i][s] = temp;
		}
	}

};

void main()
{
	cout << "Input size matrix" << endl;
	int M;
	cin >> M;

	if (M == 0 || M < 0)
	{
		cout << "Error input" << endl;
		exit(0);
	}

	matr matrix(M);
	matrix.input();
	matrix.print();

	double A;
	cout << "Input number" << endl;
	cin >> A;
	int test1 = matrix.resh1(A);
	cout << "The number of elements is greater than the number " << A << ":" << test1 << endl;

	cout << "Input the number of string" << endl;
	int k, s;
	cin >> k;

	if (k == 0 || k < 0 || k > M)
	{
		cout << "Error input" << endl;
		exit(0);
	}

	cout << "Input the number of column" << endl;
	cin >> s;

	if (s == 0 || s < 0 || s > M)
	{
		cout << "Error input" << endl;
		exit(0);
	}

	if (s != k)
	{
		cout << "Impossible values" << endl;
		exit(0);
	}

	k -= 1;
	s = s - 1;

	matrix.resh2(k, s);
	matrix.print();

	cout << endl;
	cout << "Main Solution" << endl;
	cout << endl;
	cout << "Input size matrix" << endl;
	int M1;
	cin >> M1;

	if (M1 == 0 || M1 < 0)
	{
		cout << "Error input" << endl;
		exit(0);
	}

	matr matrix1(M1);
	matrix1.input();
	matrix1.print();

	double A1;
	cout << "Input number" << endl;
	cin >> A1;

	int test2 = 0;
	for (int i = 0; i < M1 - 1; i++)
	{
		for (int j = i + 1; j < M1; j++)
		{
			if (matrix1.get(i,j) > A1)
			{
				test2 += 1;
			}
		}
	}

	cout << "The number of elements is greater than the number " << A1 << ":" << test2 << endl;

	cout << "Input the number of string" << endl;
	int k1, s1;
	cin >> k1;

	if (k1 == 0 || k1 < 0 || k1 > M1)
	{
		cout << "Error input" << endl;
		exit(0);
	}

	cout << "Input the number of column" << endl;
	cin >> s1;

	if (s1 == 0 || s1 < 0 || s1 > M1)
	{
		cout << "Error input" << endl;
		exit(0);
	}

	if (s1 != k1)
	{
		cout << "Impossible values" << endl;
		exit(0);
	}

	k1 = k1 - 1;
	s1 = s1 - 1;

	for (int i = 0; i < M1; i++)
	{
		double temp = matrix1.get(k1,i);
		matrix1.set(k1, i, matrix1.get(i, s1));
		matrix1.set(i, s1, temp);
	}

	matrix1.print();
}