﻿#include <iostream>
using namespace std;

class complex
{
	double real, image;
public:
	complex() { real = 0; image = 0; }
	complex(double re, double im) {
		real = re; image = im;
	}

	bool operator>(complex& c)
	{
		if (real > c.real&& image > c.image)
			return true;
		else return false;
	}
	bool operator<(complex& c)
	{
		if (real < c.real&& image < c.image)
			return true;
		else return false;
	}
	bool operator==(complex& c)
	{
		if (real == c.real&& image == c.image)
			return true;
		else return false;
	}
	complex operator=(complex& c)
	{
		real = c.real;
		image = c.image;
		return *this;
	}

	friend ostream& operator<<(ostream& out, complex& a);
	friend istream& operator>>(istream& in, complex& a);
};
ostream& operator<<(ostream& out, complex& a)
{
	out << a.real << "+" << "(" << a.image << ")" << "i";
	return out;
}

istream& operator>>(istream& in, complex& a)
{
	in >> a.real;
	in >> a.image;
	return in;
}

template <class T>
bool wheremin(T* array, int size)
{
	T min = array[0];
	int flag = 0;
	int flag1 = 0;
	int flag2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (min > array[i])
		{
			min = array[i];
			flag1 = i;
		}
	}

	for (int i = flag1 + 1; i < size; i++)
	{
		if (min == array[i])
		{
			flag2 = i;

		}
	}

	if (flag2 != 0)
	{
		cout << "Min elem in 1 and 2 (or center) part" << endl;
		return 0;
	}
	else
		return 1;
}

template <class T>
int minimum(T* array, int size)
{
	T min = array[0];
	int flag = 0;
	for (int i = 0; i < size; i++)
	{
		if (min > array[i])
		{
			min = array[i];
			flag = i;
		}
	}
	return flag;
}

template <class T>
void solution1CHET(T* array, int size)
{
	for (int j = size / 2; j < size; j++)
	{
		int num = j;
		for (int l = j + 1; l < size; l++)
		{
			if (array[num] > array[l])
			{
				num = l;
			}
		}
		T temp = array[j];
		array[j] = array[num];
		array[num] = temp;
	}
}

template <class T>
void solution2CHET(T* array, int size)
{
	int i = 0;
	int j = (size / 2) - 1;
	while (i < j)
	{
		T klon = array[i];
		array[i] = array[j];
		array[j] = klon;
		i = i + 1;
		j = j - 1;
	}
}

template <class T>
void solution1NECHET(T* array, int size)
{
	double kol = (double)size / 2;
	kol = kol - 0.5;
	for (int j = kol + 1; j < size; j++)
	{
		int num = j;
		for (int l = j + 1; l < size; l++)
		{
			if (array[num] > array[l])
			{
				num = l;
			}
		}
		T temp = array[j];
		array[j] = array[num];
		array[num] = temp;
	}
}

template <class T>
void solution2NECHET(T* array, int size)
{
	double kol = (double)size / 2;
	kol = kol - 0.5;
	int i = 0;
	int j = kol - 1;
	while (i < j)
	{
		T klon = array[i];
		array[i] = array[j];
		array[j] = klon;
		i = i + 1;
		j = j - 1;
	}
}

template <class T>
void print(T* array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}


int main()
{
	int N;
	cout << "Input size" << endl;
	cin >> N;

	cout << "int" << endl;

	int* mas1 = new int[N];
	double* mas2 = new double[N];
	char* mas3 = new char[N];

	for (int i = 0; i < N; i++)
	{
		cout << "Elem " << i + 1 << endl;
		cin >> mas1[i];
	}

	print(mas1, N);
	
	if (N % 2 == 0)
	{
		bool where = wheremin(mas1, N);
		if (where)
		{
			int min = minimum(mas1, N);
			if (min > ((N / 2) - 1))
				solution1CHET(mas1, N);
			else
				solution2CHET(mas1, N);
		}
	}
	else
	{
		bool where = wheremin(mas1, N);
		if (where)
		{
			int min = minimum(mas1, N);
			double kol = (double)N / 2;
			kol = kol - 0.5;
			if (min > kol)
				solution1NECHET(mas1, N);
			else if (min < kol)
				solution2NECHET(mas1, N);
			else if (kol == min)
				cout << "Min elem in center" << endl;
		}
	}

	print(mas1, N);

	for (int i = 0; i < N; i++)
	{
		cout << "Elem " << i + 1 << endl;
		cin >> mas2[i];
	}

	print(mas2, N);
	if (N % 2 == 0)
	{
		bool where = wheremin(mas2, N);
		if (where)
		{
			int min = minimum(mas2, N);
			if (min > ((N / 2) - 1))
				solution1CHET(mas2, N);
			else
				solution2CHET(mas2, N);
		}
	}
	else
	{
		bool where = wheremin(mas2, N);
		if (where)
		{
			int min = minimum(mas2, N);
			double kol = (double)N / 2;
			kol = kol - 0.5;
			if (min > kol)
				solution1NECHET(mas2, N);
			else if (min < kol)
				solution2NECHET(mas2, N);
			else if (kol == min)
				cout << "Min elem in center" << endl;
		}
	}

	print(mas2, N);

	for (int i = 0; i < N; i++)
	{
		cout << "Elem " << i + 1 << endl;
		cin >> mas3[i];
	}

	print(mas3, N);
	if (N % 2 == 0)
	{
		bool where = wheremin(mas3, N);
		if (where)
		{
			int min = minimum(mas3, N);
			if (min > ((N / 2) - 1))
				solution1CHET(mas3, N);
			else
				solution2CHET(mas3, N);
		}
	}
	else
	{
		bool where = wheremin(mas3, N);
		if (where)
		{
			int min = minimum(mas3, N);
			double kol = (double)N / 2;
			kol = kol - 0.5;
			if (min > kol)
				solution1NECHET(mas3, N);
			else if (min < kol)
				solution2NECHET(mas3, N);
			else if (kol == min)
				cout << "Min elem in center" << endl;
		}
	}
	print(mas3, N);

	complex* mas4 = new complex[N];
	complex test;
	double x, y;
	for (int i = 0; i < N; i++)
	{
		cout << "Input elem " << i + 1 << " of the array 1" << endl;
		cout << "Vvedite real" << endl;
	    cin >> x;
		cout << "Vvedite image" << endl;
		cin >> y;
		complex test(x, y);
		mas4[i] = test;
		cout << endl;
	}
	print(mas4, N);

	if (N % 2 == 0)
	{
		bool where = wheremin(mas4, N);
		if (where)
		{
			int min = minimum(mas4, N);
			if (min > ((N / 2) - 1))
				solution1CHET(mas4, N);
			else
				solution2CHET(mas4, N);
		}
	}
	else
	{
		bool where = wheremin(mas4, N);
		if (where)
		{
			int min = minimum(mas4, N);
			double kol = (double)N / 2;
			kol = kol - 0.5;
			if (min > kol)
				solution1NECHET(mas4, N);
			else if (min < kol)
				solution2NECHET(mas4, N);
			else if (kol == min)
				cout << "Min elem in center" << endl;
		}
	}
	print(mas4, N);
	
}