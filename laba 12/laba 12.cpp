﻿#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
using namespace std;

struct worker
{
	string FIO;
	char gender;
	string position;
	int salary;
};

template<class T>
void create(list<T>& mas, int n)
{
	T test;
	for (int i = 0; i < n; i++)
	{
		cout << "ФИО" << endl;
		cin >> test.FIO;
		cout << "Пол" << endl;
		cin >> test.gender;
		cout << "Должность" << endl;
		cin >> test.position;
		cout << "Зарплата" << endl;
		cin >> test.salary;
		mas.push_back(test);
	}
}

template<class T>
void print(list<T>& mas)
{
	for (auto it = mas.begin(); it != mas.end(); it++)
		cout << (*it).FIO << " " << (*it).gender << " " << (*it).position << " " << (*it).salary << endl;
}

template<class T>
void men(list<T>& mas1, list<T>& mas2)
{
	const char *gender = "M";
	for (auto it = mas1.begin(); it != mas1.end(); it++)
		if ((*it).gender == *gender)
			mas2.push_back(*it);
}

template<class T>
void sortirovka(list<T>& mas)
{
	for (auto it = mas.begin(); it != mas.end(); it++)
	{
		auto smallestIt = it;
		it++;
		for (auto it2 = it; it2 != mas.end(); it2++)
			if ((*it2).salary < (*smallestIt).salary)
				smallestIt = it2;
		it--;
		iter_swap(it, smallestIt);
	}
}


template<class T>
void file(list<T>& mas, ifstream &ifile,int n)
{
	ifile.open("file.txt");
	T test;
	for (int i = 0; i < n; i++)
	{
		ifile >> test.FIO;
		ifile >> test.gender;
		ifile >> test.position;
		ifile >> test.salary;
		mas.push_back(test);
	}
	ifile.close();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Количество сотрудников" << endl;
	cin >> n;

	list<worker> mas;
	ifstream ifile;
	//create(mas, n);
	file(mas, ifile, n);
	cout << endl;
	print(mas);
	cout << endl;

	list<worker> masmen;
	men(mas, masmen);
	print(masmen);
	cout << endl;
    sortirovka(masmen);
	print(masmen);
}
