﻿#include <iostream>
#include <vector>
using namespace std;

template <class T>
void create(vector<T>& mas, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		T test;
		cin >> test;
		mas.push_back(test);
	}
	cout << endl;
}

template <class T>
void print(T mas)
{
	cout << endl;
	for (auto i = mas.begin(); i < mas.end(); i++)
		cout << *i << " ";
	cout << endl;
}

template <class T>
void swapsign(vector<T>& mas, int n)
{
	cout << endl;
	cout << "The sign changed after the elements" << endl;
	int qunt = 0;
	for (auto i = mas.begin(); i < mas.end()-1; i++)
	{
		if ((*i > 0 && *(i+1) < 0) || (*i < 0 && *(i+1) > 0))
		{
		qunt++;
		cout << *i <<endl;
		}
	}
	cout << endl;
	cout << "Number of times the sign changes "<<qunt;
	cout << endl;
}

int main()
{
	vector<double> vector;
	int n;
	cout << "Size" << endl;
	cin >> n;
	create(vector, n);
	print(vector);
	swapsign(vector, n);
}


