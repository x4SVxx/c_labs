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
		matrica = new double* [size];
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
	friend void solution(matr &X, int size, int s);
	friend int max(matr &X, int size);
	double* operator[](int);
};

double* matr::operator[] (int number)
{
	return matrica[number];
}


int max(matr &X, int size)
{
	double max = X[0][0];
	int num = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (max < X[i][j])
			{
				max = X[i][j];
				num = j;
			}
	return num;
}

void solution(matr &X, int size, int s)
{
	for (int i = 0; i < size; i++)
	{
		double temp = X[i][s];
		X[i][s] = X[i][size - 1];
		X[i][size - 1] = temp;

	}
}

void input(matr &X, int size)
{
	cout << "Input matrix" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << " elem " << i + 1 << "=" << endl;
			cin>>X[i][j];
		}
	}
}


void print(matr &X, int size)
{
	cout << endl;
	cout << "Matrix=" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << X[i][j] << "\t";
		cout << endl;
	}
}
int main()
{
	int n;
	cout << "Size" << endl;
	cin >> n;
	if (n <= 0)
	{
		cout << "Error input";
		exit(0);
	}
	matr A(n);
	input(A, n);
	print(A,n);
	int maximum = max(A, n);
	if (maximum!=n-1)
	solution(A, n, maximum);
	print(A,n);
}