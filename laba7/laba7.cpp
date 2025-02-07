﻿#include <iostream>
#include <stdlib.h>
using namespace std;

class matr
{
protected:
	double** matrica;
	int size1;
	int size2;
public:
	matr(int n, int n1)
	{
		size1 = n;
		size2 = n1;
		matrica = new double* [size1];
		for (int i = 0; i < size1; i++)
			matrica[i] = new double[size2];
	}
	~matr()
	{
		for (int i = 0; i < size1; i++)
			delete[] matrica[i];
		delete[] matrica;
		size2 = 0;
		size1 = 0;
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
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
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
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
				cout << matrica[i][j] << "\t";
			cout << endl;
		}
	}
};

class Point : protected matr
{
	double x=0, y=0;
	double temperature;
public:
	Point(int n1,int n2, double K) :matr(n1,n2)
	{
		temperature = K;
		x = 0;
		y = 0;
	}
	~Point()
	{
		temperature = 0;
		x = 0;
		y = 0;
	}
	void input()
	{
		cout << "Input matrix" << endl;
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				cout << " elem " << "[" << i + 1 << "]" <<"["<<j+1<<"]" << "=" << endl;
				cin >> matrica[i][j];
				//matrica[i][j] = rand();
			}
		}
	}
	void print()
	{
		cout << endl;
		cout << "Matrix=" << endl;
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
				cout << matrica[i][j] << "\t";
			cout << endl;
		}
	}
	void solution()
	{
		for (int i=0;i<size1;i++)
				if ((temperature * 0.95) > matrica[i][2] || (temperature * 1.05) < matrica[i][2])
				{
					x = matrica[i][0];
					y = matrica[i][1];
					cout << "X:" << x << " " << "Y:" << y << endl;
				}
	}
};

int main()
{
	int n;
	int n1;
	cout << "Size" << endl;
	cin >> n;
	cin >> n1;
	if (n <= 0 || n1 <=0)
	{
		cout << "Error input" << endl;
		exit(0);
	}
	double temper;
	cout << "Temperature" << endl;
	cin >> temper;
	if (temper <= 0)
	{
		cout << "Error input" << endl;
		exit(0);
	}
	Point A(n,n1,temper);
	A.input();
	A.print();
	A.solution();
}